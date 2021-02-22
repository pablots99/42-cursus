/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:31:46 by ptorres           #+#    #+#             */
/*   Updated: 2021/02/16 16:35:12 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	size_objects(t_file *c, int key)
{
	if (c->obj_selected == SPHERE && c->curr_sp)
		size_sphere((t_sphere *)c->curr_sp->content, key);
	else if (c->obj_selected == CAMERA && c->camera)
		zoom_camera((t_camera *)c->camera->content, key);
	else if (c->obj_selected == SQUARE && c->curr_sq)
		size_square((t_square *)c->curr_sq->content, key);
	else if (c->obj_selected == CYLINDER && c->curr_cy)
		size_cylinder((t_cylinder *)c->curr_cy->content, key);
	else if (c->obj_selected == TRIANGLE && c->curr_tr)
		size_triangle((t_triangle *)c->curr_tr->content, key);
	else if (c->obj_selected == LIGTH && c->curr_tr)
		change_ligth_intesity((t_ligth *)c->curr_l->content, key);
	else if (c->obj_selected == CUBE && c->curr_cu)
		size_cu((t_cube *)c->curr_cu->content, key);
	else
	{
		ft_printf("     -Can´t resize object or No Object selected\n");
		return ;
	}
	threats(c, 0);
	mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img.mlx_img, 0, 0);
}

void	rot_objects(t_file *c, int key)
{
	if (c->obj_selected == CAMERA && c->camera)
		rot_cam((t_camera *)c->camera->content, key);
	else if (c->obj_selected == CYLINDER && c->curr_cy)
		rot_cy((t_cylinder *)c->curr_cy->content, key);
	else if (c->obj_selected == PLANE && c->curr_pl)
		rot_pl((t_plane *)c->curr_pl->content, key);
	else if (c->obj_selected == SQUARE && c->curr_sq)
		rot_sq((t_square *)c->curr_sq->content, key);
	else if (c->obj_selected == PYRAMID && c->curr_py)
		rot_py((t_pyramid *)c->curr_py->content, key);
	else if (c->obj_selected == CUBE && c->curr_cu)
		rot_cu((t_cube *)c->curr_cu->content, key);
	else
	{
		ft_printf("     -Can´t rotate object or No Object selected\n");
		return ;
	}
	threats(c, 0);
	mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img.mlx_img, 0, 0);
}

int		detect_key(int keycode, t_file *c)
{
	if (keycode == 8 && c->camera)
		select_camera(c);
	if (keycode == 31 && BONUS == 1)
		select_type_object(c);
	if (keycode == 35 && BONUS == 1)
		select_object(c);
	if (((keycode >= 123 && keycode <= 126) || keycode == 45
		|| keycode == 46) && BONUS == 1)
		move_objects(c, keycode);
	if ((keycode == 30 || keycode == 44) && BONUS == 1)
		size_objects(c, keycode);
	if ((keycode == 6 || keycode == 7 || keycode == 0 || keycode == 1
		|| keycode == 2 || keycode == 13) && BONUS == 1)
		rot_objects(c, keycode);
	if (keycode == 4 && BONUS == 1)
		create_bmp_file(c, "screeshot.bmp");
	return (1);
}
