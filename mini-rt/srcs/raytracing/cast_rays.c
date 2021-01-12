/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 12:16:02 by pablo             #+#    #+#             */
/*   Updated: 2021/01/12 18:09:56 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_ray generate_ray(int x, int y, t_file c)
{
    t_ray ray;
    t_camera camera;

    camera = *((t_camera *)c.camera->content);
    ray.origin = camera.cord;
    ray.direction.x = (2 * (((float)x + 0.5) / (float)c.win_width) - 1) * tan((camera.fov/2) * ( M_PI / 180)) * c.aspect_ratio;
    ray.direction.y = (1 - 2 * ((float)y + 0.5) / ((float)c.win_heigth)) * tan((camera.fov/2) * ( M_PI / 180));
    ray.direction.z = -1;
    ray.direction = norm_vec(vector_dot_matrix(norm_vec(ray.direction), camera.canvas.matrix));
    ray.len = INFINITY;
    ray.normal = vector(0,0,0);
    return (ray);
}

int get_intersections(t_ray *ray, t_file c)
{
    int color;
    int color_aux;
    float len;
   

    color = 0;
    len = ray->len;
    if (c.sphere && (color_aux = spheres_intersection(ray, c.sphere,c)) && ray->len < len)
    {
        color = color_aux;
        len = ray->len;
    }
    if (c.plane && (color_aux = plane_intersection(ray, c.plane,c)) && ray->len < len)
    {
        color = color_aux;
            len = ray->len;
    }
      if (c.cylinder && (color_aux = cylinder_intersection(ray, c.cylinder,c)) && ray->len < len)
    {
        color = color_aux;
        len = ray->len;
    }
    if (c.square && (color_aux = square_intersection(ray, c.square,c)) && ray->len < len)
    {
        color = color_aux;
        len = ray->len;
    }
       if (c.triangle && (color_aux = triangle_intersection(ray, c.triangle,c)) && ray->len < len)
    {
        color = color_aux;
        len = ray->len;
    }
  
    return (color);
}

