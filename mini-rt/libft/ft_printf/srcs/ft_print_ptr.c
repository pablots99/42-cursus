/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:56:01 by pablo             #+#    #+#             */
/*   Updated: 2020/11/30 21:36:15 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ptr_num(t_flags flgs, int len, char *sufix)
{
	if (flgs.left_just)
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(sufix, 1);
	}
	if (flgs.num >= len)
	{
		ft_put_spaces(flgs.num - len, 0);
		return (flgs.num - len);
	}
	return (0);
}

int		print_ptr(void *ptr, t_flags flgs)
{
	long	x;
	char	*sufix;
	int		len;

	x = (unsigned long)ptr;
	if (ptr != NULL)
		sufix = ft_print_base_itoa((long int)x, 16, 0);
	else
		sufix = ((flgs.dot == -1) ? NULL : "0");
	len = 2 + ft_strlen(sufix);
	if (flgs.num)
		len += ptr_num(flgs, len, sufix);
	if (!flgs.left_just || (!flgs.num && flgs.left_just))
		ft_putstr_fd("0x", 1);
	if (!flgs.left_just || (!flgs.num && flgs.left_just))
		ft_putstr_fd(sufix, 1);
	if (ptr != NULL)
		free(sufix);
	return (len);
}
