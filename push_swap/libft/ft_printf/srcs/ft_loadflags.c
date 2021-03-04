/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:49:19 by pablo             #+#    #+#             */
/*   Updated: 2020/11/30 20:36:17 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		load_width(char *input, t_flags *flgs)
{
	if (flgs->dot == 0 && flgs->nulldot == 0)
		flgs->num = flgs->num * 10 + (*input - '0');
	else
	{
		if (flgs->dot == -1)
		{
			flgs->dot = 0;
			if (*input == '0')
				flgs->nulldot = 1;
		}
		flgs->dot = flgs->dot * 10 + (*input - '0');
	}
	return (0);
}

void	load_ast(t_flags *flgs, int arg)
{
	if (flgs->dot == -1)
	{
		if (arg == -1)
			arg--;
		if (arg == 0)
			flgs->nulldot = 1;
		flgs->dot = arg;
	}
	else if (flgs->num == 0)
	{
		if (arg < 0)
		{
			flgs->zero = 0;
			flgs->left_just = 1;
			arg *= -1;
		}
		flgs->num = arg;
	}
}
