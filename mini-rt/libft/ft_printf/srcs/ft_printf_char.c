/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:30:10 by pablo             #+#    #+#             */
/*   Updated: 2020/11/30 20:42:44 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(int c, t_flags flgs)
{
	int len;

	len = 0;
	if (flgs.num != 0)
	{
		if (flgs.left_just == 1)
		{
			ft_putchar_fd(c, 1);
			ft_put_spaces(flgs.num - 1,
				(c == '%' && flgs.zero && !flgs.left_just) ? 1 : 0);
		}
		else
		{
			ft_put_spaces(flgs.num - 1,
				(c == '%' && flgs.zero && !flgs.left_just) ? 1 : 0);
			ft_putchar_fd(c, 1);
		}
	}
	else
		ft_putchar_fd(c, 1);
	return ((flgs.num) ? flgs.num : 1);
}
