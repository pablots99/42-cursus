/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:30:41 by pablo             #+#    #+#             */
/*   Updated: 2020/11/30 20:50:07 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		uns_num(t_flags flgs, int len_num, unsigned int *n, int zero_cond)
{
	int len;

	len = 0;
	if (flgs.zero && (flgs.dot == -1 || flgs.nulldot == 1))
		len += ft_put_spaces(flgs.num - len_num,
			(flgs.zero && (flgs.dot > 0)) ? 1 : 0);
	if (flgs.left_just && !zero_cond)
		ft_putnbr_unsigned_fd(*n, 1);
	if (flgs.num > len_num && !(flgs.zero &&
		(flgs.dot == -1 || flgs.nulldot == 1)))
		len += ft_put_spaces(flgs.num - len_num,
			(flgs.zero && flgs.dot != -1) ? 1 : 0);
	return ((len < 0) ? 0 : len);
}

int		uns_dot(t_flags flgs, int len_num, unsigned int *n, int zero_cond)
{
	int len;

	len = 0;
	if (flgs.dot > len_num && flgs.left_just)
		len += ft_put_spaces(flgs.dot - len_num, 1);
	if (flgs.left_just && !zero_cond)
		ft_putnbr_unsigned_fd(*n, 1);
	if (flgs.dot > len_num && !flgs.left_just)
		len += ft_put_spaces(flgs.dot - len_num, 1);
	return (len);
}

int		uns_dot_and_num(t_flags flgs, int len_num,
					unsigned int *n, int zero_cond)
{
	int len;
	int dot_aux;

	dot_aux = (((flgs.dot > len_num) ? flgs.dot : len_num) + (*n < 0 ? 1 : 0));
	len = 0;
	if (flgs.num > dot_aux && !flgs.left_just)
		len += ft_put_spaces(flgs.num - dot_aux, 0);
	if (flgs.dot > len_num)
		len += ft_put_spaces(flgs.dot - len_num, 1);
	if (flgs.left_just && !zero_cond)
		ft_putnbr_unsigned_fd(*n, 1);
	if (flgs.num > dot_aux && flgs.left_just)
		len += ft_put_spaces(flgs.num - (dot_aux), 0);
	return (len);
}

int		print_unsiged_int(unsigned int n, t_flags flgs)
{
	int len;
	int len2;
	int zero_cond;

	zero_cond = ((n == 0 && flgs.dot == -1)) ? 1 : 0;
	zero_cond = ((n == 0 && flgs.nulldot == 1)) ? 2 : zero_cond;
	len2 = num_len(n) - ((zero_cond) ? 1 : 0);
	len = num_len(n) - (zero_cond ? 1 : 0);
	if (flgs.dot > 0 && flgs.num > 0)
		len += uns_dot_and_num(flgs, len2, &n, zero_cond);
	else if (flgs.num > 0)
		len += uns_num(flgs, len2, &n, zero_cond);
	else if (flgs.dot > 0)
		len += uns_dot(flgs, len2, &n, zero_cond);
	if (!flgs.left_just || (flgs.dot <= 0 && flgs.num <= 0))
	{
		if (!zero_cond)
			ft_putnbr_unsigned_fd(n, 1);
	}
	return (len);
}
