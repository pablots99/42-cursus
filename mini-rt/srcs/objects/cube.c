/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:04:47 by ptorres           #+#    #+#             */
/*   Updated: 2021/02/04 22:17:49 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_cu_inter2(t_ray *ray, t_faces faces, int color)
{
	t_square sq;

	sq = faces.face4;
	if (get_sq_inter(ray, faces.face4))
	{
		color = int_from_rgb(sq.rgb.r, sq.rgb.g, sq.rgb.b);
		ray->reflexion = sq.refraction;
		ray->specular = sq.specular;
	}
	sq = faces.face5;
	if (get_sq_inter(ray, faces.face5))
	{
		color = int_from_rgb(sq.rgb.r, sq.rgb.g, sq.rgb.b);
		ray->reflexion = sq.refraction;
		ray->specular = sq.specular;
	}
	sq = faces.face6;
	if (get_sq_inter(ray, faces.face6))
	{
		color = int_from_rgb(sq.rgb.r, sq.rgb.g, sq.rgb.b);
		ray->reflexion = sq.refraction;
		ray->specular = sq.specular;
	}
	return color;
}

int get_cu_inter(t_ray *ray, t_faces faces)
{
	int color;
	t_square sq;

	sq = faces.face1;
	color = -1;
	if (get_sq_inter(ray, faces.face1))
	{
		color = int_from_rgb(sq.rgb.r, sq.rgb.g, sq.rgb.b);
		ray->reflexion = sq.refraction;
		ray->specular = sq.specular;
	}
	sq = faces.face2;
	if (get_sq_inter(ray, faces.face2))
	{
		color = int_from_rgb(sq.rgb.r, sq.rgb.g, sq.rgb.b);
		ray->reflexion = sq.refraction;
		ray->specular = sq.specular;
	}
	sq = faces.face3;
	if (get_sq_inter(ray, faces.face3))
	{
		color = int_from_rgb(sq.rgb.r, sq.rgb.g, sq.rgb.b);
		ray->reflexion = sq.refraction;
		ray->specular = sq.specular;
	}
	color = get_cu_inter2(ray, faces, color);
	return color;
}

void move_cube(t_cube *cu, int axis)
{
	if (axis == 123)
		cu->cord.x -= 10;
	if (axis == 124)
		cu->cord.x += 10;
	if (axis == 126)
		cu->cord.y += 10;
	if (axis == 125)
		cu->cord.y -= 10;
	if (axis == 45)
		cu->cord.z += 10;
	if (axis == 46)
		cu->cord.z -= 10;
	save_cube_sides(cu);

	ft_printf("     Plane Moved\n");
}

int select_cu(t_file *c)
{
	if (c->cu_count == 0)
	{
		c->curr_cu = c->cube;
		c->cu_count++;
	}
	else
	{
		if (c->curr_cu->next)
		{
			c->cu_count++;
			c->curr_cu = c->curr_cu->next;
		}
		else
		{
			c->cu_count = 1;
			c->curr_cu = c->cube;
		}
	}
	ft_printf("Cube: %d selected.\n", c->cu_count);
	return (1);
}
void rot_cu(t_cube *cu, int key)
{
	int angle;

	angle = ROT_ANGLE;
	if (key == 0)
		cu->norm_vec = rot_vec_x(cu->norm_vec, angle);
	if (key == 2)
		cu->norm_vec = rot_vec_x(cu->norm_vec, -angle);
	if (key == 13)
		cu->norm_vec = rot_vec_y(cu->norm_vec, angle);
	if (key == 1)
		cu->norm_vec = rot_vec_y(cu->norm_vec, -angle);
	if (key == 6)
		cu->norm_vec = rot_vec_z(cu->norm_vec, angle);
	if (key == 7)
		cu->norm_vec = rot_vec_z(cu->norm_vec, -angle);

	cu->norm_vec = norm_vec(cu->norm_vec);
	save_cube_sides(cu);
	ft_printf("Cube: rotated\n");
}
