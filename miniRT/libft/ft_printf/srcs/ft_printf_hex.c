/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:34:39 by pablo             #+#    #+#             */
/*   Updated: 2020/11/30 20:47:36 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_hex_dot(t_flags flgs, char *str, int len_num, int zero_cond)
{
	int len;

	len = 0;
	if (flgs.dot > len_num && flgs.left_just)
		len += ft_put_spaces(flgs.dot - len_num, 1);
	if (flgs.left_just && !zero_cond)
		ft_putstr_fd(str, 1);
	if (flgs.dot > len_num && !flgs.left_just)
		len += ft_put_spaces(flgs.dot - len_num, 1);
	return (len);
}

int		print_hex_num(t_flags flgs, char *str, int len_num, int zero_cond)
{
	int len;

	len = 0;
	if (flgs.zero && (flgs.dot == -1 || flgs.nulldot == 1))
		len += ft_put_spaces(flgs.num - len_num,
			(flgs.zero && (flgs.dot > 0)) ? 1 : 0);
	if (flgs.left_just && !zero_cond)
		ft_putstr_fd(str, 1);
	if (flgs.num > len_num && !(flgs.zero &&
		(flgs.dot == -1 || flgs.nulldot == 1)))
		len += ft_put_spaces(flgs.num - len_num,
			(flgs.zero && flgs.dot != -1) ? 1 : 0);
	return ((len < 0) ? 0 : len);
}

int		print_hex_num_dot(t_flags flgs, char *str, int len, int zero_cond)
{
	int aux;
	int dot_aux;

	aux = 0;
	dot_aux = (((flgs.dot > len) ? flgs.dot : len));
	if (flgs.num > dot_aux && !flgs.left_just)
		aux = ft_put_spaces(flgs.num - dot_aux, 0);
	if (dot_aux > len)
		aux += ft_put_spaces(flgs.dot - len, 1);
	if (flgs.left_just && !zero_cond)
		ft_putstr_fd(str, 1);
	if (flgs.num > dot_aux && flgs.left_just)
		aux += ft_put_spaces(flgs.num - dot_aux, 0);
	return (aux);
}

int		print_hex(unsigned int n, int mayus, t_flags flgs)
{
	char	*str;
	int		len;
	int		len2;
	int		zero_cond;

	zero_cond = ((n == 0 && flgs.dot == -1)) ? 1 : 0;
	zero_cond = ((n == 0 && flgs.nulldot == 1)) ? 2 : zero_cond;
	str = ft_print_base_itoa(n, 16, mayus);
	len = ft_strlen(str);
	len2 = ft_strlen(str) - ((zero_cond) ? 1 : 0);
	if (flgs.num > 0 && flgs.dot > 0)
		len += print_hex_num_dot(flgs, str, len2, zero_cond);
	else if (flgs.num > 0)
		len += print_hex_num(flgs, str, len2, zero_cond);
	else if (flgs.dot > 0)
		len += print_hex_dot(flgs, str, len2, zero_cond);
	if (!flgs.left_just || (flgs.dot <= 0 && flgs.num <= 0))
	{
		if (!zero_cond)
			ft_putstr_fd(str, 1);
	}
	free(str);
	return (len - ((zero_cond) ? 1 : 0));
}
