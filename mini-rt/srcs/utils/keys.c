/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:06:31 by pablo             #+#    #+#             */
/*   Updated: 2021/01/15 17:15:14 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void select_type_object(t_file *c)
{
    c->obj_selected++;
    if (c->obj_selected > 2)
        c->obj_selected = 0;
    if (c->obj_selected == 0)
        ft_printf("Selected Object: None.\n");
    if (c->obj_selected == 1)
        ft_printf("Selected Object: Spheres.\n");
    if (c->obj_selected == 2)
        ft_printf("Selected Object: Camera.\n");
}

void select_object(t_file *c)
{
    if (c->obj_selected == 0)
        ft_printf("     -No Type selected\n");
    else if (c->obj_selected == 1 && c->sphere)
        select_sp(c);
    else if (c->obj_selected == 2 && c->camera)
        ft_printf("Camera: %d selected.(Press 'c' to switch.)\n", c->cam_count);
    else
        ft_printf("     -No object of the type selected\n");
}
void move_objects(t_file *c, int key)
{
    if (c->obj_selected == 1 && c->curr_sp)
        move_sphere((t_sphere *)c->curr_sp->content, key);
    else if (c->obj_selected == 2 && c->camera)
        move_camera((t_camera *)c->camera->content, key);
    else
    {
        ft_printf("     -No Object selected\n");
        return;
    }
    paint_scene(c);
    mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img.mlx_img, 0, 0);
}
void size_objects(t_file *c, int key)
{
    if (c->obj_selected == 1 && c->curr_sp)
        size_sphere((t_sphere *)c->curr_sp->content, key);
    else if (c->obj_selected == 2 && c->camera)
        zoom_camera((t_camera *)c->camera->content, key);
    else
    {
        ft_printf("     -No Object selected\n");
        return;
    }
    paint_scene(c);
    mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img.mlx_img, 0, 0);
}
int detect_key(int keycode, t_file *c)
{
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
    return 1;
}

