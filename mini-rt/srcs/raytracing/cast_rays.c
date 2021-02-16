/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 12:16:02 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 15:59:15 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_ray	generate_ray(int x, int y, t_file c, float r1[2])
{
	t_ray		ray;
	t_camera	camera;

	camera = *((t_camera *)c.camera->content);
	ray.origin = camera.cord;
	ray.direction.x = (2 * (((float)x + r1[0]) / (float)c.win_width) - 1)
		* tan((camera.fov * (M_PI / 180) / 2)) * c.aspect_ratio;
	ray.direction.y = (1 - 2 * ((float)y + r1[1]) / ((float)c.win_heigth))
		* tan((camera.fov * (M_PI / 180) / 2));
	ray.direction.z = -1;
	ray.reflexion = 0;
	ray.direction = norm_vec(vector_dot_matrix(norm_vec(ray.direction),
		camera.canvas.matrix));
	ray.len = INFINITY;
	ray.normal = vector(0, 0, 0);
	return (ray);
}

int		get_intersections(t_ray *ray, t_file *c)
{
	int		color;
	int		color_aux;
	float	len;

	color = 0;
	len = ray->len;
	if (c->sphere && (color_aux = spheres_intersection(ray, c->sphere, c)))
		color = color_aux;
	if (c->plane && (color_aux = plane_intersection(ray, c->plane)))
		color = color_aux;
	if (c->cylinder && (color_aux = cylinder_intersection(ray, c->cylinder)))
		color = color_aux;
	if (c->square && (color_aux = square_intersection(ray, c->square)))
		color = color_aux;
	if (c->triangle && (color_aux = triangle_intersection(ray, c->triangle)))
		color = color_aux;
	if (c->square && (color_aux = square_intersection(ray, c->square)))
		color = color_aux;
	if (c->pyramid && (color_aux = pyramid_intersection(ray, c->pyramid)))
		color = color_aux;
	if (c->cube && (color_aux = cube_intersection(ray, c->cube)))
		color = color_aux;
	return (color);
}

int		get_shadow_intersections(t_ray ray, t_file c)
{
	ray.object = 0;
	if (c.sphere && (spheres_intersection(&ray, c.sphere, &c)))
		return (1);
	if (c.plane && (plane_intersection(&ray, c.plane)))
		return (1);
	if (c.cylinder && (cylinder_intersection(&ray, c.cylinder)))
		return (1);
	if (c.square && (square_intersection(&ray, c.square)))
		return (1);
	if (c.triangle && (triangle_intersection(&ray, c.triangle)))
		return (1);
	if (c.square && (square_intersection(&ray, c.square)))
		return (1);
	if (c.pyramid && (pyramid_intersection(&ray, c.pyramid)))
		return (1);
	if (c.cube && (cube_intersection(&ray, c.cube)))
		return (1);
	if (ray.object == 0)
		return (0);
	else
		return (1);
}
