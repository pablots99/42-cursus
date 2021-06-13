/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 23:08:38 by pablo             #+#    #+#             */
/*   Updated: 2021/06/13 16:35:18 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/fractal.h"

double resize_value(double value, t_range initial, t_range new)
{
	double res;
	double range1;
	double range2;

	res = 0;
	range1 = initial.end - initial.start;
	range2 = new.end - new.start;
	res = new.start + (value - initial.start) * (range2) / (range1);
	return res;
}

int create_fractal(void *f)
{
	int x;
	int y;
	int aux_c;
	int z;
	t_threads *param;
	double x1;
	double y1;

	x1 = 0;
	y1 = 0;
	param = (t_threads *)f;
	y = (param->thread * (param->f->win_heigth / THREADS));
	while (y < (int)((param->thread + 1) * (param->f->win_heigth / THREADS)))
	{
		x = 0;
		while (x < param->f->win_width)
		{
			z = 0;
			//printf("start\n->");89
			x1 = resize_value(x, (t_range){0, param->f->win_width}, (t_range){-param->f->zoom + param->f->move_x, param->f->zoom + param->f->move_x});
			y1 = resize_value(y, (t_range){0, param->f->win_heigth}, (t_range){-param->f->zoom + param->f->move_y, param->f->zoom + param->f->move_y});

			double a1 = x1;
			double b1 = y1;
			while (z < param->f->precision)
			{
				double h1 = ((a1 * a1) - (b1 * b1)); //real number
				double h2 = (2 * a1 * b1);
				if(param->f->is_julia)
			{
				x1 = param->f->julia->x;
				y1 = param->f->julia->y;
			}	 //imaginary number
				a1 = h1 - x1;						 //x1 real plane values
				b1 = h2 - y1;						 //y1 imaginary plane values
				if (fabs(a1 + b1) > param->f->win_width * 4)
					break;
				z++;
			}
			//z /= 4;
			//printf("z:%d\n",z);
			my_mlx_pixel_put(&param->f->img, x, y, int_from_rgb(150, z, z));
			x++;
		}
		y++;
	}

	aux_c = 0;
	mlx_put_image_to_window(param->f->mlx_ptr, param->f->win_ptr, param->f->img.mlx_img, 0, 0);
	return 1;
}

int threads(t_fractal *c)
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
		params[i].f = c;
		err = pthread_create(&th[i], 0,
							 (void *)create_fractal, (void *)&(params[i]));
		if (err)
			return (printf("Thread Error: CAN NOT CREATE THREAD"));
		i++;
	}
	while (i-- > 0)
		err = pthread_join(th[i], 0);
	return (1);
}
int detect_key(int keycode, t_fractal *c)
{
	while (c->zoom + c->zoom_value > 0)
		c->zoom_value /= 10;

	if (keycode == 125)
		c->zoom -= c->zoom_value;
	if (keycode == 126)
		c->zoom += c->zoom_value;
	if (keycode == 13)
		c->move_y += c->zoom_value;
	if (keycode == 1)
		c->move_y -= c->zoom_value;
	if (keycode == 2)
		c->move_x += c->zoom_value;
	if (keycode == 0)
		c->move_x -= c->zoom_value;
	if (keycode == 30)
		c->precision *=2;
	if (keycode == 44)
		c->precision /=2;
	threads(c);
	return 1;
}

int mouse_actions(int button, int x, int y, t_fractal *f)
{


	while (f->zoom + f->zoom_value > 0)
		f->zoom_value /= 10;

	if (button == 4)
		f->zoom -= f->zoom_value;

	if (button == 5)
	{
		f->zoom += f->zoom_value;
		// if (x1 > f->move_x)
		// 	f->move_x += f->zoom_value;
		// if (x1 < f->move_x)
		// 	f->move_x -= f->zoom_value;

		// if (y1 > f->move_y)
		// 	f->move_y += f->zoom_value;
		// if (y1 < f->move_y)
		// 	f->move_y -= f->zoom_value;
	}
	if (button == 1 && !f->is_julia)
	{
		mlx_mouse_get_pos(f->win_ptr, &x, &y);
		double x1 = resize_value(x, (t_range){0, f->win_width}, (t_range){-f->zoom + f->move_x, f->zoom + f->move_x});
		double y1 = resize_value(y, (t_range){0, f->win_heigth}, (t_range){-f->zoom + f->move_y, f->zoom + f->move_y});
		f->is_julia = 1;
		f->julia->x  =x1;
		f->julia->y  =y1;
		f->julia->move_x = f->move_x;
		f->julia->move_y = f->move_y;
		f->julia->zoom = f->zoom;
		f->julia->zoom_value = f->zoom_value;
		f->move_x = 0;
		f->move_y = 0;
		f->zoom = -1;
		f->zoom_value = 0.1;
	}
	if (button == 2 && f->is_julia)
	{
		f->is_julia = 0;
		f->move_x = f->julia->move_x;
		f->move_y = f->julia->move_y;
		f->zoom = f->julia->zoom ;
		f->zoom_value = f->julia->zoom_value;
		f->julia->zoom_value = 0;
		f->julia->move_y = 0;
		f->julia->zoom = -1;
		f->julia->zoom_value = 0.1;
	}
	threads(f);
	return 1;
}

int init_window(t_fractal *f)
{

	printf("w:%d,h:%d\n", f->win_width, f->win_heigth);
	if (!(f->mlx_ptr = mlx_init()))
		return 1;
	if (!(f->win_ptr = mlx_new_window(f->mlx_ptr, f->win_width, f->win_heigth, "fractal")))
		return 1; //error
	f->img.mlx_img = mlx_new_image(f->mlx_ptr, f->win_width, f->win_heigth);
	f->img.address = mlx_get_data_addr(f->img.mlx_img, &f->img.bits_per_pixel, &f->img.line_length, &f->img.endian);
	mlx_hook(f->win_ptr, 17, 1L << 2, exit_win, f);
	f->zoom = -1;
	f->zoom_value = 0.1;
	f->is_julia = 0;
	f->precision = PRECISION;
	//fill image
	threads(f);
	mlx_hook(f->win_ptr, 2, 1L << 0, detect_key, f);
	mlx_mouse_hook(f->win_ptr, mouse_actions, f);
	mlx_loop_hook(f->win_ptr, threads, f);
	mlx_loop(f->mlx_ptr);

	return (0);
}

int main()
{
	t_fractal f;
	int err;
	t_julia jul;

	err = 0;
	f.move_x = 0;
	f.move_y = 0;
	ft_bzero(&f, sizeof(t_fractal));
	ft_bzero(&jul, sizeof(t_julia));
		f.julia = &jul;

	f.win_heigth = 500;
	f.win_width = 500;
	err = init_window(&f);
	if (err)
		return printf("error creating window");
	return 0;
}
