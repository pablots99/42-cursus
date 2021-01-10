/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 20:02:19 by pablo             #+#    #+#             */
/*   Updated: 2021/01/10 16:48:22 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"


int create_int_color_shade(t_rgb color, t_ligth ligth,float brigth)
{
	t_rgb c;
	ligth.brigthness /= brigth;
	c.r = (color.r  * ligth.rgb.r * ligth.brigthness ) / 255;
	c.g = (color.g  * ligth.rgb.g * ligth.brigthness) / 255;
	c.b = (color.b  * ligth.rgb.b * ligth.brigthness) / 255;
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
t_rgb rgb_from_int(int color)
{
	t_rgb c;

	c.r = (color >> 16) &  0xFF;
	c.g = (color >> 8)  &  0xFF;
	c.b = (color & 0xFF);
	return (c);
}
