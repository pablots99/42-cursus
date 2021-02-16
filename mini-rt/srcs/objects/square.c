/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:06:52 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 18:04:54 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	sq_get_norm(t_cord *norm, t_square *sq)
{
	*norm = norm_vec(prod_vec((rest_vec(sq->points.p2, sq->points.p1)),
		(rest_vec(sq->points.p3, sq->points.p2))));
}

int		get_sq_inter(t_ray *ray, t_square *sq)
{
	t_triangle	tr;
	t_cord		ab;
	t_cord		norm;
	float		den;
	float		len;

	sq_get_norm(&norm, sq);
	if (prod_esc(norm, ray->direction) > 0)
		norm = esc_dot_vec(-1, norm);
	den = prod_esc(ray->direction, norm);
	if (fabs(den) > 0)
	{
		len = prod_esc(rest_vec(sq->cord, ray->origin), norm) / den;
		if (!(len >= 0 && len < ray->len))
			return (-1);
		tr = new_triangle(sq->points.p0, sq->points.p1, sq->points.p2);
		ab = barycentric_cords(tr, ray_intersection(*ray, len));
		if ((ab.x <= 1 && ab.x >= 0) && (ab.y <= 1 && ab.y >= 0))
		{
			ray->len = len - BIAS;
			ray->normal = norm;
			return (1);
		}
	}
	return (-1);
}

void	move_square(t_square *sq, int axis)
{
	if (axis == 123)
		sq->cord.x -= 10;
	if (axis == 124)
		sq->cord.x += 10;
	if (axis == 126)
		sq->cord.y += 10;
	if (axis == 125)
		sq->cord.y -= 10;
	if (axis == 45)
		sq->cord.z += 10;
	if (axis == 46)
		sq->cord.z -= 10;
	save_sq_points(sq);
	ft_printf("     Square Moved\n");
}

void	size_square(t_square *sq, int k)
{
	if (k == 30)
		sq->side += 10;
	if (k == 44)
		sq->side -= 10;
	if (sq->side < 1)
		sq->side = 1;
	save_sq_points(sq);
	ft_printf("     Square Resized\n");
}

int		select_sq(t_file *c)
{
	if (c->sq_count == 0)
	{
		c->curr_sq = c->square;
		c->sq_count++;
	}
	else
	{
		if (c->curr_sq->next)
		{
			c->sq_count++;
			c->curr_sq = c->curr_sq->next;
		}
		else
		{
			c->sq_count = 1;
			c->curr_sq = c->square;
		}
	}
	ft_printf("Square: %d selected.\n", c->sq_count);
	return (1);
}
