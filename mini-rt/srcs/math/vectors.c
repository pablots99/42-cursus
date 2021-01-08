/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:45:28 by pablo             #+#    #+#             */
/*   Updated: 2021/01/08 12:37:30 by pablo            ###   ########.fr       */
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

	vec.x = v1.y * v2.z - v1.z * v2.y;
	vec.y = v1.z * v2.x - v1.x * v2.z;
	vec.z = v1.x * v2.y - v1.y * v2.x;
	return (vec);
}
t_cord esc_dot_vec(float num, t_cord c)
{
	t_cord vec;

	vec.x = c.x * num;
	vec.y = c.y * num;
	vec.z = c.z * num;
	return (vec);
}

t_cord sum_vec(t_cord v1, t_cord v2)
{
	t_cord vec;
	vec.x = v1.x + v2.x;
	vec.y = v1.y + v2.y;
	vec.z = v1.z + v2.z;
	return (vec);
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

float rad_ang_vec(t_cord v1, t_cord v2)
{
	return (acos(prod_esc(v1, v2) / (mod_vec(v1) * mod_vec(v2))) * M_PI / 180);
}

t_cord vector_dot_matrix(t_cord v, t_matrix matrix)
{
	t_cord vec;

	vec.x = prod_esc(v,matrix.v1);
	vec.y = prod_esc(v,matrix.v2);
	vec.z = prod_esc(v,matrix.v3);
	return (vec);
}

float mod_vec(t_cord vec)
{
	return (sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2)));
}