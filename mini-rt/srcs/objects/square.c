/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:06:52 by pablo             #+#    #+#             */
/*   Updated: 2021/02/14 20:39:03 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_sq_inter(t_ray *ray, t_square *sq)
{
	float den;
	float len;
	t_triangle tr;
	t_cord ab;
	t_cord norm;

	norm = norm_vec(prod_vec((rest_vec(sq->points.p2, sq->points.p1)),
							 (rest_vec(sq->points.p3, sq->points.p2))));
	if (prod_esc(norm, ray->direction) <= 0)
		norm = esc_dot_vec(-1, norm);
	den = prod_esc(ray->direction, norm);
	if (fabs(den) > 0)
	{
		len = prod_esc(rest_vec(sq->cord, ray->origin), norm) / den;
		if (len >= 0 && len < ray->len)
		{
			tr = new_triangle(sq->points.p0, sq->points.p1, sq->points.p2);
			ab = barycentric_cords(tr, ray_intersection(*ray, len));
			if ((ab.x <= 1 && ab.x >= 0) && (ab.y <= 1 && ab.y >= 0))
			{
				ray->len = len - BIAS;
				ray->normal = sq->norm_v;
				return (1);
			}
		}
	}
	return (-1);
}
void move_square(t_square *sq, int axis)
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
void size_square(t_square *sq, int k)
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

int select_sq(t_file *c)
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

void rot_sq2(t_square *sq, int key)
{

	if (key == 0)
	{
		sq->rot_mat.v1 = norm_vec(rot_vec_y(sq->rot_mat.v1, ROT_ANGLE));
		sq->rot_mat.v2 = norm_vec(rot_vec_y(sq->rot_mat.v2, ROT_ANGLE));
	}
	if (key == 2)
	{
		sq->rot_mat.v1 = norm_vec(rot_vec_y(sq->rot_mat.v1, -ROT_ANGLE));
		sq->rot_mat.v2 = norm_vec(rot_vec_y(sq->rot_mat.v2, -ROT_ANGLE));
	}
	sq->points.p0 = sum_vec(vector_dot_matrix(vector(sq->side / 2 * -1, sq->side / 2, -1), sq->rot_mat), sq->cord);
	sq->points.p1 = sum_vec(vector_dot_matrix(vector(sq->side / 2, sq->side / 2, -1), sq->rot_mat), sq->cord);
	sq->points.p2 = sum_vec(vector_dot_matrix(vector(sq->side / 2 * -1, sq->side / 2 * -1, -1), sq->rot_mat), sq->cord);
	sq->points.p3 = sum_vec(vector_dot_matrix(vector(sq->side / 2, sq->side / 2 * -1, -1), sq->rot_mat), sq->cord);
}

void rot_sq(t_square *sq, int key)
{
	if (key == 7)
	{
		sq->rot_mat.v1 = norm_vec(rot_vec_z(sq->rot_mat.v1, ROT_ANGLE));
		sq->rot_mat.v3 = norm_vec(rot_vec_z(sq->rot_mat.v3, ROT_ANGLE));
	}
	if (key == 6)
	{
		sq->rot_mat.v1 = norm_vec(rot_vec_z(sq->rot_mat.v1, -ROT_ANGLE));
		sq->rot_mat.v3 = norm_vec(rot_vec_z(sq->rot_mat.v3, -ROT_ANGLE));
	}
	if (key == 13)
	{
		sq->rot_mat.v2 = norm_vec(rot_vec_x(sq->rot_mat.v2, ROT_ANGLE));
		sq->rot_mat.v3 = norm_vec(rot_vec_x(sq->rot_mat.v3, ROT_ANGLE));
	}
	if (key == 1)
	{
		sq->rot_mat.v2 = norm_vec(rot_vec_x(sq->rot_mat.v2, -ROT_ANGLE));
		sq->rot_mat.v3 = norm_vec(rot_vec_x(sq->rot_mat.v3, -ROT_ANGLE));
	}
	rot_sq2(sq, key);
}

