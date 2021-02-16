/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:18:03 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 16:37:19 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../mini_rt.h"

int			ft_str_isnum(char *num)
{
	int i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int			ft_bistrlen(char **str)
{
	int i;

	if (!*str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			parse_error(char *err)
{
	ft_printf("Error\n     %s\n", err);
	return (1);
}

t_triangle	new_triangle(t_cord p1, t_cord p2, t_cord p3)
{
	t_triangle res;

	res.cord_1 = p1;
	res.cord_2 = p2;
	res.cord_3 = p3;
	return (res);
}
