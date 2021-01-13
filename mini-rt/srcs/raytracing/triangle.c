/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:06:16 by pablo             #+#    #+#             */
/*   Updated: 2021/01/13 13:47:25 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_tr_inter(t_ray *ray, t_triangle tr)
{
    float len;
    t_cord ab;
    t_cord normal;
    t_cord p;

    normal = norm_vec(prod_vec((rest_vec(tr.cord_2, tr.cord_1)),
                               (rest_vec(tr.cord_3, tr.cord_1))));
    len = prod_esc(rest_vec(tr.cord_1, ray->origin), normal) /
          prod_esc(ray->direction, normal);
    if (len <= 0)
        return (-1);
    p = ray_intersection(*ray,len);
    ab = barycentric_cords(tr,p);
    if (len < ray->len && (ab.x <= 1 && ab.x >= 0) &&
        (ab.y <= 1 && ab.y >= 0))
    {
        ray->normal = sum_vec(p,normal);
        ray->len = len - 1;
    }
    return -1;
}

int triangle_intersection(t_ray *ray, t_list *plane, t_file c)
{
    t_triangle tr;
    t_list *aux;
    int color;
    float len_aux;

    color = 0;
    tr = *(t_triangle *)plane->content;
    aux = plane;
    while (aux->next)
    {
        len_aux = ray->len;
        tr = *(t_triangle *)aux->content;
        if (get_tr_inter(ray, tr) && ray->len < len_aux)
            color = create_int_color(tr.rgb, c.ambient_ligth);
        aux = aux->next;
    }
    len_aux = ray->len;
    tr = *(t_triangle *)aux->content;
    if (get_tr_inter(ray, tr) && ray->len < len_aux)
        color = create_int_color(tr.rgb, c.ambient_ligth);
    aux = aux->next;
    return color;
}