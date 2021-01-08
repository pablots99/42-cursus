/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 12:16:02 by pablo             #+#    #+#             */
/*   Updated: 2021/01/07 22:13:06 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_ray generate_ray(int x, int y, t_file c)
{
    t_ray ray;
    t_camera camera;

    camera = *((t_camera *)c.camera->content);
    ray.origin = camera.cord;
    ray.direction.x = (2 * (((float)x+ 0.5) / (float)c.win_width )- 1) * (camera.canvas.canvas_w / 2);
    ray.direction.y = (1 - 2 * ((float)y + 0.5) / (float)(c.win_heigth)) * (camera.canvas.canvas_h / 2);
    ray.direction.z = -1;
    ray.direction = norm_vec(vector_dot_matrix(norm_vec(ray.direction), camera.canvas.matrix));
    ray.len = INFINITY;
    return (ray);
}

int get_intersections(t_ray *ray, t_file c)
{
    int color;
    int color_aux;
    float len;

    color = 0;
    len = ray->len;
    if (c.plane && (color_aux = plane_intersection(ray, c.plane)) && ray->len < len)
        color = color_aux;
    len = ray->len;

    if (c.sphere && (color_aux = spheres_intersection(ray, c.sphere)) && ray->len < len)
        color = color_aux;

    return (color);
}
