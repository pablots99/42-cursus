/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 23:08:38 by pablo             #+#    #+#             */
/*   Updated: 2021/06/04 17:43:36 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/fractal.h"

double resize_value(double value,t_range initial,t_range new)
{
	double res;
	double range1;
	double range2;

	res = 0;
	range1 = initial.end -initial.start;
	range2 = new.end -new.start;


	return res;
}

int		create_fractal(t_fractal *f)
{
	int x;
	int y;
	int aux_c;
	int z;

	aux_c = 0 ;
	y = 0;
	resize_value(100,(t_range){0,100},(t_range){0,1});
	while(y < f->win_heigth)
	{
		x = 0;
		while(x < f->win_width)
		{
			z = 0;
			//printf("start\n->");
			double x1 = (5 * (((float)x / (double)f->win_width) - 1));
			double y1 = (1- 5 * (((float)y / (double)f->win_heigth)));


			double a1 = x1;
			double b1 = y1;
			while(z < 100)
			{
				double h1 = ((a1 * a1) - (b1 * b1));	//rel number
				double h2 = (2 * a1 * b1);				//imaginary number
				 a1 = h1 + 0.065;//x1 real plane values
				 b1 = h2  + 0.122;//y1 imaginary plane values
				if(fabs(a1 + b1 ) > f->win_width*4)
						break ;
				z++;
			}
			//printf("z:%d\n",z);
			my_mlx_pixel_put(&f->img, x, y, int_from_rgb(255,z,z));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.mlx_img, 0, 0);
	return 1;
}


int		init_window(t_fractal *f)
{
	printf("w:%d,h:%d\n",f->win_width,f->win_heigth);
	if (!(f->mlx_ptr = mlx_init()))
		return 1;
	if (!(f->win_ptr = mlx_new_window(f->mlx_ptr, f->win_width,f->win_heigth, "fractal")))
		return 1; //error
	//salir de las ventanas
	//mlx_hook(f->win_ptr, 2, 1L << 0, exit_win, f);//exit con esc
	mlx_hook(f->win_ptr, 17, 1L << 2, exit_win, f);
	f->img.mlx_img = mlx_new_image(f->mlx_ptr, f->win_width, f->win_heigth);
	f->img.address = mlx_get_data_addr(f->img.mlx_img, &f->img.bits_per_pixel,&f->img.line_length, &f->img.endian);
	//fill image
	create_fractal(f);
	mlx_loop(f->mlx_ptr);
	return (0);
}

int main()
{
	t_fractal f;
	int err;

	err = 0;
	ft_bzero(&f,sizeof(t_fractal));
	f.win_heigth = 500;
	f.win_width = 500;
	err = init_window(&f);
	if(err)
		return printf("error creating window");
	return 0;
}
