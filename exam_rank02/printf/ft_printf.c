/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 21:52:50 by pablo             #+#    #+#             */
/*   Updated: 2020/12/14 19:06:11 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>


int ft_strlen(char* str)
{
	int i;

	i = 0;

	while(str[i])
		i++;
	return (i);
}

int ft_putchar(char a)
{	
	write(1,&a,1);
	return 1; 
}

int ft_strchr(char *str, char a)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(str[i] == a)
			return 1;
		i++;
	}
	return 0;
}
int pritnstr(char *str,int  precision)
{
	int len;

	len = ft_strlen(str);
	if(precision == 0)
		len = 0;
	if(precision > 0 && precision <= len)
		len -= precision + 1;
	write(1,str,len);
	return len ;
}
void putnbr(int num, int *len)
{
	if(num >= 10)
		putnbr(num / 10, len);
	*len = *len + ft_putchar(num % 10 + '0');
}
int printint(int  num,int  precision)
{
	int len;

	len = 0;
	if(num < 0 )
	{
		len++;
		write(1,"-",1);
		num *= -1;
	}
	putnbr(num, &len);
	return len ;
}
int printflgs(va_list args, char c, int precision)
{
	int len;

	len = 0;
	if(c == 's')
		len += pritnstr(va_arg(args,char*),precision);
	else if(c == 'd')
		len += printint(va_arg(args,int));
	return len;
}
int ft_printf(const char *input, ... )
{
	va_list	args;
	int len;
	int i;
	int precision;

	precision = -1;
	len = 0;
	i = 0;
	va_start(args, input);
	while (input[i])
	{		
		if (input[i] == '%' && input[i + 1])
		{
			i++;
			if(input[i] == '.')
			{
				i++;
				precision = 0;
				while (ft_strchr("0123456789", input[i]))
				{		
					precision = precision * 10 + (input[i] - '0');
					i++;
				}
			}
			if(ft_strchr("sdx", input[i]))
				len += printflgs(args, input[i],precision);
			else
				break ;
		}
		else
			len +=  ft_putchar(input[i]);
		i++;
	}
	va_end(args);
	return(len);

}


int main()
{
	int len;
	int len2;

	len = ft_printf("aaaa. %.2d.\n",-5);
	printf("----------\n");
	len2 = printf("aaaa. %.2d.\n",-5);
	printf("-----------\n");
	printf("ft_pf: %d \npf_ %d",len,len2);

}
