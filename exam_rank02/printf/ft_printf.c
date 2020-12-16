/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 21:52:50 by pablo             #+#    #+#             */
/*   Updated: 2020/12/16 10:44:45 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;

	while (str[i])
		i++;
	return (i);
}

int ft_putchar(char a)
{
	write(1, &a, 1);
	return 1;
}

int ft_strchr(char *str, char a)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			return 1;
		i++;
	}
	return 0;
}
int pritnstr(char *str, int precision)
{
	int len;

	len = ft_strlen(str);
	if (precision == 0)
		len = 0;
	if (precision > 0 && precision <= len)
		len -= precision + 1;
	write(1, str, len);
	return len;
}

void len_basenbr(long long int num,char *base,int *len)
{
	int b;

	b = ft_strlen(base);
	if (num >= b)
		len_basenbr(num / b,base, len);
	*len = *len + 1;
}
void put_basenbr(long long int num,char *base)
{
	int b;

	b = ft_strlen(base);
	if (num >= b)
		put_basenbr(num / b,base);
	ft_putchar(base[num % b]);
}
int print_gaps(int len, int zero){
	while (len > 0)
	{
		ft_putchar((zero)?'0':' ');
		len--;
	}	
	return (len);
}
int printint(int num, int precision, int width)
{
	int len;

	len = 0;
	len_basenbr(num,"0123456789", &len);
	if (num < 0)
	{
		len++;
		write(1, "-", 1);
		num *= -1;
	}
	put_basenbr(num,"0123456789");
	return len;
}

int print_exa(unsigned int num, int precision, int width)
{
	int len;
	int final_len;

	len = 0;
	len_basenbr(num,"0123456789abcdef", &len);
	//printf("pre:%d,width:%d,len:%d\n",precision,width,len);
	if(width > precision && width > len)
	{
		if( precision > len)
			final_len += print_gaps(precision - width,0);
		else
			final_len += print_gaps(width - len,0);
	}
	if(precision > len)
			final_len += print_gaps(precision - len,1);
	put_basenbr(num,"0123456789abcdef");
	return (len + final_len);
}
int printflgs(va_list args, char c, int precision, int width)
{
	int len;

	len = 0;
	if (c == 's')
		len += pritnstr(va_arg(args, char *), precision);
	else if (c == 'd')
		len += printint(va_arg(args, int), precision, width);
	else if (c == 'x')
		len += print_exa(va_arg(args,unsigned int), precision, width);
	return len;
}
void load_flags(int *width, int *precision, int *i, const char *input)
{
	while (ft_strchr("0123456789", input[*i]))
	{
		*width = *width * 10 + (input[*i] - '0');
		*i = *i + 1;
	}
	if (input[*i] == '.')
	{
		*i = *i + 1;
		*precision = 0;
		while (ft_strchr("0123456789", input[*i]))
		{
			*precision = *precision * 10 + (input[*i] - '0');
			*i = *i + 1;
		}
	}
}
int ft_printf(const char *input, ...)
{
	va_list args;
	int len;
	int i;
	int precision;
	int width;

	precision = -1;
	len = 0;
	i = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
		{
			i++;
			load_flags(&width, &precision, &i, input);
			if (ft_strchr("sdx", input[i]))
				len += printflgs(args, input[i], precision, width);
			else
				break;
		}
		else
			len += ft_putchar(input[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int main()
{
	int len;
	int len2;

	len = ft_printf("aaaa. %10.9x\n", 242452452);
	printf("----------\n");
	len2 =   printf("aaaa. %10.9x\n", 242452452);
	printf("-----------\n");
	printf("ft_pf: %d \npf_ %d", len, len2);
}
