/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:57:32 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 22:33:01 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int		get_pl_inter(t_ray *ray, t_plane pl)
{
	float len;
	float den;

	den = prod_esc(ray->direction, pl.norm_v);
	if (fabs(den) > 0)
	{
		len = prod_esc(rest_vec(pl.cord, ray->origin), pl.norm_v) / den;
		if (len < ray->len && len >= 0)
		{
			ray->len = len - BIAS;
			ray->normal = pl.norm_v;
			return (1);
		}
	}
	return (-1);
}

void	move_plane(t_plane *pl, int axis)
{
	if (axis == 123)
		pl->cord.x -= 10;
	if (axis == 124)
		pl->cord.x += 10;
	if (axis == 126)
		pl->cord.y += 10;
	if (axis == 125)
		pl->cord.y -= 10;
	if (axis == 45)
		pl->cord.z += 10;
	if (axis == 46)
		pl->cord.z -= 10;
	ft_printf("     Plane Moved\n");
}

int		select_pl(t_file *c)
{
	if (c->pl_count == 0)
	{
		c->curr_pl = c->plane;
		c->pl_count++;
	}
	else
	{
		if (c->curr_pl->next)
		{
			c->pl_count++;
			c->curr_pl = c->curr_pl->next;
		}
		else
		{
			c->pl_count = 1;
			c->curr_pl = c->plane;
		}
	}
	ft_printf("Pane: %d selected.\n", c->pl_count);
	return (1);
}

void	rot_pl(t_plane *pl, int key)
{
	int angle;

	angle = ROT_ANGLE;
	if (key == 0)
		pl->norm_v = rot_vec_x(pl->norm_v, angle);
	if (key == 2)
		pl->norm_v = rot_vec_x(pl->norm_v, -angle);
	if (key == 13)
		pl->norm_v = rot_vec_y(pl->norm_v, angle);
	if (key == 1)
		pl->norm_v = rot_vec_y(pl->norm_v, -angle);
	if (key == 6)
		pl->norm_v = rot_vec_z(pl->norm_v, angle);
	if (key == 7)
		pl->norm_v = rot_vec_z(pl->norm_v, -angle);
	pl->norm_v = norm_vec(pl->norm_v);
	ft_printf("Plane: rotated\n");
}
