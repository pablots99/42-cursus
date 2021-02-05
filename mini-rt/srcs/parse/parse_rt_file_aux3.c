/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_file_aux3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:14:58 by ptorres           #+#    #+#             */
/*   Updated: 2021/02/04 19:23:49 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_matrix norm_cu(t_cord norm_v)
{
	float side;
	t_matrix rot_mat;

	side = side / 2;
	rot_mat.v3 = norm_v;
	rot_mat.v1 = prod_vec(vector(0, 1, 0), norm_v);
	rot_mat.v2 = prod_vec(norm_v, rot_mat.v1);
	if (fabs(norm_v.y) == 1)
	{
		rot_mat.v1 = esc_dot_vec(norm_v.y * -1, vector(1, 0, 0));
		rot_mat.v2 = esc_dot_vec(norm_v.y * -1, vector(0, 0, 1));
	}
	return (rot_mat);
}

int save_cube_sides1(t_cube *cube)
{
	t_matrix mat;

	mat = norm_cu(cube->norm_vec);
	cube->faces.face3.cord = sum_vec(sum_vec(cube->cord, esc_dot_vec(cube->width / 2,
																	 cube->norm_vec)),
									 esc_dot_vec(cube->width / 2, mat.v2));
	cube->faces.face3.norm_v = mat.v2;
	cube->faces.face3.angle = 0;
	cube->faces.face3.refraction = cube->reflexion;
	cube->faces.face3.rgb = cube->rgb;
	cube->faces.face3.side = cube->width;
	cube->faces.face3.specular = cube->specular;
	cube->faces.face4.norm_v = esc_dot_vec(-1, mat.v2);
	cube->faces.face4.cord = sum_vec(sum_vec(cube->cord, esc_dot_vec(cube->width / 2,
																	 cube->norm_vec)),
									 esc_dot_vec(cube->width / 2, cube->faces.face4.norm_v));
	cube->faces.face4.angle = 0;
	cube->faces.face4.refraction = cube->reflexion;
	cube->faces.face4.rgb = cube->rgb;
	cube->faces.face4.side = cube->width;
	cube->faces.face4.specular = cube->specular;
	save_sq_points(&cube->faces.face3);
	save_sq_points(&cube->faces.face4);
	return (0);
}
int save_cube_sides2(t_cube *cube)
{
	t_matrix mat;

	mat = norm_cu(cube->norm_vec);
	cube->faces.face5.cord = sum_vec(sum_vec(cube->cord, esc_dot_vec(cube->width / 2,
																	 cube->norm_vec)),
									 esc_dot_vec(cube->width / 2, mat.v1));
	cube->faces.face5.norm_v = mat.v1;
	cube->faces.face5.angle = 0;
	cube->faces.face5.refraction = cube->reflexion;
	cube->faces.face5.rgb = cube->rgb;
	cube->faces.face5.side = cube->width;
	cube->faces.face5.specular = cube->specular;
	cube->faces.face6.norm_v = esc_dot_vec(-1, mat.v1);
	cube->faces.face6.cord = sum_vec(sum_vec(cube->cord, esc_dot_vec(cube->width / 2,
																	 cube->norm_vec)),
									 esc_dot_vec(cube->width / 2, cube->faces.face6.norm_v));
	cube->faces.face6.angle = 0;
	cube->faces.face6.refraction = cube->reflexion;
	cube->faces.face6.rgb = cube->rgb;
	cube->faces.face6.side = cube->width;
	cube->faces.face6.specular = cube->specular;
	save_sq_points(&cube->faces.face5);
	save_sq_points(&cube->faces.face6);
	return (0);
}
int save_cube_sides(t_cube *cube)
{
	cube->faces.face1.cord = cube->cord;
	cube->faces.face1.norm_v = cube->norm_vec;
	cube->faces.face1.angle = 0;
	cube->faces.face1.refraction = cube->reflexion;
	cube->faces.face1.rgb = cube->rgb;
	cube->faces.face1.side = cube->width;
	cube->faces.face1.specular = cube->specular;
	cube->faces.face2.cord = sum_vec(cube->cord, esc_dot_vec(cube->width, cube->norm_vec));
	cube->faces.face2.norm_v = esc_dot_vec(-1, cube->norm_vec);
	cube->faces.face2.angle = 0;
	cube->faces.face2.refraction = cube->reflexion;
	cube->faces.face2.rgb = cube->rgb;
	cube->faces.face2.side = cube->width;
	cube->faces.face2.specular = cube->specular;
	save_sq_points(&cube->faces.face1);
	save_sq_points(&cube->faces.face2);
	save_cube_sides1(cube);
	save_cube_sides2(cube);
	return (0);
}
int save_new_cube(char **splited, t_file *configFile)
{
	t_cube *cube;
	int err;

	err = 0;
	if (!(ft_bistrlen(splited) == 7))
		return (parse_error("Sphere Error: Bad number of arguments \n"));
	if (!ft_isfloat(splited[3]))
		return (parse_error("Sphere Error: Bad value for Diameter \n"));
	if (!(cube = malloc((1 * sizeof(t_cube)))))
		return (parse_error("Sphere Error: Malloc error on t_sphere\n"));
	err += save_cord(&cube->cord, splited[1], "Sphere");
	err += save_cord(&cube->norm_vec, splited[2], "Sphere");
	err += save_rgb(&cube->rgb, splited[4], "Sphere");
	cube->width = ft_atof(splited[3]);
	cube->reflexion = ft_atof(splited[5]);
	cube->specular = ft_atoi(splited[6]);
	save_cube_sides(cube);
	ft_lstadd_back(&configFile->cube, ft_lstnew(cube));
	if (err)
		return (1);
	return (0);
}