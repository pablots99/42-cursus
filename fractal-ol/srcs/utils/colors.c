/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 00:34:01 by pablo             #+#    #+#             */
/*   Updated: 2021/06/13 18:48:31 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int		int_from_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
t_rgb hsv2rgb(t_hsv HSV)
{
    t_rgb RGB;
    double H = HSV.h, S = HSV.s, V = HSV.v,
            P, Q, T,
            fract;

    (H == 360.)?(H = 0.):(H /= 60.);
    fract = H - floor(H);

    P = V*(1. - S);
    Q = V*(1. - S*fract);
    T = V*(1. - S*(1. - fract));

    if      (0. <= H && H < 1.)
        RGB = (t_rgb){.r = V, .g = T, .b = P};
    else if (1. <= H && H < 2.)
        RGB = (t_rgb){.r = Q, .g = V, .b = P};
    else if (2. <= H && H < 3.)
        RGB = (t_rgb){.r = P, .g = V, .b = T};
    else if (3. <= H && H < 4.)
        RGB = (t_rgb){.r = P, .g = Q, .b = V};
    else if (4. <= H && H < 5.)
        RGB = (t_rgb){.r = T, .g = P, .b = V};
    else if (5. <= H && H < 6.)
        RGB = (t_rgb){.r = V, .g = P, .b = Q};
    else
        RGB = (t_rgb){.r = 0., .g = 0., .b = 0.};

    return RGB;
}
