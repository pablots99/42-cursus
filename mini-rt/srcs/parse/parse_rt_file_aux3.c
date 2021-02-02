/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_file_aux3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:14:58 by ptorres           #+#    #+#             */
/*   Updated: 2021/02/02 19:28:38 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int save_cube_sides(t_cube *cube)
{
	t_square *sq1;
	t_square *sq2;

	if (!(sq1 = malloc(1 * sizeof(t_square))) || !(sq2 = malloc(1 * sizeof(t_square))))
		return (parse_error("Cube Error: Malloc error on t_square\n"));
	sq1->cord = cube->cord;
	sq1->norm_v = cube->norm_vec;
	sq1->angle = 0;
	sq1->refraction = cube->reflexion;
	sq1->rgb = cube->rgb;
	sq1->side = cube->width;
	sq1->specular = cube->specular;

	sq2->cord = esc_dot_vec(cube->width, sq1->norm_v);
	sq2->norm_v = esc_dot_vec(-1, cube->norm_vec);
	sq2->angle = 0;
	sq2->refraction = cube->reflexion;
	sq2->rgb = cube->rgb;
	sq2->side = cube->width;
	sq2->specular = cube->specular;
	save_sq_points(sq1);
	save_sq_points(sq2);
	printf("cube sq:%p , sq2:%p", sq1, sq2);
	//ft_lstadd_back(&cube->faces, ft_lstnew(sq1));
	//ft_lstadd_back(&cube->faces, ft_lstnew(sq2));
	return (0);
}
int save_cube_sides1(t_cube *cube, t_file *c)
{
	t_square *sq3;
	t_square *sq4;

	return (0);
}
int save_cube_sides3(t_cube *cube, t_file *c)
{
	t_square *sq5;
	t_square *sq6;

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
	if (!(cube = malloc(1 * sizeof(t_cube))))
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