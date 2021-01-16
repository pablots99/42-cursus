/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:34:03 by pablo             #+#    #+#             */
/*   Updated: 2021/01/16 01:08:12 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

//cambiar
int get_dyscs_inter(t_ray *ray, t_cylinder cy)
{
    float len;
    float i_to_center;
    t_cord normal;

    len = prod_esc(rest_vec(cy.cord, ray->origin), cy.norm_v) /
          prod_esc(ray->direction, cy.norm_v);
    i_to_center = fabs(mod_vec(rest_vec(cy.cord, ray_intersection(*ray, len))));
    normal = norm_vec(esc_dot_vec(-1, cy.norm_v));
    if (len < 0 || i_to_center > cy.diameter / 2)
    {
        len = prod_esc(rest_vec(sum_vec(cy.cord, esc_dot_vec(cy.height, cy.norm_v)),
                 ray->origin),cy.norm_v) / prod_esc(ray->direction, cy.norm_v);
        i_to_center = fabs(mod_vec(rest_vec(sum_vec(cy.cord,
            esc_dot_vec(cy.height, cy.norm_v)),ray_intersection(*ray, len))));
        normal = cy.norm_v;
    }
    if (len >= 0 && i_to_center <= cy.diameter / 2 && len < ray->len)
    {
        ray->len = len - 1;
        ray->normal = norm_vec(normal);
        return 1;
    }
    return -1;
}

int get_cy_inter(t_ray *ray, t_cylinder cy)
{
    float l;
    t_cord h;
    t_cord w;
    t_cord ec;
    float proy;

    h = norm_vec(rest_vec(sum_vec(esc_dot_vec(cy.height, cy.norm_v), cy.cord), cy.cord));
    w = rest_vec(ray->origin, cy.cord);
    ec.x = prod_esc(ray->direction, ray->direction) - pow(prod_esc(ray->direction, h), 2);
    ec.y = 2 * (prod_esc(ray->direction, w) - (prod_esc(ray->direction, h) * prod_esc(w, h)));
    ec.z = prod_esc(w, w) - pow(prod_esc(w, h), 2) - pow(cy.diameter / 2, 2);
    l = pow(ec.y, 2) - (4 * ec.x * ec.z);
    if (l > 0)
    {
        l = ((((ec.y * -1) - sqrt(l)) / (2 * ec.x)) > ((((ec.y * -1) + sqrt(l)) / (2 * ec.x)))) ? (((ec.y * -1) + sqrt(l)) / (2 * ec.x)) : (((ec.y * -1) - sqrt(l)) / (2 * ec.x));
        proy = fabs(prod_esc(rest_vec(ray_intersection(*ray, l), cy.cord), h));
        if (l > 0 && l < ray->len && proy <= cy.height && proy >= 0)
        {
            //ray->normal = 
            ray->len = l - 0.001;
            return (1);
        }
    }
    if (get_dyscs_inter(ray, cy))
        return (1);
    return (-1);
}
