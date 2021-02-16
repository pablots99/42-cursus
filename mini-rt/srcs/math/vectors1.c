/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:05:23 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 13:59:06 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_ray	reflected_ray(t_ray *ray)
{
	t_ray	res;
	t_cord	dir;

	dir = esc_dot_vec(-1, ray->direction);
	res.direction = rest_vec(esc_dot_vec(2 * prod_esc(ray->normal, dir),
		ray->normal), dir);
	res.len = INFINITY;
	res.reflexion = 0;
	res.object = 0;
	res.origin = ray_cut_point(*ray);
	return (res);
}

t_cord	rot_center_point(t_cord p, int ang)
{
	t_cord	res;
	float	s;
	float	c;

	if (ang == 0)
		return (p);
	s = sin(ang * M_PI / 180);
	c = cos(ang * M_PI / 180);
	res.x = (p.x * c) - (p.y * s);
	res.y = (p.x * s) + (p.y * c);
	return (res);
}

t_cord	rot_vec_x(t_cord vec, int a)
{
	t_matrix mat;

	if (a > 360)
		a = a - 360;
	mat.v1 = vector(1, 0, 0);
	mat.v2 = vector(0, cos(a), -sin(a));
	mat.v3 = vector(0, sin(a), cos(a));
	printf("anlge:%d\n", a);
	return (vector_dot_matrix(vec, mat));
}

t_cord	rot_vec_y(t_cord vec, int a)
{
	t_matrix mat;

	if (a > 360)
		a = a - 360;
	mat.v1 = vector(cos(a), 0, sin(a));
	mat.v2 = vector(0, 1, 0);
	mat.v3 = vector(-sin(a), 0, cos(a));
	return (vector_dot_matrix(vec, mat));
}

t_cord	rot_vec_z(t_cord vec, int a)
{
	t_matrix mat;

	if (a > 360)
		a = a - 360;
	mat.v1 = vector(cos(a), -sin(a), 0);
	mat.v2 = vector(sin(a), cos(a), 0);
	mat.v3 = vector(0, 0, 1);
	return (vector_dot_matrix(vec, mat));
}
