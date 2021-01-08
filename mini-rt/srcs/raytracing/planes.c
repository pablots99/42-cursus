/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:57:32 by pablo             #+#    #+#             */
/*   Updated: 2021/01/07 19:05:37 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_pl_inter(t_ray *ray, t_plane pl)
{
    float len;

    len = prod_esc(points_vec(pl.cord, ray->origin), pl.norm_v) /
          prod_esc(ray->direction, pl.norm_v);
    if (len < 0)
        return (-1);
    if (len < ray->len)
        ray->len = len;
    return create_int_color(1, pl.rgb.r, pl.rgb.g, pl.rgb.b);
}

int plane_intersection(t_ray *ray, t_list *plane)
{
    t_plane pl;
    t_list *aux;
    int color;
    int color_aux;
    float len_aux;

    color = 0;
    pl = *(t_plane *)plane->content;
    aux = plane;
    while (aux->next)
    {
        len_aux = ray->len;
        pl = *(t_plane *)aux->content;
        if ((color_aux = get_pl_inter(ray, pl)) >= 0 && ray->len < len_aux)
            color = color_aux;
        aux = aux->next;
    }
    len_aux = ray->len;
    pl = *(t_plane *)aux->content;
    if ((color_aux = get_pl_inter(ray, pl)) >= 0 && ray->len < len_aux)
        color = color_aux;
    aux = aux->next;
    return color;
}
