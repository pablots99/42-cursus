/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:51:39 by pablo             #+#    #+#             */
/*   Updated: 2021/01/24 13:59:06 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

float calculate_specular(t_ray *ray)
{
    t_cord r;

    t_cord dir;

    dir = esc_dot_vec(-1, ray->direction);
    float spec;
    r = rest_vec(esc_dot_vec(2 * prod_esc(ray->normal, dir),ray->normal),dir);
    spec = pow(prod_esc(r, ray->direction), 20);

    return 0;
}

int shading(t_ray *ray, int color, t_file *c)
{
    t_cord vec_ligth;
    t_ray pointo_ligth;
    t_ligth ligth;
    float brigth;
    t_list *aux;
    int color_aux;
    t_ray refracted;

    refracted = refracted_ray(ray);
    if (ray->refraction > 0)
        return shading(&refracted, get_intersections(&refracted, c), c);
    color_aux = color;
    aux = c->ligth;
    while (aux)
    {
        ligth = *((t_ligth *)aux->content);
        pointo_ligth.origin = ray_cut_point(*ray);
        vec_ligth = rest_vec(ligth.cord, pointo_ligth.origin);
        pointo_ligth.direction = norm_vec(vec_ligth);
        pointo_ligth.len = mod_vec(vec_ligth);
        if (get_intersections(&pointo_ligth, c))
            return (ambient_color(rgb_from_int(color), c->ambient_ligth));
        brigth = max_float(c->ambient_ligth.ratio, (prod_esc(ray->normal, norm_vec(vec_ligth)) * (ligth.brigthness)));
        color = create_shade_color(rgb_from_int(color), ligth, brigth,calculate_specular(&pointo_ligth));
        aux = aux->next;
    }
    return (color);
}