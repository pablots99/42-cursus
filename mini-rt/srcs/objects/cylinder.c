/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:34:03 by pablo             #+#    #+#             */
/*   Updated: 2021/01/24 19:23:41 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_dyscs_inter1(t_ray *ray, t_cylinder cy)
{
    float len;
    float i_to_center;
    float den;

    den = prod_esc(ray->direction, cy.norm_v);
    if (fabs(den) > 0)
    {
        len = prod_esc(rest_vec(cy.cord, ray->origin), cy.norm_v) / den;
        i_to_center = fabs(mod_vec(rest_vec(cy.cord, ray_intersection(*ray, len))));
        if (len >= 0 && i_to_center <= (cy.diameter / 2) && len < ray->len)
        {
            ray->len = len - BIAS;
            ray->normal =  norm_vec(esc_dot_vec(-1,cy.norm_v));
            return 1;
        }
    }
    return -1;
}
int get_dyscs_inter2(t_ray *ray, t_cylinder cy)
{
    float len;
    float i_to_center;
    t_cord p;
    float den;

    p = sum_vec(esc_dot_vec(cy.height, cy.norm_v), cy.cord);
    den = prod_esc(ray->direction, cy.norm_v);
    if (fabs(den) > 0)
    {
        len = prod_esc(rest_vec(p, ray->origin), cy.norm_v) / den;
        i_to_center = fabs(mod_vec(rest_vec(p, ray_intersection(*ray, len))));
        if (len >= 0 && i_to_center <= (cy.diameter / 2) && len < ray->len)
        {
            ray->len = len - BIAS;
            ray->normal = norm_vec(esc_dot_vec(1,cy.norm_v));
            return 1;
        }
    }
    return -1;
}
float t_inter(t_ray *ray, float t1, float t2)
{
    if (t1 >= 0 && ray->len > t1)
        return (t1);
    else if (t2 >= 0 && ray->len > t2)
        return (t2);
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
    h.x = get_dyscs_inter1(ray, cy);
    h.x =  get_dyscs_inter2(ray, cy);
    l = pow(ec.y, 2) - (4 * ec.x * ec.z);
    l = min_float((-ec.y - sqrt(l)) / (2 * ec.x), (-ec.y + sqrt(l)) / (2 * ec.x));
    proy = prod_esc(rest_vec(ray_intersection(*ray, l), cy.cord), cy.norm_v);
    if (l > 0 && l < ray->len && proy >= 0 && proy <= cy.height)
    {
        ray->normal = norm_vec(rest_vec(ray_intersection(*ray, l),sum_vec(esc_dot_vec(proy,cy.norm_v),cy.cord)));
        ray->len = l - BIAS;
        return (1);
    }
    if(h.x == 1)
        return 1;
    return (-1);
}
