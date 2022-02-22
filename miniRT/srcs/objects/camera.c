/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:10:38 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 14:05:27 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	move_camera(t_camera *c, int axis)
{
	if (axis == 123)
		c->cord.x -= 10;
	if (axis == 124)
		c->cord.x += 10;
	if (axis == 126)
		c->cord.y += 10;
	if (axis == 125)
		c->cord.y -= 10;
	if (axis == 45)
		c->cord.z += 10;
	if (axis == 46)
		c->cord.z -= 10;
	ft_printf("     Camera Moved\n");
}

void	zoom_camera(t_camera *c, int k)
{
	if (k == 30)
		c->fov -= 10;
	if (k == 44)
		c->fov += 10;
	if (c->fov > 180)
		c->fov = 180;
	if (c->fov < 0)
		c->fov = 0;
	ft_printf("     Camera Fov: %d\n", c->fov);
}

int		select_camera(t_file *c)
{
	if (c->camera->next)
	{
		c->cam_count++;
		c->camera = c->camera->next;
	}
	else
	{
		c->cam_count = 1;
		c->camera = c->first_cam;
	}
	threats(c, 0);
	mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img.mlx_img, 0, 0);
	ft_printf("Camera: %d\n", c->cam_count);
	return (1);
}

void	rot_cam2(t_camera *camera, int key)
{
	if (key == 0)
	{
		camera->canvas.matrix.v1 =
			rot_vec_y(camera->canvas.matrix.v1, ROT_ANGLE);
		camera->canvas.matrix.v3 =
			rot_vec_y(camera->canvas.matrix.v3, ROT_ANGLE);
	}
	if (key == 2)
	{
		camera->canvas.matrix.v1 =
			rot_vec_y(camera->canvas.matrix.v1, -ROT_ANGLE);
		camera->canvas.matrix.v3 =
			rot_vec_y(camera->canvas.matrix.v3, -ROT_ANGLE);
	}
}

void	rot_cam(t_camera *camera, int key)
{
	if (key == 7 || key == 6)
		ft_printf("Camera: can´t ratate this axis\n");
	if (key == 13)
	{
		camera->canvas.matrix.v2 =
			rot_vec_x(camera->canvas.matrix.v2, ROT_ANGLE);
		camera->canvas.matrix.v3 =
			rot_vec_x(camera->canvas.matrix.v3, ROT_ANGLE);
	}
	if (key == 1)
	{
		camera->canvas.matrix.v2 =
			rot_vec_x(camera->canvas.matrix.v2, -ROT_ANGLE);
		camera->canvas.matrix.v3 =
			rot_vec_x(camera->canvas.matrix.v3, -ROT_ANGLE);
	}
	rot_cam2(camera, key);
	camera->canvas.matrix.v2 = norm_vec(camera->canvas.matrix.v2);
	camera->canvas.matrix.v3 = norm_vec(camera->canvas.matrix.v3);
	camera->canvas.matrix.v1 = norm_vec(camera->canvas.matrix.v1);
}
