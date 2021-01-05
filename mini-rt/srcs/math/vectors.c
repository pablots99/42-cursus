/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:45:28 by pablo             #+#    #+#             */
/*   Updated: 2021/01/05 18:22:43 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_cord norm_vec(t_cord vec)
{
    t_cord norm_vec;
    float l;
    
    l = mod_vec(vec);
    norm_vec.x = vec.x / l;
    norm_vec.y = vec.y / l;
    norm_vec.z = vec.z / l;
    return (norm_vec);
}

t_cord prod_vec(t_cord v1, t_cord v2)
{

	t_cord vec;
	vec.x = v1.y*v2.z-v1.z*v2.y;
	vec.y = v1.z*v2.x-v1.x*v2.z;
	vec.z = v1.x*v2.y-v1.y*v2.x;
	return (vec);
}


float mod_vec(t_cord vec)
{
	float l;

	l = sqrt(pow(vec.x,2) + pow(vec.y,2) + pow(vec.z,2));
	return (l);
}