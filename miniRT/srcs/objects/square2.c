/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:32:18 by ptorres           #+#    #+#             */
/*   Updated: 2021/02/16 22:02:55 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	rot_sq2(t_square *sq, int key)
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
	sq->points.p0 = sum_vec(vector_dot_matrix(vector(sq->side / 2 * -1,
		sq->side / 2, 0), sq->rot_mat), sq->cord);
	sq->points.p1 = sum_vec(vector_dot_matrix(vector(sq->side / 2,
		sq->side / 2, 0), sq->rot_mat), sq->cord);
	sq->points.p2 = sum_vec(vector_dot_matrix(vector(sq->side / 2 * -1,
		sq->side / 2 * -1, 0), sq->rot_mat), sq->cord);
	sq->points.p3 = sum_vec(vector_dot_matrix(vector(sq->side / 2,
	sq->side / 2 * -1, 0), sq->rot_mat), sq->cord);
}

void	rot_sq(t_square *sq, int key)
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
