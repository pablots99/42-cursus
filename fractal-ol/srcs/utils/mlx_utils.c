/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 23:10:26 by pablo             #+#    #+#             */
/*   Updated: 2021/06/02 23:33:30 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->address + (y * data->line_length +
						   x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
int exit_win( t_fractal *f)
{

	mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	exit(0);

	return (0);
}
