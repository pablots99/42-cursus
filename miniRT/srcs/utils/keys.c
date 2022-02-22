/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:06:31 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 16:33:10 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	select_type_object(t_file *c)
{
	c->obj_selected++;
	if (c->obj_selected > 9)
		c->obj_selected = 0;
	if (c->obj_selected == 0)
		ft_printf("Selected Object: None.\n");
	if (c->obj_selected == SPHERE)
		ft_printf("Selected Object: Spheres.\n");
	if (c->obj_selected == CAMERA)
		ft_printf("Selected Object: Camera.\n");
	if (c->obj_selected == SQUARE)
		ft_printf("Selected Object: Square.\n");
	if (c->obj_selected == PLANE)
		ft_printf("Selected Object: Plane.\n");
	if (c->obj_selected == TRIANGLE)
		ft_printf("Selected Object: Trinagle.\n");
	if (c->obj_selected == CYLINDER)
		ft_printf("Selected Object: Cylinder.\n");
	if (c->obj_selected == LIGTH)
		ft_printf("Selected Object: Ligth.\n");
	if (c->obj_selected == PYRAMID)
		ft_printf("Selected Object: Pyramid.\n");
	if (c->obj_selected == CUBE)
		ft_printf("Selected Object: Cube.\n");
}

void	select_object(t_file *c)
{
	if (c->obj_selected == 0)
		ft_printf("     -No Type selected\n");
	else if (c->obj_selected == SPHERE && c->sphere)
		select_sp(c);
	else if (c->obj_selected == CAMERA && c->camera)
		ft_printf("Camera: %d selected.(Press 'c' to switch.)\n", c->cam_count);
	else if (c->obj_selected == SQUARE && c->square)
		select_sq(c);
	else if (c->obj_selected == CYLINDER && c->cylinder)
		select_cy(c);
	else if (c->obj_selected == TRIANGLE && c->triangle)
		select_tr(c);
	else if (c->obj_selected == PLANE && c->plane)
		select_pl(c);
	else if (c->obj_selected == LIGTH && c->ligth)
		select_l(c);
	else if (c->obj_selected == PYRAMID && c->pyramid)
		select_py(c);
	else if (c->obj_selected == CUBE && c->cube)
		select_cu(c);
	else
		ft_printf("     -No object of the type selected\n");
}

void	move_objects(t_file *c, int key)
{
	if (c->obj_selected == SPHERE && c->curr_sp)
		move_sphere((t_sphere *)c->curr_sp->content, key);
	else if (c->obj_selected == CAMERA && c->camera)
		move_camera((t_camera *)c->camera->content, key);
	else if (c->obj_selected == SQUARE && c->curr_sq)
		move_square((t_square *)c->curr_sq->content, key);
	else if (c->obj_selected == CYLINDER && c->curr_cy)
		move_cylinder((t_cylinder *)c->curr_cy->content, key);
	else if (c->obj_selected == TRIANGLE && c->curr_tr)
		move_triangle((t_triangle *)c->curr_tr->content, key);
	else if (c->obj_selected == PLANE && c->curr_pl)
		move_plane((t_plane *)c->curr_pl->content, key);
	else if (c->obj_selected == LIGTH && c->curr_l)
		move_ligth((t_ligth *)c->curr_l->content, key);
	else if (c->obj_selected == PYRAMID && c->curr_py)
		move_pyramid((t_pyramid *)c->curr_py->content, key);
	else if (c->obj_selected == CUBE && c->curr_cu)
		move_cube((t_cube *)c->curr_cu->content, key);
	else
	{
		ft_printf("     -Can´t move object or No Object selected\n");
		return ;
	}
	threats(c, 0);
	mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img.mlx_img, 0, 0);
}
