/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:31:06 by pablo             #+#    #+#             */
/*   Updated: 2020/12/01 17:10:19 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printwidth(char *s, t_flags flgs, int len)
{
	if (flgs.left_just == 1)
	{
		if (flgs.dot != -1)
			ft_putstr_fd(s, 1);
		ft_put_spaces(flgs.num - len, 0);
	}
	else
	{
		ft_put_spaces(flgs.num - len, 0);
		if (flgs.dot != -1)
			ft_putstr_fd(s, 1);
	}
}

char	*printdot(char *s, t_flags flgs, int *len)
{
	char *aux;

	aux = "";
	if (flgs.dot >= *len)
	{
		aux = ft_substr(s, 0, ft_strlen(s));
	}
	else
	{
		aux = ft_substr(s, 0, flgs.dot);
		*len = flgs.dot;
	}
	return (aux);
}

int		print_string(char *s, t_flags flgs)
{
	int len;

	if (s == NULL && flgs.dot != -1)
		s = "(null)";
	if (flgs.dot == 0 && flgs.nulldot == 1)
		s = "";
	len = ((flgs.dot != -1) ? ft_strlen(s) : 0);
	if (flgs.dot == -1 && flgs.num == 0)
		return (0);
	else if (flgs.dot > 0)
		s = printdot(s, flgs, &len);
	if (flgs.num != 0)
		printwidth(s, flgs, len);
	else if (flgs.dot != -1)
		ft_putstr_fd(s, 1);
	if (flgs.dot > 0)
		free(s);
	return ((flgs.num - len > 0) ? flgs.num : len);
}
