/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:06:31 by pablo             #+#    #+#             */
/*   Updated: 2021/01/14 02:16:13 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void select_type_object(t_file *c)
{
    c->obj_selected++;
    if (c->obj_selected > 1)
        c->obj_selected = 0;
    if (c->obj_selected == 0)
        ft_printf("Selected Object: None.\n");
    if (c->obj_selected == 1)
        ft_printf("Selected Object: Spheres.\n");
}
int select_sp(t_file *c)
{
    if (c->sp_count == 0)
    {
        c->curr_sp = c->sphere;
        c->sp_count++;
    }
    else
    {
        if (c->curr_sp->next)
        {
            c->sp_count++;
            c->curr_sp = c->curr_sp->next;
        }
        else
        {
            c->sp_count = 1;
            c->curr_sp = c->sphere;
        }
    }
    ft_printf("Sphere: %d selected.\n", c->sp_count);
    return (1);
}

void select_object(t_file *c)
{
    if (c->obj_selected == 0)
        ft_printf("     -No Type selected\n");
    else if (c->obj_selected == 1 && c->sphere)
        select_sp(c);
    else
        ft_printf("     -No object of the type selected\n");
}
void move_objects(t_file *c, int key)
{
    if (c->obj_selected == 1 && c->curr_sp)
        move_sphere((t_sphere *)c->curr_sp->content, key);
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
    if (keycode >= 123 && keycode <= 126)
        move_objects(c, keycode);
    return 1;
}

int select_camera(t_file *c)
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
    paint_scene(c);
    mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img.mlx_img, 0, 0);
    ft_printf("Camera: %d\n", c->cam_count);
    return (1);
}