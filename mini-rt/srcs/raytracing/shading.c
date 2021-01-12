/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:51:39 by pablo             #+#    #+#             */
/*   Updated: 2021/01/12 16:03:21 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int shading(t_ray *ray, int color, t_file c)
{
    t_cord vec_ligth;
    t_ray pointo_ligth;
    t_ligth ligth;
    float brigth;

    ligth = *((t_ligth *)c.ligth->content);
    pointo_ligth.origin = ray_cut_point(*ray);
    
    vec_ligth = rest_vec(ligth.cord, pointo_ligth.origin);
    pointo_ligth.direction = norm_vec(vec_ligth);
    pointo_ligth.len = mod_vec(vec_ligth);
    if (get_intersections(&pointo_ligth, c))
        return (color);
    //calcular la intensidad de la luz con la normal del punto de corte
    //brigth = fabs(cos(prod_esc(ray->normal,pointo_ligth.direction))*ligth.brigthness) + 0.9;
    brigth = ligth.brigthness/c.ambient_ligth.ratio;
    color = create_int_color_shade(rgb_from_int(color), ligth, brigth);
    return (color);
}