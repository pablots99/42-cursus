/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:14:12 by pablo             #+#    #+#             */
/*   Updated: 2021/01/29 18:10:47 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/mini_rt.h"

int threats(t_file *c, int save)
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

void paint_scene(void *a)
{
	int y;
	int x;
	t_ray ray;
	t_threads *param;
	int color;

	param = (t_threads *)a;
	color = 0;
	y = (param->thread * (param->c->win_heigth / THREADS));
	while (y < (param->thread + 1) * (param->c->win_heigth / THREADS))
	{
		x = 0;
		while (x < param->c->win_width)
		{
			ray = generate_ray(x, y, *param->c);
			color = get_intersections(&ray, param->c);
			if (param->c->ligth)
				color = shading(&ray, color, param->c);
			my_mlx_pixel_put(&param->c->img, x, y, color);
			x++;
		}
		//ft_printf("\rLoading%d: %d%%", c->thread, y / (c->win_heigth / 100));
		y++;
	}
	pthread_exit(0);
}

int init_window(t_file *c, int save)
{
	printf("inti:%d", save);

	adjust_res(c);
	if (!(c->win_ptr = mlx_new_window(c->mlx_ptr, c->win_width, c->win_heigth, "MiniRt")))
		return parse_error("Minilibx Error: CAN NOT OPEN A WINDOW");
	mlx_hook(c->win_ptr, 2, 1L << 0, exit_win, c);
	mlx_hook(c->win_ptr, 17, 1L << 2, exit_win2, c);
	mlx_key_hook(c->win_ptr, detect_key, c);
	c->img.mlx_img = mlx_new_image(c->mlx_ptr, c->win_width, c->win_heigth);
	c->img.address = mlx_get_data_addr(c->img.mlx_img, &c->img.bits_per_pixel,
						     &c->img.line_length, &c->img.endian);
	threats(c, save);
	mlx_loop(c->mlx_ptr);
	return 0;
}

int main(int argc, char **argv)
{
	t_file config;
	int save;

	save = 0;
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		save = 1;
	if (argc == 2 || (argc == 3 & save == 1))
	{
		ft_bzero(&config, sizeof(t_file));
		if (read_rt_file(argv[1], &config))
			init_window(&config, save);
	}
	else
	{
		ft_printf("Error: Parameters");
		return 0;
	}
	free_config(&config);
	ft_printf("\n\n\n\n------------------LEAKS---------------------------------------\n");
	system("leaks minirt");
	ft_printf("--------------------------------------------------------\n");
	return 0;
}
