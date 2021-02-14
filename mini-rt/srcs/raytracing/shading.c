/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:51:39 by pablo             #+#    #+#             */
/*   Updated: 2021/02/14 18:24:20 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

float calculate_specular(t_ray *ray, t_cord v)
{
	t_cord r;
	float spec;
	t_cord dir;

	if (ray->specular == 0 || BONUS == 0)
		return 0;
	dir = norm_vec(esc_dot_vec(-1, ray->direction));
	r = rest_vec(esc_dot_vec(2 * prod_esc(ray->normal, dir), ray->normal), dir);
	spec = pow(max_float(0, prod_esc(r, v)), 100);
	return (spec);
}
void get_point_to_ligth(t_ligth ligth, t_ray *pointo_ligth, t_ray *ray)
{
	t_cord vec_ligth;

	pointo_ligth->origin = ray_cut_point(*ray);
	vec_ligth = rest_vec(ligth.cord, pointo_ligth->origin);
	pointo_ligth->direction = norm_vec(vec_ligth);
	pointo_ligth->len = mod_vec(vec_ligth);
	pointo_ligth->normal = ray->normal;
	pointo_ligth->specular = ray->specular;
}

void reflection(t_file *c, t_ray *ray, t_shades *shades, int *color)
{
	t_ray reflected;
	int color_aux;

	color_aux = *color;
	reflected = reflected_ray(ray);
	if (BONUS == 1 && ray->reflexion > 0 && c->n_reflexions <  NREFLEXIONS)
	{
		c->n_reflexions++;
		*color = shading(&reflected, get_intersections(&reflected, c), c);
		*color = sum_int_colors(*color, color_aux);
	}
	shades->difuse = 0;
	shades->specular = 0;
	shades->ligth_color = (t_rgb){0, 0, 0};
	c->n_reflexions = 0;
}

int shading(t_ray *ray, int color, t_file *c)
{
	t_list *lst_ligth;
	t_ray pointo_ligth;
	t_shades shades;

	lst_ligth = c->ligth;
	reflection(c, ray, &shades, &color);
	while (lst_ligth)
	{
		shades.ligth = *((t_ligth *)lst_ligth->content);
		get_point_to_ligth(shades.ligth, &pointo_ligth, ray);
		if (get_shadow_intersections(pointo_ligth, *c) == 0)
		{
			shades.difuse += max_float(c->ambient_ligth.ratio,
									   (prod_esc(ray->normal, pointo_ligth.direction) * (shades.ligth.brigthness)));
			shades.specular += calculate_specular(&pointo_ligth, ray->direction);
		}
		else
			shades.difuse += c->ambient_ligth.ratio;
		shades.ligth_color = sum_colors(shades.ligth_color, shades.ligth.rgb);
		lst_ligth = lst_ligth->next;
	}
	color = create_shade_color2(rgb_from_int(color), shades);
	return (color);
}
