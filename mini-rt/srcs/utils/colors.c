/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 20:02:19 by pablo             #+#    #+#             */
/*   Updated: 2021/02/05 00:48:56 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int create_shade_color(t_rgb color, t_ligth ligth, float brigth, float specular)
{
	t_rgb c;

	c.r = min_int(255, ligth.rgb.r * ((color.r * brigth / 255) + specular));
	c.g = min_int(255, ligth.rgb.g * ((color.g * brigth / 255) + specular));
	c.b = min_int(255, ligth.rgb.b * ((color.b * brigth / 255) + specular));
	return (c.r << 16 | c.g << 8 | c.b);
}

int ambient_color(t_rgb color, t_ambient_ligth ambient)
{
	t_rgb c;

	c.r = min_int(255, (color.r * ambient.rgb.r * ambient.ratio / 255));
	c.g = min_int(255, (color.g * ambient.rgb.g * ambient.ratio) / 255);
	c.b = min_int(255, (color.b * ambient.rgb.b * ambient.ratio) / 255);
	return (c.r << 16 | c.g << 8 | c.b);
}
t_rgb sum_colors(t_rgb c1, t_rgb c2)
{
	t_rgb res;
	res.r = min_int(255, c1.r + c2.r);
	res.g = min_int(255, (c1.g + c2.g));
	res.b = min_int(255, (c1.b + c2.b));
	return (res);
}
t_rgb rgb_from_int(int color)
{
	t_rgb c;

	c.r = (color >> 16) & 0xFF;
	c.g = (color >> 8) & 0xFF;
	c.b = (color & 0xFF);
	return (c);
}
int int_from_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
int sum_int_colors(int color1, int color2)
{
	t_rgb c1;
	t_rgb c2;
	t_rgb res;

	c1 = rgb_from_int(color1);
	c2 = rgb_from_int(color2);
	res.r = min_int(255, c1.r + c2.r);
	res.g = min_int(255, c1.g + c2.g);
	res.b = min_int(255, c1.b + c2.b);
	return (int_from_rgb(res.r, res.g, res.b));
}
int average_color(int *color, int base)
{
	int i;
	t_rgb c;
	t_rgb aux_c;

	i = 0;
	c = rgb_from_int(0);
	while (i < base)
	{
		aux_c = rgb_from_int(color[i]);
		c.r += aux_c.r;
		c.g += aux_c.g;
		c.b += aux_c.b;
		//printf("color r:%d,g:%d,b:%d\n",aux_c.r,aux_c.g,aux_c.b);
		i++;
	}
	c.r /= base;
	c.g /= base;
	c.b /= base;
	//printf("-----------------------\n");
	return int_from_rgb(c.r, c.g, c.b);
}