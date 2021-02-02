/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:01:00 by ptorres           #+#    #+#             */
/*   Updated: 2021/02/02 19:12:17 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"


int cube_intersection(t_ray *ray, t_list *list)
{
    t_cube cu;
    t_list *aux;
    int color;
    float len_aux;

    color = 0;
    cu = *(t_cube *)list->content;
    aux = list;
    while (aux)
    {
        len_aux = ray->len;
        cu = *(t_cube *)aux->content;
        if (get_cu_inter(ray, cu.faces) && ray->len < len_aux)
        {
            color = int_from_rgb(cu.rgb.r,cu.rgb.g,cu.rgb.b);
            ray->object = CUBE;
            ray->reflexion = cu.reflexion;
        }
        aux = aux->next;
    }
    return (color);
}