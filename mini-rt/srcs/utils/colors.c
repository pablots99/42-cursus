/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 20:02:19 by pablo             #+#    #+#             */
/*   Updated: 2021/01/25 23:19:36 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int create_shade_color(t_rgb color, t_ligth ligth, float brigth, float specular)
{
	t_rgb c;
	
	c.r = min_int(255,ligth.rgb.r * ((color.r * brigth / 255) +specular));
	c.g = min_int(255,ligth.rgb.g * ((color.g * brigth / 255) + specular));
	c.b = min_int(255,ligth.rgb.b * ((color.b * brigth / 255)  +specular));
	return (c.r << 16 | c.g << 8 | c.b);
}

int ambient_color(t_rgb color, t_ambient_ligth ambient)
{
	t_rgb c;

	c.r = min_int(255,(color.r * ambient.rgb.r * ambient.ratio / 255));
	c.g = min_int(255,(color.g * ambient.rgb.g * ambient.ratio) / 255);
	c.b = min_int(255,(color.b * ambient.rgb.b * ambient.ratio) / 255);
	return (c.r << 16 | c.g << 8 | c.b);
}
t_rgb sum_colors(t_rgb c1, t_rgb c2)
{
	t_rgb res;
	res.r = min_int(255,c1.r + c2.r);
	res.g = min_int(255,(c1.g + c2.g));
	res.b = min_int(255,(c1.b + c2.b));
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
	res.r = min_int(255,c1.r + c2.r);
	res.g = min_int(255,c1.g + c2.g);
	res.b =  min_int(255,c1.b + c2.b);
	return (int_from_rgb(res.r,res.g,res.b));
}