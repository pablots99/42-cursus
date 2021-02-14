/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:28:06 by pablo             #+#    #+#             */
/*   Updated: 2021/02/14 23:37:48 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"


int get_cu_inter(t_ray *ray, t_cube cu)
{
    int cond;

    cond = 0;
    cond += get_sq_inter(ray,&cu.face1);
    cond += get_sq_inter(ray,&cu.face2);
    // cond += get_sq_inter(ray,&cu.face3);
    // cond += get_sq_inter(ray,&cu.face4);
    // cond += get_sq_inter(ray,&cu.face5);
    // cond += get_sq_inter(ray,&cu.face6);

    if(cond > -2)
        return 1;
    return 0;
}