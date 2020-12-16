/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 21:52:50 by pablo             #+#    #+#             */
/*   Updated: 2020/12/16 22:02:37 by ptorres          ###   ########.fr       */
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
int print_gaps(int len, int zero)
{

	int i;

	i = 0;
	while (len > 0)
	{
		ft_putchar((zero) ? '0' : ' ');
		len--;
		i++;
	}

	return (i);
}
int pritnstr(char *str, int precision, int width)
{
	int len;
	int f;

	f = 0;
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (precision == 0)
		len = 0;
	if (precision > 0 && precision < len)
		len = precision;
	if (width > len)
		f += print_gaps(width - len, 0);
	write(1, str, len);
	return len + f;
}

void len_basenbr(long long int num, char *base, int *len)
{
	int b;

	b = ft_strlen(base);
	if (num >= b)
		len_basenbr(num / b, base, len);
	*len = *len + 1;
}
void put_basenbr(long long int num, char *base)
{
	int b;

	b = ft_strlen(base);
	if (num >= b)
		put_basenbr(num / b, base);
	ft_putchar(base[num % b]);
}

int printint(long int num, int precision, int width)
{
	int len;
	int final_len;
	int aux;

	aux = 0;
	len = 0;
	final_len = 0;
	if (num == 0 && precision == 0)
		len = -1;
	if (num < 0)
	{
		aux = 1;
		num *= -1;
		width--;
	}
	len_basenbr(num, "0123456789", &len);
	if (width > precision && width > len)
	{
		if (precision > len)
			final_len += print_gaps(width - precision, 0);
		else
			final_len += print_gaps(width - len, 0);
	}
	if (aux == 1)
	{
		final_len++;
		write(1, "-", 1);
		;
	}
	if (precision > len)
		final_len += print_gaps(precision - len, 1);
	if (!(num == 0 && precision == 0))
		put_basenbr(num, "0123456789");
	return (len + final_len);
}

int print_exa(unsigned int num, int precision, int width)
{
	int len;
	int final_len;

	len = 0;
	final_len = 0;
	len_basenbr(num, "0123456789abcdef", &len);
	if (num == 0 && precision == 0)
		len = -1;
	if (num == 0 && precision == 0)
		len = 0;
	if (width > precision && width > len)
	{
		if (precision > len)
			final_len += print_gaps(width - precision, 0);
		else
			final_len += print_gaps(width - len, 0);
	}
	if (precision > len)
		final_len += print_gaps(precision - len, 1);
	if (!(num == 0 && precision == 0))
		put_basenbr(num, "0123456789abcdef");
	return (len + final_len);
}
int printflgs(va_list args, char c, int precision, int width)
{
	int len;

	len = 0;
	if (c == 's')
		len += pritnstr(va_arg(args, char *), precision, width);
	else if (c == 'd')
		len += printint(va_arg(args, int), precision, width);
	else if (c == 'x')
		len += print_exa(va_arg(args, unsigned int), precision, width);
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

	width = 0;
	va_start(args, input);
	while (input[i])
	{
		width = 0;
		precision = -1;
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

// int main()
// {
// 	int len;

// 	int len1;
// 	len = 0, len1 = 0;

// 	len = ft_printf("60:d4w0p %4.0d.\n", 0);
// 	len1 = printf("60:d4w0p %4.0d.\n", 0);
// 	printf("len:%d, len1:%d",len , len1);

// }