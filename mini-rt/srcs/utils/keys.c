/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:06:31 by pablo             #+#    #+#             */
/*   Updated: 2021/01/24 18:07:28 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void select_type_object(t_file *c)
{
    c->obj_selected++;
    if (c->obj_selected > 6)
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
}

void select_object(t_file *c)
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
    else
        ft_printf("     -No object of the type selected\n");
}
void move_objects(t_file *c, int key)
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
     else if (c->obj_selected == PLANE && c->plane)
        move_plane((t_plane *)c->curr_pl->content, key);
    else
    {
        ft_printf("     -Can´t move object or No Object selected\n");
        return;
    }
    paint_scene(c);
    mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img.mlx_img, 0, 0);
}
void size_objects(t_file *c, int key)
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
    else
    {
        ft_printf("     -Can´t resize object or No Object selected\n");
        return;
    }
    paint_scene(c);
    mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img.mlx_img, 0, 0);
}
void rot_objects(t_file *c, int key)
{
    if (c->obj_selected == SQUARE && c->curr_sq)
        rot_square((t_square *)c->curr_sq->content, key);
    else
    {
        ft_printf("     -Can´t rotate object or No Object selected\n");
        return;
    }
    paint_scene(c);
    mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img.mlx_img, 0, 0);
}
int detect_key(int keycode, t_file *c)
{
    printf("key%d\n",keycode);
    if (keycode == 8 && c->camera)
        select_camera(c);
    if (keycode == 31)
        select_type_object(c);
    if (keycode == 35)
        select_object(c);
    if ((keycode >= 123 && keycode <= 126) || keycode == 45 || keycode == 46)
        move_objects(c, keycode);
    if (keycode == 30 || keycode == 44)
        size_objects(c, keycode);
    if (keycode == 6 || keycode == 7 || keycode == 0 || keycode ==1 || keycode == 2 || keycode == 13)
        rot_objects(c, keycode);
    return 1;
}