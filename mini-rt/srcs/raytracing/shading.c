/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:51:39 by pablo             #+#    #+#             */
/*   Updated: 2021/01/25 18:41:43 by ptorres          ###   ########.fr       */
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
	spec = pow(prod_esc(r, v), 100);

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

	color_aux = int_from_rgb(0,0,0);
	reflected = refracted_ray(ray);
	if (ray->reflexion > 0)
		return shading(&reflected, get_intersections(&reflected, c), c);
	aux = c->ligth;
	while (aux)
	{
		ligth = *((t_ligth *)aux->content);
		pointo_ligth.origin = ray_cut_point(*ray);
		vec_ligth = rest_vec(ligth.cord, pointo_ligth.origin);
		pointo_ligth.direction = norm_vec(vec_ligth);
		pointo_ligth.len = mod_vec(vec_ligth);
		pointo_ligth.normal = ray->normal;
		//botleneck!! en cuanto hay interseccion tiene que devolver sombre
		if (get_intersections(&pointo_ligth, c))
			return (ambient_color(rgb_from_int(color), c->ambient_ligth));
		brigth = max_float(c->ambient_ligth.ratio, (prod_esc(ray->normal, norm_vec(vec_ligth)) * (ligth.brigthness)));
		color = create_shade_color(rgb_from_int(color), ligth, brigth, calculate_specular(&pointo_ligth, ray->direction));
		aux = aux->next;
	}
	return (color);
}