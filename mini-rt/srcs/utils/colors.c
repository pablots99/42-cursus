/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 20:02:19 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 16:27:00 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int		create_shade_color(t_rgb color, t_ligth ligth,
	float brigth, float specular)
{
	t_rgb c;

	c.r = min_int(255, ligth.rgb.r * ((color.r * brigth / 255) + specular));
	c.g = min_int(255, ligth.rgb.g * ((color.g * brigth / 255) + specular));
	c.b = min_int(255, ligth.rgb.b * ((color.b * brigth / 255) + specular));
	return (c.r << 16 | c.g << 8 | c.b);
}

int		create_shade_color2(t_rgb color, t_shades sh)
{
	t_rgb c;

	c.r = min_int(255, sh.ligth_color.r * ((color.r *
		sh.difuse / 255) + sh.specular));
	c.g = min_int(255, sh.ligth_color.g * ((color.g *
		sh.difuse / 255) + sh.specular));
	c.b = min_int(255, sh.ligth_color.b * ((color.b *
		sh.difuse / 255) + sh.specular));
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
