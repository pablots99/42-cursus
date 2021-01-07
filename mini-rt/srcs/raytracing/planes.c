/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:57:32 by pablo             #+#    #+#             */
/*   Updated: 2021/01/07 17:04:54 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"


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
             aux = aux->next;
    }



}
