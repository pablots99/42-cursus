/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 12:16:02 by pablo             #+#    #+#             */
/*   Updated: 2021/01/05 18:06:55 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../mini_rt.h"




t_ray generate_ray(int x, int y, t_file c)
{
    t_ray ray;
    t_camera camera;

    camera = *((t_camera *)c.camera->content);
    ray.origin = camera.cord;
    ray.direction.z = -1;
    ray.direction.x = 2 * (((float)x + 0.5) * camera.canvas.canvas_w/c.win_width) - camera.canvas.canvas_w;
    ray.direction.y = camera.canvas.canvas_h -2 * (((float)y + 0.5)* camera.canvas.canvas_h/c.win_heigth);


    
    return (ray);
}
