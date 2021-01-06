/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:51:00 by pablo             #+#    #+#             */
/*   Updated: 2021/01/06 21:14:17 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_sp_inter(t_ray ray, t_sphere sp)
{
    t_cord l;
    float tca;
    float d;
    
    l = points_vec(ray.origin, sp.cord);
    tca = prod_esc(ray.direction, l);
    d =  prod_esc(l,l) - tca * tca;

    if (d < 0 || d > sp.diameter / 2)
        return -1;
    return create_int_color(1, sp.rgb.r, sp.rgb.g, sp.rgb.b);
}

int spheres_intersection(t_ray ray, t_list *list)
{
    t_sphere sphere;
    t_list *aux;
    int color;

    color = 0;
    sphere = *(t_sphere *)list->content;
    aux = list;
    while (aux->next)
    {
        sphere = *(t_sphere *)aux->content;
        if ((color = get_sp_inter(ray, sphere)) >= 0)
            return color;
        aux = aux->next;
    }
    sphere = *(t_sphere *)aux->content;
    if ((color = get_sp_inter(ray, sphere)) > 0)
        return color;
    return (0);
}
