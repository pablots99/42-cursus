/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:10:38 by pablo             #+#    #+#             */
/*   Updated: 2021/01/27 15:52:05 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"


void move_camera(t_camera *c, int axis)
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
    ft_printf("     Camera Moved");
}
void zoom_camera(t_camera *c, int k)
{
    if (k == 30)
        c->fov -= 10;
    if (k == 44)
        c->fov += 10;
    if(c->fov > 180)
        c->fov = 180;
     if(c->fov < 0)
        c->fov = 0;
    ft_printf("     Camera Fov: %d",c->fov);

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
    //paint_scene(c);
    threats(c,0);
    mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img.mlx_img, 0, 0);
    ft_printf("Camera: %d\n", c->cam_count);
    return (1);
}