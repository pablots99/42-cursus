/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:04:47 by ptorres           #+#    #+#             */
/*   Updated: 2021/02/02 19:14:54 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_cu_inter(t_ray *ray, t_list *sides)
{
	t_square sq;
	t_list *aux;
	int color;
	float len_aux;

	color = 0;
	sq = *(t_square *)sides->content;
	aux = sides;
	while (aux)
	{
		len_aux = ray->len;
		sq = *(t_square *)aux->content;
		if (get_sq_inter(ray, sq) && ray->len < len_aux)
		{
			color = int_from_rgb(sq.rgb.r, sq.rgb.g, sq.rgb.b);
			ray->object = SQUARE;
			ray->reflexion = sq.refraction;
			ray->specular = sq.specular;
		}
		aux = aux->next;
	}
	return color;
}
