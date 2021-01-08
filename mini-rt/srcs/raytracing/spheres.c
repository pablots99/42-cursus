/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:51:00 by pablo             #+#    #+#             */
/*   Updated: 2021/01/08 12:37:54 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_sp_inter(t_ray *ray, t_sphere sp)
{
    t_cord l;
    float tca;
    float d;
    float l_p1;

    l = rest_vec(sp.cord,ray->origin);
    tca = proy_vect(ray->direction, l);
    if (tca < 0)
        return -1;
    d = sqrt(prod_esc(l, l) - (tca * tca));
    if (d < 0 || d > sp.diameter / 2)
        return -1;
    l_p1 = tca - sqrt(pow(sp.diameter / 2, 2) - pow(d, 2));
    if (l_p1 < ray->len)
        ray->len = l_p1;
    return create_int_color(1, sp.rgb.r, sp.rgb.g, sp.rgb.b);
}

int spheres_intersection(t_ray *ray, t_list *list)
{
    t_sphere sphere;
    t_list *aux;
    int color;
    int color_aux;
    float len_aux;

    color = 0;
    sphere = *(t_sphere *)list->content;
    aux = list;
    while (aux->next)
    {
        len_aux = ray->len;
        sphere = *(t_sphere *)aux->content;
        if ((color_aux = get_sp_inter(ray, sphere)) >= 0 && ray->len < len_aux)
            color = color_aux;
        aux = aux->next;
    }
    len_aux = ray->len;
    sphere = *(t_sphere *)aux->content;
    if ((color_aux = get_sp_inter(ray, sphere)) >= 0 && ray->len < len_aux)
        color = color_aux;
    return (color);
}
