/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:28:06 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 14:06:28 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int		get_cu_inter(t_ray *ray, t_cube cu)
{
	int cond;

	cond = 0;
	cond += get_sq_inter(ray, &cu.face1);
	cond += get_sq_inter(ray, &cu.face2);
	cond += get_sq_inter(ray, &cu.face3);
	cond += get_sq_inter(ray, &cu.face4);
	cond += get_sq_inter(ray, &cu.face5);
	cond += get_sq_inter(ray, &cu.face6);
	if (cond > -6)
		return (1);
	return (0);
}

int		select_cu(t_file *c)
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

void	move_cube(t_cube *cu, int axis)
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
	save_sq_points(&cu->face1);
	save_cube_base(cu, 0);
	save_cube_faces(cu);
	ft_printf("     Cube Moved\n");
}

void	rot_cu(t_cube *cu, int key)
{
	rot_sq(&cu->face1, key);
	save_cube_base(cu, 1);
	rot_sq(&cu->face2, key);
	save_cube_faces(cu);
}

void	size_cu(t_cube *cu, int k)
{
	if (k == 30)
		cu->width += 10;
	if (k == 44)
		cu->width -= 10;
	if (cu->width < 1)
		cu->width = 1;
	save_cube_faces(cu);
	ft_printf("     Cube Resized\n");
}
