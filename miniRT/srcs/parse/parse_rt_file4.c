/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_file4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:13:03 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 15:45:01 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	save_cube_faces2(t_cube *cu)
{
	cu->face3.rgb = cu->rgb;
	cu->face3.refraction = cu->reflexion;
	cu->face3.specular = cu->specular;
	cu->face3.side = cu->width;
	cu->face3.points.p0 = cu->face1.points.p0;
	cu->face3.points.p1 = cu->face1.points.p1;
	cu->face3.points.p2 = cu->face2.points.p3;
	cu->face3.points.p3 = cu->face2.points.p2;
	cu->face3.cord = cu->face3.points.p0;
	cu->face4.rgb = cu->rgb;
	cu->face4.refraction = cu->reflexion;
	cu->face4.specular = cu->specular;
	cu->face4.side = cu->width;
	cu->face4.points.p0 = cu->face1.points.p3;
	cu->face4.points.p1 = cu->face1.points.p2;
	cu->face4.points.p2 = cu->face2.points.p0;
	cu->face4.points.p3 = cu->face2.points.p1;
	cu->face4.cord = cu->face4.points.p0;
}

void	save_cube_faces(t_cube *cu)
{
	cu->face5.rgb = cu->rgb;
	cu->face5.refraction = cu->reflexion;
	cu->face5.specular = cu->specular;
	cu->face5.side = cu->width;
	cu->face5.points.p0 = cu->face1.points.p3;
	cu->face5.points.p1 = cu->face1.points.p1;
	cu->face5.points.p2 = cu->face2.points.p0;
	cu->face5.points.p3 = cu->face2.points.p2;
	cu->face5.cord = cu->face5.points.p0;
	cu->face6.rgb = cu->rgb;
	cu->face6.refraction = cu->reflexion;
	cu->face6.specular = cu->specular;
	cu->face6.side = cu->width;
	cu->face6.points.p0 = cu->face1.points.p0;
	cu->face6.points.p1 = cu->face1.points.p2;
	cu->face6.points.p2 = cu->face2.points.p3;
	cu->face6.points.p3 = cu->face2.points.p1;
	cu->face6.cord = cu->face6.points.p0;
	save_cube_faces2(cu);
}

void	save_cube_base(t_cube *cu, int cond)
{
	if (cond)
		cu->norm_vec = norm_vec(prod_vec(
			(rest_vec(cu->face1.points.p3, cu->face1.points.p2)),
				(rest_vec(cu->face1.points.p2, cu->face1.points.p1))));
	cu->face2.cord = sum_vec(cu->cord, esc_dot_vec(cu->width, cu->norm_vec));
	cu->face2.norm_v = cu->norm_vec;
	cu->face2.rgb = cu->rgb;
	cu->face2.refraction = cu->reflexion;
	cu->face2.specular = cu->specular;
	cu->face2.side = cu->width;
	if (!cond)
	{
		cu->face1.cord = cu->cord;
		cu->face1.norm_v = esc_dot_vec(-1, cu->norm_vec);
		cu->face1.rgb = cu->rgb;
		cu->face1.refraction = cu->reflexion;
		cu->face1.specular = cu->specular;
		cu->face1.side = cu->width;
		save_sq_points(&cu->face1);
		save_sq_points(&cu->face2);
	}
}

int		save_new_cube(char **splited, t_file *configfile)
{
	t_cube	*cube;
	int		err;

	err = 0;
	if (ft_bistrlen(splited) != 6)
		return (parse_error("Cube Error: Bad number of arguments \n"));
	if (!ft_isfloat(splited[2]))
		return (parse_error("Cube  Error: Bad value for width \n"));
	if (!(cube = malloc(1 * sizeof(t_cube))))
		return (parse_error("Cube Error: Malloc error on cube\n"));
	err += save_cord(&cube->cord, splited[1], "Cube");
	cube->width = ft_atof(splited[2]);
	err += save_rgb(&cube->rgb, splited[3], "Cube");
	cube->reflexion = ft_atof(splited[4]);
	cube->specular = ft_atoi(splited[5]);
	cube->norm_vec = vector(0, 1, 0);
	save_cube_base(cube, 0);
	save_cube_faces(cube);
	ft_lstadd_back(&configfile->cube, ft_lstnew(cube));
	return ((err) ? 1 : 0);
}
