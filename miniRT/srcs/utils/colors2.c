/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:25:04 by ptorres           #+#    #+#             */
/*   Updated: 2021/02/22 13:08:55 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_rgb	rgb_from_int(int color)
{
	t_rgb c;

	c.r = (color >> 16) & 0xFF;
	c.g = (color >> 8) & 0xFF;
	c.b = (color & 0xFF);
	return (c);
}

int		int_from_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int		sum_int_colors(int color1, int color2)
{
	t_rgb c1;
	t_rgb c2;
	t_rgb res;

	c1 = rgb_from_int(color1);
	c2 = rgb_from_int(color2);
	res = sum_colors(c1, c2);
	return (int_from_rgb(res.r, res.g, res.b));
}

int		sepia_filter(t_rgb color)
{
	t_rgb c;

	c.r = min_int(255, (float)((float)color.r * 0.393) +
		(float)((float)color.g * 0.769) + (float)((float)color.b * 0.189));
	c.g = min_int(255, (float)((float)color.r * 0.349) +
		(float)((float)color.g * 0.686) + (float)((float)color.b * 0.168));
	c.b = min_int(255, (float)((float)color.r * 0.272) +
		(float)((float)color.g * 0.534) + (float)((float)color.b * 0.131));
	return (c.r << 16 | c.g << 8 | c.b);
}

int		average_color(int *color, int base, t_file *con)
{
	int		i;
	t_rgb	c;
	t_rgb	aux_c;
	int		color_a;

	i = 0;
	c = rgb_from_int(0);
	while (i < base)
	{
		aux_c = rgb_from_int(color[i]);
		c.r += aux_c.r;
		c.g += aux_c.g;
		c.b += aux_c.b;
		i++;
	}
	c.r /= base;
	c.g /= base;
	c.b /= base;
	color_a = int_from_rgb(c.r, c.g, c.b);
	if (con->sepia)
		color_a = sepia_filter(c);
	return (color_a);
}
