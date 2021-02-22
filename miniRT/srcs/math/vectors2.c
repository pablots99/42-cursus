/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:05:19 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 14:01:16 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

float	rad_ang_vec(t_cord v1, t_cord v2)
{
	return (acos(prod_esc(v1, v2) / (mod_vec(v1) * mod_vec(v2))) * M_PI / 180);
}

t_cord	vector_dot_matrix(t_cord v, t_matrix matrix)
{
	t_cord vec;

	vec.x = prod_esc(v, matrix.v1);
	vec.y = prod_esc(v, matrix.v2);
	vec.z = prod_esc(v, matrix.v3);
	return (vec);
}

float	mod_vec(t_cord vec)
{
	return (sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2)));
}

t_cord	ray_cut_point(t_ray ray)
{
	return (sum_vec(ray.origin, esc_dot_vec(ray.len, ray.direction)));
}

t_cord	barycentric_cords(t_triangle tr, t_cord point)
{
	t_cord	res;
	t_cord	v0;
	t_cord	v1;
	t_cord	v2;
	float	inv;

	v0 = rest_vec(tr.cord_2, tr.cord_1);
	v1 = rest_vec(tr.cord_3, tr.cord_1);
	v2 = rest_vec(point, tr.cord_1);
	inv = 1.0 / ((prod_esc(v0, v0) * prod_esc(v1, v1)) -
		(prod_esc(v0, v1) * prod_esc(v0, v1)));
	res.x = ((prod_esc(v1, v1) * prod_esc(v2, v0)) -
		((prod_esc(v0, v1) * prod_esc(v2, v1)))) * inv;
	res.y = ((prod_esc(v0, v0) * prod_esc(v2, v1)) -
		((prod_esc(v0, v1) * prod_esc(v2, v0)))) * inv;
	res.z = 1.0f - res.x - res.y;
	return (res);
}
