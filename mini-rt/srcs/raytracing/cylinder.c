/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:34:03 by pablo             #+#    #+#             */
/*   Updated: 2021/01/12 15:06:17 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_cy_inter(t_ray *ray, t_cylinder cy)
{
    float l;
    t_cord r_cy;
    t_cord norm;
    
    r_cy = rest_vec(ray->origin,cy.cord);
    norm = prod_vec(cy.norm_v, ray->direction);
    l = fabs(prod_esc(r_cy, norm));
    if (l <cy.diameter/2 )
    {
        ray->len = l;
        return 1;
    }
    return 0;
}

int cylinder_intersection(t_ray *ray, t_list *list, t_file c)
{
    t_cylinder cy;
    t_list *aux;
    int color;
    float len_aux;

    color = 0;
    cy = *(t_cylinder *)list->content;
    aux = list;
    while (aux->next)
    {
        len_aux = ray->len;
        cy = *(t_cylinder *)aux->content;
        if (get_cy_inter(ray, cy))
        {
            color = create_int_color(cy.rgb, c.ambient_ligth);
            printf("r:%d,g:%d,b:%d", cy.rgb.r, cy.rgb.g, cy.rgb.b);
        }
        aux = aux->next;
    }
    len_aux = ray->len;
    cy = *(t_cylinder *)aux->content;
    if (get_cy_inter(ray, cy))
    {
        color = create_int_color(cy.rgb, c.ambient_ligth);
        printf("r:%d,g:%d,b:%d", cy.rgb.r, cy.rgb.g, cy.rgb.b);
    }
    return (color);
}