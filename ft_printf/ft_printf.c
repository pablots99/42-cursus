/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:07:51 by pablo             #+#    #+#             */
/*   Updated: 2020/11/30 21:32:52 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <stdio.h>

t_flags	init_flags(void)
{
	t_flags flgs;

	flgs.dot = 0;
	flgs.left_just = 0;
	flgs.num = 0;
	flgs.star = 0;
	flgs.zero = 0;
	flgs.nulldot = 0;
	flgs.zero_cond = 0;
	return (flgs);
}

int		print_arg(va_list arg, char conv, t_flags flgs)
{
	int n;

	n = 0;
	if (conv == 'c')
		n = print_char(va_arg(arg, int), flgs);
	else if (conv == 'd' || conv == 'i')
		n = print_int(va_arg(arg, int), flgs);
	else if (conv == 's')
		n = print_string(va_arg(arg, char *), flgs);
	else if (conv == 'x')
		n = print_hex(va_arg(arg, unsigned int), 0, flgs);
	else if (conv == 'X')
		n = print_hex(va_arg(arg, unsigned int), 1, flgs);
	else if (conv == 'p')
		n = print_ptr(va_arg(arg, void *), flgs);
	else if (conv == 'u')
		n = print_unsiged_int(va_arg(arg, unsigned int), flgs);
	else if (conv == '%')
		n = print_char('%', flgs);
	else
		return (0);
	return (n);
}

void	loadflags(const char *input, int *i, t_flags *flgs, va_list arg)
{
	while (input[*i] && ft_strchr("-0123456789.*", input[*i]))
	{
		if (input[*i] == '0' && flgs->num == 0
			&& !flgs->left_just && flgs->dot == 0)
			flgs->zero = 1;
		else if (ft_isdigit(input[*i]))
			load_width((char *)&input[*i], flgs);
		else if (input[*i] == '.')
			flgs->dot = -1;
		else if (input[*i] == '-')
			flgs->left_just = 1;
		else if (input[*i] == '*')
			load_ast(flgs, va_arg(arg, int));
		*i += 1;
	}
}

int		input_loop(va_list args, const char *input, t_flags *flgs)
{
	int final_len;
	int i;

	i = 0;
	final_len = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
		{
			*flgs = init_flags();
			i++;
			if (ft_strchr("-0123456789.*", input[i]))
				loadflags(input, &i, flgs, args);
			if (input[i] && ft_strchr("cspdiuxX%", input[i]))
				final_len += print_arg(args, input[i], *flgs);
			else
				break ;
		}
		else
			final_len += input_loop_aux(input[i]);
		i++;
	}
	return (final_len);
}

int		ft_printf(const char *input, ...)
{
	va_list	args;
	t_flags	flgs;
	int		len;

	len = 0;
	va_start(args, input);
	len = input_loop(args, input, &flgs);
	va_end(args);
	return (len);
}
