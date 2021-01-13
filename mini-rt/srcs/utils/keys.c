/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:06:31 by pablo             #+#    #+#             */
/*   Updated: 2021/01/13 23:02:28 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int detect_key(int keycode,t_file *c)
{
    if(keycode == 8 && c->camera)
        select_camera(c);
    return 1;
}

int select_camera(t_file *c)
{
    if(c->camera->next)
    {
        c->cam_count++; 
        c->camera = c->camera->next;
    }
    else
    {
        c->cam_count = 1;
        c->camera = c->first_cam;
    }
    c->img.mlx_img = mlx_new_image(c->mlx_ptr, c->win_width, c->win_heigth);
    c->img.address = mlx_get_data_addr(c->img.mlx_img, &c->img.bits_per_pixel,
                                       &c->img.line_length, &c->img.endian);
    paint_scene(c);
    mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img.mlx_img, 0, 0);
    ft_printf("Camera: %d\n",c->cam_count);
    return (1);
}