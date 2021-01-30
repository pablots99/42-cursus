/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:51:39 by pablo             #+#    #+#             */
/*   Updated: 2021/01/30 16:09:26 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

float calculate_specular(t_ray *ray, t_cord v)
{
	t_cord r;
	float spec;
	t_cord dir;

	dir = norm_vec(esc_dot_vec(-1, ray->direction));
	r = rest_vec(esc_dot_vec(2 * prod_esc(ray->normal, dir), ray->normal), dir);
	spec = pow(max_float(0,prod_esc(r, v)), 100);
	return (spec);
}

int shading(t_ray *ray, int color, t_file *c)
{
	t_cord vec_ligth;
	t_ray pointo_ligth;
	t_ligth ligth;
	float brigth;
	t_list *aux;
	t_ray reflected;
	int color_aux;
	
	reflected = refracted_ray(ray);
	color_aux = color;
	aux = c->ligth;
	brigth = 1;
    if (ray->reflexion > 0)
	{
		c->n_reflexions++;
		color = shading(&reflected, get_intersections(&reflected, c), c);
		color = sum_int_colors(color, color_aux);
		//return sum_int_colors(color_aux,shading(&reflected, get_intersections(&reflected, c), c));
	}
	c->n_reflexions = 0;
	while (aux)
	{
		ligth = *((t_ligth *)aux->content);
		pointo_ligth.origin = ray_cut_point(*ray);
		vec_ligth = rest_vec(ligth.cord, pointo_ligth.origin);
		pointo_ligth.direction = norm_vec(vec_ligth);
		pointo_ligth.len = mod_vec(vec_ligth);
		pointo_ligth.normal = ray->normal;
		if (get_shadow_intersections(pointo_ligth, *c) != 0)
			brigth = c->ambient_ligth.ratio;
		else 
			brigth = max_float(c->ambient_ligth.ratio,brigth* (prod_esc(ray->normal, norm_vec(vec_ligth)) * (ligth.brigthness + 0.01)));
			//especular se ve en la sombra
			color = create_shade_color(rgb_from_int(color), ligth, brigth, calculate_specular(&pointo_ligth, ray->direction));
		aux = aux->next;
	}
	return (color);
}