/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 00:34:01 by pablo             #+#    #+#             */
/*   Updated: 2021/06/20 01:09:28 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

typedef struct s_aux
{
	double	   p;
	double 		q;
	double 		t;
	double		fract;
}	t_aux;

int int_from_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

t_rgb hsv_aux(double h, double s, double v, t_aux a)
{
	t_rgb rgb;
	if (0. <= h && h < 1.)
		rgb = (t_rgb){v,a.t, a.p};
	else if (1. <= h && h < 2.)
		rgb = (t_rgb){a.q,v,a.p};
	else if (2. <= h && h < 3.)
		rgb = (t_rgb){a.p, v, a.t};
	else if (3. <= h && h < 4.)
		rgb = (t_rgb){a.p, a.q,v};
	else if (4. <= h && h < 5.)
		rgb = (t_rgb){a.t, a.p, v};
	else if (5. <= h && h < 6.)
		rgb = (t_rgb){v, a.p, a.q};
	else
		rgb = (t_rgb){0,0,0};
	return rgb;

}

t_rgb hsv2rgb(t_hsv hsv)
{
	t_rgb rgb;
	double h;
	double s;
	double v;
	t_aux a;

	h = hsv.h;
	s = hsv.s;
	v = hsv.v;
	(h == 360.) ? (h = 0.) : (h /= 60.);
	a.fract = h - floor(h);
	a.p = v * (1. - s);
	a.q = v * (1. - s * a.fract);
	a.t = v * (1. - s * (1. - a.fract));

	return hsv_aux(h,s,v,a);
}


int get_color(t_fractal f, int z)
{

	t_hsv hsv;
	t_rgb rgb;


	hsv.h = (double)((double)255 * (double)z / f.precision);
	hsv.s = 1;
	if (z == f.precision)
		z = 0;
	else
		z = 255;
	hsv.v = resize_value(z, (t_range){0,f.precision}, (t_range){0, 1});

	rgb = hsv2rgb(hsv);
	rgb.r = resize_value(rgb.r, (t_range){0, 1}, (t_range){0, 255});
	rgb.g = resize_value(rgb.g, (t_range){0, 1}, (t_range){0, 255});
	rgb.b = resize_value(rgb.b, (t_range){0, 1}, (t_range){0, 255});
	return int_from_rgb(rgb.r, rgb.g,rgb.b);
}
