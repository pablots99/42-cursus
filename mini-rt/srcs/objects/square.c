/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:06:52 by pablo             #+#    #+#             */
/*   Updated: 2021/01/15 17:24:31 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_sq_inter(t_ray *ray, t_square sq)
{
    float len;
    float i_to_center;

    len = prod_esc(rest_vec(sq.cord, ray->origin), sq.norm_v) /
          prod_esc(ray->direction, sq.norm_v);
    if (len <= 0)
        return (-1);
    i_to_center= fabs(mod_vec(rest_vec(sq.cord,ray_intersection(*ray,len))));
    if ( i_to_center < sq.side/2 && len < ray->len)
    {
        ray->len = len - 1;
        ray->normal = norm_vec(sum_vec(sum_vec(esc_dot_vec(ray->len,ray->direction),ray->origin),sq.norm_v));
    }
    return 1;
}


