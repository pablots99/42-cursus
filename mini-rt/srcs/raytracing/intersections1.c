/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:01:00 by ptorres           #+#    #+#             */
/*   Updated: 2021/02/14 23:20:29 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"


int pyramid_intersection(t_ray *ray, t_list *list)
{
    t_pyramid py;
    t_list *aux;
    int color;
    float len_aux;

    color = 0;
    py = *(t_pyramid *)list->content;
    aux = list;
    while (aux)
    {
        len_aux = ray->len;
        py = *(t_pyramid *)aux->content;
        if (get_py_inter(ray, py) && ray->len < len_aux)
        {
            color = int_from_rgb(py.rgb.r,py.rgb.g,py.rgb.b);
            ray->object = PYRAMID;
            ray->reflexion = py.reflexion;
            ray->specular = py.specular;
        }
        aux = aux->next;
    }
    return (color);
}
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
        if (get_cu_inter(ray, cu) && ray->len < len_aux)
        {
            color = int_from_rgb(cu.rgb.r,cu.rgb.g,cu.rgb.b);
            ray->object = PYRAMID;
            ray->reflexion = cu.reflexion;
            ray->specular = cu.specular;
        }
        aux = aux->next;
    }
    return (color);
}