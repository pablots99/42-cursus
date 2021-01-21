/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:06:16 by pablo             #+#    #+#             */
/*   Updated: 2021/01/21 22:44:04 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_tr_inter(t_ray *ray, t_triangle tr)
{
    float len;
    float den;
    t_cord ab;
    t_cord normal;
    t_cord p;

    normal = norm_vec(prod_vec((rest_vec(tr.cord_2, tr.cord_3)),
                               (rest_vec(tr.cord_3, tr.cord_1))));
    den = prod_esc(ray->direction, normal);
    if (fabs(den) > 0)
    {
        if ((len = prod_esc(rest_vec(tr.cord_1, ray->origin), normal) / den) >= 0)
        {
            p = ray_intersection(*ray, len);
            ab = barycentric_cords(tr, p);
            if (len < ray->len && (ab.x <= 1 && ab.x >= 0) &&
                (ab.y <= 1 && ab.y >= 0) &&  (ab.z <= 1 && ab.z >= 0))
            {
                ray->normal = norm_vec(sum_vec(p, normal));
                ray->len = len - 1;
                return 1;
            }
        }
    }
    return -1;
}
