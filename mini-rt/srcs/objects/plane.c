/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:57:32 by pablo             #+#    #+#             */
/*   Updated: 2021/01/15 22:16:06 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_pl_inter(t_ray *ray, t_plane pl)
{
    float len;
    float den;

    den = prod_esc(ray->direction, pl.norm_v);
    if (fabs(den) > 0)
    {
        len = prod_esc(rest_vec(pl.cord,ray->origin),pl.norm_v) /den;
        if (len < ray->len && len >= 0)
        {
            ray->len = len - 1;
            ray->normal = norm_vec(sum_vec(sum_vec(esc_dot_vec(ray->len, ray->direction), ray->origin), pl.norm_v));
            return 1;
        }
    }
    return -1;
}
