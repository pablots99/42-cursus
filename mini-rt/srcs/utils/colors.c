/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 20:02:19 by pablo             #+#    #+#             */
/*   Updated: 2021/01/12 15:38:31 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"


int create_int_color_shade(t_rgb color, t_ligth ligth,float brigth)
{
	t_rgb c;
	c.r = (color.r  * ligth.rgb.r * brigth ) / 255;
	c.g = (color.g  * ligth.rgb.g * brigth) / 255;
	c.b = (color.b  * ligth.rgb.b * brigth) / 255;
	return ( c.r << 16 | c.g << 8 | c.b);
}

int create_int_color(t_rgb color, t_ambient_ligth ambient)
{
	t_rgb c;

	c.r = (color.r  * ambient.rgb.r * ambient.ratio ) / 255;
	c.g = (color.g  * ambient.rgb.g * ambient.ratio) / 255;
	c.b = (color.b  * ambient.rgb.b * ambient.ratio) / 255;
	return (c.r << 16 | c.g << 8 | c.b);

}
t_rgb sum_colors(t_rgb c1,t_rgb c2)
{
	t_rgb res;
	res.r = c1.r + c2.r;
	res.g = c1.g + c2.g;
	res.b = c1.b + c2.b;
	return (res);
}
t_rgb rgb_from_int(int color)
{
	t_rgb c;

	c.r = (color >> 16) &  0xFF;
	c.g = (color >> 8)  &  0xFF;
	c.b = (color & 0xFF);
	return (c);
}
