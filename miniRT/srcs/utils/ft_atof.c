/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:15:14 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 16:31:17 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	init_vars(float *res, float *cont, int *i)
{
	*i = 0;
	*cont = 0;
	*res = 0;
}

float	ft_atof(char *num)
{
	float	res;
	float	cont;
	int		i;

	init_vars(&res, &cont, &i);
	while (num[i])
	{
		if (num[i] == '.' && !cont)
		{
			cont = 1;
			i++;
		}
		if (ft_isdigit(num[i]))
		{
			res = (res * 10) + (num[i] - '0');
			if (cont)
				cont *= 10;
		}
		i++;
	}
	if (cont == 0)
		cont = 1;
	if (*num == '-')
		res *= -1;
	return (res / (cont) + ft_atoi(""));
}
