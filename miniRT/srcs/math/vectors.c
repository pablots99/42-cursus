/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:45:28 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 13:55:55 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_cord	vector(float x, float y, float z)
{
	t_cord vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_cord	norm_vec(t_cord vec)
{
	t_cord	norm_vec;
	float	l;

	l = mod_vec(vec);
	norm_vec.x = vec.x / l;
	norm_vec.y = vec.y / l;
	norm_vec.z = vec.z / l;
	return (norm_vec);
}

t_cord	prod_vec(t_cord v1, t_cord v2)
{
	t_cord vec;

	vec.x = v1.y * v2.z - v1.z * v2.y;
	vec.y = v1.z * v2.x - v1.x * v2.z;
	vec.z = v1.x * v2.y - v1.y * v2.x;
	return (vec);
}

t_cord	esc_dot_vec(float num, t_cord c)
{
	t_cord vec;

	vec.x = c.x * num;
	vec.y = c.y * num;
	vec.z = c.z * num;
	return (vec);
}

t_cord	ray_intersection(t_ray ray, float len)
{
	return (sum_vec(esc_dot_vec(len, ray.direction), ray.origin));
}
