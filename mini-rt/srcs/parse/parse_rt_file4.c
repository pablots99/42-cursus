/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_file4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:13:03 by pablo             #+#    #+#             */
/*   Updated: 2021/02/14 23:37:09 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void save_faces(t_cube *cu)
{
    cu->face1.cord = cu->cord;
    cu->face1.norm_v = esc_dot_vec(-1, cu->norm_vec);
    cu->face1.rgb = cu->rgb;
    cu->face1.refraction = cu->reflexion;
    cu->face1.specular = cu->specular;
    cu->face1.side = cu->width;

    cu->face2.cord = sum_vec(cu->cord, esc_dot_vec(cu->width, cu->norm_vec));
    cu->face2.norm_v = cu->norm_vec;
    cu->face2.rgb = cu->rgb;
    cu->face2.refraction = cu->reflexion;
    cu->face1.specular = cu->specular;
    cu->face2.side = cu->width;
    save_sq_points(&cu->face1);
    save_sq_points(&cu->face2);
    // cu->face3.rgb = cu->rgb;
    // cu->face3.refraction = cu->reflexion;
    // cu->face3.side = cu->width;
    // cu->face3.points.p0 = cu->face2.points.p0;
    // cu->face3.points.p1 = cu->face2.points.p1;
    // cu->face3.points.p2 = cu->face1.points.p0;
    // cu->face3.points.p3 = cu->face1.points.p1;
}

int save_new_cube(char **splited, t_file *configFile)
{
    t_cube *cube;
    int err;

    err = 0;
    if (ft_bistrlen(splited) != 7)
        return (parse_error("Cube Error: Bad number of arguments \n"));
    if (!ft_isfloat(splited[3]))
        return (parse_error("Cube  Error: Bad value for width \n"));
    if (!(cube = malloc(1 * sizeof(t_cube))))
        return (parse_error("Cube Error: Malloc error on cube\n"));
    err += save_cord(&cube->cord, splited[1], "Cube");
    err += save_cord(&cube->norm_vec, splited[2], "Cube");
    cube->width = ft_atof(splited[3]);
    err += save_rgb(&cube->rgb, splited[4], "Cube");
    cube->reflexion = ft_atof(splited[5]);
    cube->specular = ft_atoi(splited[6]);
    cube->norm_vec = norm_vec(cube->norm_vec);
    save_faces(cube);
    ft_lstadd_back(&configFile->cube, ft_lstnew(cube));
    return ((err) ? 1 : 0);
}
