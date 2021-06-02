/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 23:08:38 by pablo             #+#    #+#             */
/*   Updated: 2021/06/02 23:34:33 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/fractal.h"

int		init_window(t_fractal *f)
{
	printf("w:%d,h:%d\n",f->win_width,f->win_heigth);
	if (!(f->mlx_ptr = mlx_init()))
		return 1;
	if (!(f->win_ptr = mlx_new_window(f->mlx_ptr, f->win_width,f->win_heigth, "MiniRt")))
		return 1; //error
	//salir de las ventanas
	//mlx_hook(f->win_ptr, 2, 1L << 0, exit_win, f);//exit con esc
	mlx_hook(f->win_ptr, 17, 1L << 2, exit_win, f);
	f->img.mlx_img = mlx_new_image(f->mlx_ptr, f->win_width, f->win_heigth);
	f->img.address = mlx_get_data_addr(f->img.mlx_img, &f->img.bits_per_pixel,&f->img.line_length, &f->img.endian);
	//fill image
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
