/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_file3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:13:03 by pablo             #+#    #+#             */
/*   Updated: 2021/02/15 20:26:16 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void save_base_py(t_pyramid *pyramid)
{
    pyramid->base.cord = pyramid->cord;
    pyramid->base.norm_v = pyramid->norm_vec;
    pyramid->base.refraction = pyramid->reflexion;
    pyramid->base.specular = pyramid->specular;
    pyramid->base.side = pyramid->width;
    pyramid->base.rgb = pyramid->rgb;
    save_sq_points(&pyramid->base);
}
void save_py_faces2(t_pyramid *pyramid)
{
    pyramid->tr1.refraction = pyramid->reflexion;
    pyramid->tr2.refraction = pyramid->reflexion;
    pyramid->tr3.refraction = pyramid->reflexion;
    pyramid->tr4.refraction = pyramid->reflexion;
    pyramid->tr1.specular = pyramid->specular;
    pyramid->tr2.specular = pyramid->specular;
    pyramid->tr3.specular = pyramid->specular;
    pyramid->tr4.specular = pyramid->specular;
    pyramid->tr1.rgb = pyramid->rgb;
    pyramid->tr2.rgb = pyramid->rgb;
    pyramid->tr3.rgb = pyramid->rgb;
    pyramid->tr4.rgb = pyramid->rgb;
}
void save_py_faces(t_pyramid *pyramid)
{
    t_cord vortex;

    vortex = sum_vec(pyramid->cord, esc_dot_vec(pyramid->heigth,
                                                norm_vec(prod_vec((rest_vec(pyramid->base.points.p3, pyramid->base.points.p2)),
                                                                  (rest_vec(pyramid->base.points.p2, pyramid->base.points.p1))))));
    pyramid->tr1.cord_1 = vortex;
    pyramid->tr2.cord_1 = vortex;
    pyramid->tr3.cord_1 = vortex;
    pyramid->tr4.cord_1 = vortex;
    pyramid->tr1.cord_2 = pyramid->base.points.p0;
    pyramid->tr1.cord_3 = pyramid->base.points.p1;
    pyramid->tr2.cord_2 = pyramid->base.points.p3;
    pyramid->tr2.cord_3 = pyramid->base.points.p2;
    pyramid->tr3.cord_2 = pyramid->base.points.p2;
    pyramid->tr3.cord_3 = pyramid->base.points.p0;
    pyramid->tr4.cord_2 = pyramid->base.points.p3;
    pyramid->tr4.cord_3 = pyramid->base.points.p1;
    save_py_faces2(pyramid);
}

int save_new_pyramid(char **splited, t_file *configFile)
{
    t_pyramid *pyramid;
    int err;

    err = 0;
    if (ft_bistrlen(splited) != 8)
        return (parse_error("Pyramid Error: Bad number of arguments \n"));
    if (!ft_isfloat(splited[3]))
        return (parse_error("Pyramid  Error: Bad value for width \n"));
    if (!ft_isfloat(splited[4]))
        return (parse_error("Pyramid  Error: Bad value for height \n"));
    if (!(pyramid = malloc(1 * sizeof(t_pyramid))))
        return (parse_error("Pyramid Error: Malloc error on t_yramid\n"));
    err += save_cord(&pyramid->cord, splited[1], "Pyramid");
    err += save_cord(&pyramid->norm_vec, splited[2], "Pyramid");
    pyramid->width = ft_atof(splited[3]);
    pyramid->heigth = ft_atof(splited[4]);
    err += save_rgb(&pyramid->rgb, splited[5], "Pyramid");
    pyramid->reflexion = ft_atof(splited[6]);
    pyramid->specular = ft_atoi(splited[7]);
    pyramid->norm_vec = norm_vec(pyramid->norm_vec);
            save_base_py(pyramid);

    save_py_faces(pyramid);
    ft_lstadd_back(&configFile->pyramid, ft_lstnew(pyramid));
    return ((err) ? 1 : 0);
}
