/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:00:01 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 14:19:04 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int		select_cy(t_file *c)
{
	if (c->cy_count == 0)
	{
		c->curr_cy = c->cylinder;
		c->cy_count++;
	}
	else
	{
		if (c->curr_cy->next)
		{
			c->cy_count++;
			c->curr_cy = c->curr_cy->next;
		}
		else
		{
			c->cy_count = 1;
			c->curr_cy = c->cylinder;
		}
	}
	ft_printf("Cylinder: %d selected.\n", c->cy_count);
	return (1);
}

void	move_cylinder(t_cylinder *cy, int axis)
{
	if (axis == 123)
		cy->cord.x -= 10;
	if (axis == 124)
		cy->cord.x += 10;
	if (axis == 126)
		cy->cord.y += 10;
	if (axis == 125)
		cy->cord.y -= 10;
	if (axis == 45)
		cy->cord.z += 10;
	if (axis == 46)
		cy->cord.z -= 10;
	ft_printf("     Cylinder Moved\n");
}

void	size_cylinder(t_cylinder *cy, int k)
{
	if (k == 30)
	{
		cy->height += 10;
		cy->diameter += 10;
	}
	if (k == 44)
	{
		cy->height -= 10;
		cy->diameter -= 10;
	}
	if (cy->height < 1)
		cy->height = 1;
	if (cy->diameter < 1)
		cy->diameter = 1;
	ft_printf("     Cylinder Resized\n");
}

void	rot_cy(t_cylinder *cy, int key)
{
	int angle;

	angle = ROT_ANGLE;
	if (key == 0)
		cy->norm_v = rot_vec_x(cy->norm_v, angle);
	if (key == 2)
		cy->norm_v = rot_vec_x(cy->norm_v, -angle);
	if (key == 13)
		cy->norm_v = rot_vec_y(cy->norm_v, angle);
	if (key == 1)
		cy->norm_v = rot_vec_y(cy->norm_v, -angle);
	if (key == 6)
		cy->norm_v = rot_vec_z(cy->norm_v, angle);
	if (key == 7)
		cy->norm_v = rot_vec_z(cy->norm_v, -angle);
	cy->norm_v = norm_vec(cy->norm_v);
	ft_printf("Cylinder: rotated\n");
}
