/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 20:02:19 by pablo             #+#    #+#             */
/*   Updated: 2021/02/22 13:08:32 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int		create_shade_color(t_rgb color, t_shades sh)
{
	t_rgb c;

	c = sum_colors2(color, sh.ligth_color);
	c = esc_color(sh.specular + sh.difuse, c);
	return (c.r << 16 | c.g << 8 | c.b);
}

int		ambient_color(t_rgb color, t_ambient_ligth ambient)
{
	t_rgb c;

	c.r = min_int(255, (color.r * ambient.rgb.r * ambient.ratio / 255));
	c.g = min_int(255, (color.g * ambient.rgb.g * ambient.ratio) / 255);
	c.b = min_int(255, (color.b * ambient.rgb.b * ambient.ratio) / 255);
	return (c.r << 16 | c.g << 8 | c.b);
}

t_rgb	sum_colors(t_rgb c1, t_rgb c2)
{
	t_rgb res;

	res.r = min_int(255, c1.r + c2.r);
	res.g = min_int(255, (c1.g + c2.g));
	res.b = min_int(255, (c1.b + c2.b));
	return (res);
}

t_rgb	sum_colors2(t_rgb c1, t_rgb c2)
{
	t_rgb res;

	res.r = (c1.r * c2.r) / 255;
	res.g = (c1.g * c2.g) / 255;
	res.b = (c1.b * c2.b) / 255;
	return (res);
}

t_rgb	esc_color(float n, t_rgb c)
{
	t_rgb res;

	res.r = min_int(255, n * c.r);
	res.g = min_int(255, n * c.g);
	res.b = min_int(255, n * c.b);
	return (res);
}
