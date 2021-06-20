/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 01:19:50 by pablo             #+#    #+#             */
/*   Updated: 2021/06/20 02:18:56 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int detect_key(int keycode, t_fractal *c)
{

	if (keycode == 125)
	{
		if (c->zoom_value < 0.5)
			c->zoom_value *= 2;
		c->zoom -= c->zoom_value;
		c->precision -= 1;
	}
	if (keycode == 126)
	{
		if (c->zoom_value > 0.2)
			c->zoom_value /= 2;
		while (c->zoom + c->zoom_value > 0)
			c->zoom_value /= 10;
		c->zoom += c->zoom_value;
		c->precision += 1;
	}
	if (keycode == 13)
		c->move_y += c->zoom_value;
	if (keycode == 1)
		c->move_y -= c->zoom_value;
	if (keycode == 2)
		c->move_x += c->zoom_value;
	if (keycode == 0)
		c->move_x -= c->zoom_value;
	if (keycode == 30)
		c->precision += 1;
	if (keycode == 44)
		c->precision -= 1;
	threads(c);
	return 1;
}

int mouse_actions(int button, int x, int y, t_fractal *f)
{
	double x1;
	double y1;


	if (button == 4)
		detect_key(125, f);
	if (button == 5)
		detect_key(126, f);
	if (button == 1 && !f->is_julia && !f->is_fullJulia)
	{
		mlx_mouse_get_pos(f->win_ptr, &x, &y);
		x1 = resize_value(x, (t_range){0, f->win_width}, (t_range){-f->zoom + f->move_x, f->zoom + f->move_x});
		y1 = resize_value(y, (t_range){0, f->win_heigth}, (t_range){-f->zoom + f->move_y, f->zoom + f->move_y});
		f->is_julia = 1;
		f->julia->x = x1;
		f->julia->y = y1;
		f->julia->move_x = f->move_x;
		f->julia->move_y = f->move_y;
		f->julia->zoom = f->zoom;
		f->julia->zoom_value = f->zoom_value;
		f->move_x = 0;
		f->move_y = 0;
		f->zoom = -1;
		f->zoom_value = 0.1;
	}
	if (button == 2 && f->is_julia && !f->is_fullJulia)
	{
		f->is_julia = 0;
		f->move_x = f->julia->move_x;
		f->move_y = f->julia->move_y;
		f->zoom = f->julia->zoom;
		f->zoom_value = f->julia->zoom_value;
		f->julia->zoom_value = 0;
		f->julia->move_y = 0;
		f->julia->zoom = -1;
		f->julia->zoom_value = 0.1;
	}
	threads(f);
	return 1;
}

