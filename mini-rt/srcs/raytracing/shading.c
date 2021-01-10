/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:51:39 by pablo             #+#    #+#             */
/*   Updated: 2021/01/10 17:56:02 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int shading(t_ray *ray, int color, t_file c)
{
    t_cord vec_ligth;
    t_ray aux_ray;
    t_ligth ligth;
    float brigth;
    ligth = *((t_ligth *)c.ligth->content);

    vec_ligth = rest_vec(ligth.cord, ray_cut_point(*ray));

    aux_ray.direction = norm_vec(vec_ligth);

    aux_ray.len = mod_vec(vec_ligth);

    aux_ray.origin = ray_cut_point(*ray);

    if (get_intersections(&aux_ray, c))
        return (color);

    //brigth = (ligth.brigthness * prod_esc(ray->normal,aux_ray.direction)/1);
    brigth = c.ambient_ligth.ratio;
    color = create_int_color_shade( rgb_from_int(color), ligth,brigth);

    return (color);
}