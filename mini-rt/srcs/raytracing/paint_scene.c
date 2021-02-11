/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:10:37 by pablo             #+#    #+#             */
/*   Updated: 2021/02/11 22:44:17 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int		threats(t_file *c, int save)
{
	int i;
	int err;
	t_threads params[THREADS];
	pthread_t th[THREADS];

	i = 0;
	mlx_clear_window(c->mlx_ptr, c->win_ptr);
	while (i < THREADS)
	{
		params[i].thread = i;
		params[i].c = c;
		err = pthread_create(&th[i], 0, (void *)paint_scene, (void *)&(params[i]));
		if (err)
			return parse_error("Thread Error: CAN NOT CREATE THREAD");
		i++;
	}
	 while (i-- > 0)
	 	err = pthread_join(th[i], 0);
	if (save == 0)
		mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img.mlx_img, 0, 0);
	else
	{
		create_bmp_file(c, "imagen.bmp");
		free_config(c);
		exit(0);
	}
	return 1;
}

void	init_int_arr(int *color, int n)
{
	int i;

	i = 0;
	while (i < n && color[i])
	{
		color[i] = 0;
		i++;
	}
}

void	get_color(t_rgb h, t_threads *param, int *color)
{
	t_ray ray;
	float rand1;
	float rand2;

	if (h.b == 1)
		ray = generate_ray(h.g, h.r, *param->c, 0.2, 0.2);
	else if (h.b == 2)
		ray = generate_ray(h.g, h.r, *param->c, 0.8, 0.8);
	else if (h.b == 3)
		ray = generate_ray(h.g, h.r, *param->c, 0.8, 0.2);
	else if (h.b == 4)
		ray = generate_ray(h.g, h.r, *param->c, 0.2, 0.8);
	else if (h.b == 0)
		ray = generate_ray(h.g, h.r, *param->c, 0.5, 0.5);
	else
		ray = generate_ray(h.g, h.r, *param->c, rand_unit_float(), rand_unit_float());
	*color = get_intersections(&ray, param->c);
	if (param->c->ligth)
		*color = shading(&ray, *color, param->c);
	else
		*color = ambient_color(rgb_from_int(*color), param->c->ambient_ligth);
}

void	paint_scene(void *a)
{
	t_rgb h;
	t_ray ray;
	t_threads *param;
	int color[ANTIALIASING];

	param = (t_threads *)a;
	init_int_arr(color, ANTIALIASING);
	h.r = (param->thread * (param->c->win_heigth / THREADS));
	while (h.r < (param->thread + 1) * (param->c->win_heigth / THREADS))
	{
		h.g = 0;
		while (h.g < param->c->win_width)
		{
			h.b = 0;
			while (h.b < ANTIALIASING)
			{
				get_color(h, param, &color[h.b]);
				h.b++;
			}
			color[0] = average_color(color, ANTIALIASING);
			my_mlx_pixel_put(&param->c->img, h.g, h.r, color[0]);
			h.g++;
		}
		h.r++;
	}
	pthread_exit(0);
}
