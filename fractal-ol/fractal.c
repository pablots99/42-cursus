/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 23:08:38 by pablo             #+#    #+#             */
/*   Updated: 2021/06/20 02:11:30 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/fractal.h"

int	calculate_z(t_fractal f, double x1, double y1)
{
	int		z;
	double	h1;
	double	h2;
	double	a1;
	double	b1;

	z = 0;
	a1 = x1;
	b1 = y1;
	while (z < f.precision && fabs(a1 + b1) < 30)
	{
		h1 = ((a1 * a1) - (b1 * b1));
		 h2 = (2 * a1 * b1);
		if (f.is_julia || f.is_fullJulia)
		{
			x1 = f.julia->x;
			y1 = f.julia->y;
		}
		a1 = h1 - x1;
		b1 = h2 - y1;
		z++;
	}
	return (z);
}

int	create_fractal(void *f)
{
	int			x;
	int			y;
	t_threads	*param;
	double		x1;
	double		y1;

	param = (t_threads *)f;
	y = (param->thread * (param->f->win_heigth / THREADS));
	while (y < (int)((param->thread + 1) * (param->f->win_heigth / THREADS)))
	{
		x = 0;
		while (x < param->f->win_width)
		{
			x1 = norme_x1(*param->f, x);
			y1 = norme_y1(*param->f, y);
			my_mlx_pixel_put(&param->f->img, x, y,
				get_color(*param->f, calculate_z(*param->f, x1, y1)));
			x++;
		}
		y++;
	}
	return (1);
}

int	threads(t_fractal *c)
{
	int			i;
	int			err;
	t_threads	params[THREADS];
	pthread_t	th[THREADS];

	i = 0;
	mlx_clear_window(c->mlx_ptr, c->win_ptr);
	while (i < THREADS)
	{
		params[i].thread = i;
		params[i].f = c;
		err = pthread_create(&th[i], 0,
				(void *)create_fractal, (void *)&(params[i]));
		if (err)
			return (printf("Thread Error: CAN NOT CREATE THREAD"));
		i++;
	}
	while (i-- > 0)
		err = pthread_join(th[i], 0);
	mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img.mlx_img, 0, 0);
	return (1);
}

int	init_window(t_fractal *f)
{
	f->mlx_ptr = mlx_init();
	if (!(f->mlx_ptr))
		return (1);
	f->win_ptr = mlx_new_window(f->mlx_ptr,
			f->win_width, f->win_heigth, "fractal");
	if (!(f->win_ptr))
		return (1);
	f->img.mlx_img = mlx_new_image(f->mlx_ptr, f->win_width, f->win_heigth);
	f->img.address = mlx_get_data_addr(f->img.mlx_img,
			&f->img.bits_per_pixel, &f->img.line_length, &f->img.endian);
	mlx_hook(f->win_ptr, 17, 1L << 2, exit_win, f);
	f->zoom = -1;
	f->zoom_value = 0.1;
	f->is_julia = 0;
	f->precision = PRECISION;
	threads(f);
	mlx_hook(f->win_ptr, 2, 1L << 0, detect_key, f);
	mlx_mouse_hook(f->win_ptr, mouse_actions, f);
	mlx_loop_hook(f->win_ptr, threads, f);
	mlx_loop(f->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	f;
	int			err;
	t_julia		jul;

		ft_bzero(&f, sizeof(t_fractal));
	ft_bzero(&jul, sizeof(t_julia));
	f.julia = &jul;
	if(argc < 2 || !valid_parameters(argv[1],&f))
		return help();
	err = 0;
	f.move_x = 0;
	f.move_y = 0;

	f.win_heigth = 1000;
	f.win_width = 1000;
	err = init_window(&f);
	if (err)
	{
		printf("error creating window");
		return (1);
	}
	return (0);
}
