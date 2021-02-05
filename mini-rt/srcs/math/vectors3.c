/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:22:24 by pablo             #+#    #+#             */
/*   Updated: 2021/02/04 17:22:35 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"


t_cord sum_vec(t_cord v1, t_cord v2)
{
	t_cord vec;
	vec.x = v1.x + v2.x;
	vec.y = v1.y + v2.y;
	vec.z = v1.z + v2.z;
	return (vec);
}
void sum_vec2(float num, float *x, float *y, float *z)
{
	*x += num;
	*y += num;
	*z += num;
}
t_cord rest_vec(t_cord v1, t_cord v2)
{
	t_cord vec;
	vec.x = v1.x - v2.x;
	vec.y = v1.y - v2.y;
	vec.z = v1.z - v2.z;
	return (vec);
}

float prod_esc(t_cord v1, t_cord v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

float proy_vect(t_cord v1, t_cord v2)
{
	return (prod_esc(v1, v2) / mod_vec(v1));
}

