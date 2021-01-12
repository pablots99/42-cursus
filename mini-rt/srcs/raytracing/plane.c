/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:57:32 by pablo             #+#    #+#             */
/*   Updated: 2021/01/12 15:11:34 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_pl_inter(t_ray *ray, t_plane pl)
{
    float len;

    len = prod_esc(rest_vec(pl.cord, ray->origin), pl.norm_v) /
          prod_esc(ray->direction, pl.norm_v);
    if (len <= 0)
        return (-1);
    if (len < ray->len)
    {
        ray->len = len -1;
        ray->normal = norm_vec(sum_vec(sum_vec(esc_dot_vec(ray->len,ray->direction),ray->origin),pl.norm_v));
    }
    return 1;
}

int plane_intersection(t_ray *ray, t_list *plane,t_file c)
{
    t_plane pl;
    t_list *aux;
    int color;
    float len_aux;

    color = 0;
    pl = *(t_plane *)plane->content;
    aux = plane;
    while (aux->next)
    {
        len_aux = ray->len;
        pl = *(t_plane *)aux->content;
        if (get_pl_inter(ray, pl) && ray->len < len_aux)
            color = create_int_color(pl.rgb,c.ambient_ligth);
        aux = aux->next;
    }
    len_aux = ray->len;
    pl = *(t_plane *)aux->content;
   if (get_pl_inter(ray, pl) && ray->len < len_aux)
            color = create_int_color(pl.rgb,c.ambient_ligth);
    aux = aux->next;
    return color;
}
