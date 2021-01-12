/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:51:00 by pablo             #+#    #+#             */
/*   Updated: 2021/01/10 16:52:16 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_sp_inter(t_ray *ray, t_sphere sp)
{
    t_cord l;
    float tca;
    float d;
    float l_p1;

    l = rest_vec(sp.cord, ray->origin);
    tca = proy_vect(ray->direction, l);
    if (tca < 0)
        return( -1);
    d = sqrt(prod_esc(l, l) - (tca * tca));
    if (d < 0 || d > sp.diameter / 2)
        return (-1);
    l_p1 = tca - sqrt(pow(sp.diameter / 2, 2) - pow(d, 2));
    if (l_p1 < ray->len)
    {
        ray->len = l_p1 - 1;
        ray->normal = norm_vec(rest_vec(esc_dot_vec(l_p1,ray->direction),sp.cord));//puede haber error
    }
    return (1);
}

int spheres_intersection(t_ray *ray, t_list *list, t_file c)
{
    t_sphere sp;
    t_list *aux;
    int color;
    float len_aux;

    color = 0;
    sp = *(t_sphere *)list->content;
    aux = list;
    while (aux->next)
    {
        len_aux = ray->len;
        sp = *(t_sphere *)aux->content;
        if (get_sp_inter(ray, sp) && ray->len < len_aux)
            color = create_int_color(sp.rgb,c.ambient_ligth);
        aux = aux->next;
    }
    len_aux = ray->len;
    sp = *(t_sphere *)aux->content;
    if (get_sp_inter(ray, sp) && ray->len < len_aux)
        color = create_int_color(sp.rgb,c.ambient_ligth);
    return (color);
}
