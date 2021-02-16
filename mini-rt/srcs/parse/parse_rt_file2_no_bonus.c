/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_file2_no_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:08:44 by ptorres           #+#    #+#             */
/*   Updated: 2021/02/16 15:37:21 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int		save_new_sphere_no(char **splited, t_file *configfile)
{
	t_sphere	*sphere;
	int			err;

	err = 0;
	if (!(ft_bistrlen(splited) == 4))
		return (parse_error("Sphere Error: Bad number of arguments \n"));
	if (!ft_isfloat(splited[2]))
		return (parse_error("Sphere Error: Bad value for Diameter \n"));
	if (!(sphere = malloc(1 * sizeof(t_sphere))))
		return (parse_error("Sphere Error: Malloc error on t_sphere\n"));
	err += save_cord(&sphere->cord, splited[1], "Sphere");
	err += save_rgb(&sphere->rgb, splited[3], "Sphere");
	sphere->diameter = ft_atof(splited[2]);
	sphere->refraction = 0;
	sphere->specular = 0;
	sphere->bmp.heigth = 0;
	ft_lstadd_back(&configfile->sphere, ft_lstnew(sphere));
	if (err)
		return (1);
	return (0);
}

int		save_new_plane_no(char **splited, t_file *configfile)
{
	t_plane	*plane;
	int		err;

	err = 0;
	if (ft_bistrlen(splited) != 4)
		return (parse_error("Plane Error: Bad number of arguments \n"));
	if (!(plane = malloc(1 * sizeof(t_plane))))
		return (parse_error("Plane Error: Malloc error on t_plane\n"));
	err += save_cord(&plane->cord, splited[1], "Plane");
	err += save_cord(&plane->norm_v, splited[2], "Plane");
	err += save_rgb(&plane->rgb, splited[3], "Plane");
	plane->norm_v = norm_vec(plane->norm_v);
	plane->refraction = 0;
	plane->specular = 0;
	ft_lstadd_back(&configfile->plane, ft_lstnew(plane));
	if (err)
		return (1);
	return (0);
}

int		save_new_square_no(char **splited, t_file *configfile)
{
	t_square	*square;
	int			err;

	err = 0;
	if (ft_bistrlen(splited) != 5)
		return (parse_error("Square Error: Bad number of arguments \n"));
	if (!ft_isfloat(splited[3]))
		return (parse_error("Square Ligth Error: Bad value for side size \n"));
	if (!(square = malloc(1 * sizeof(t_square))))
		return (parse_error("Square Error: Malloc error on t_square\n"));
	err += save_cord(&square->cord, splited[1], "PlSquareane");
	err += save_cord(&square->norm_v, splited[2], "Square");
	square->side = ft_atof(splited[3]);
	square->refraction = 0;
	err += save_rgb(&square->rgb, splited[4], "Square");
	square->norm_v = norm_vec(square->norm_v);
	square->specular = 0;
	square->angle = 0;
	save_sq_points(square);
	ft_lstadd_back(&configfile->square, ft_lstnew(square));
	if (err)
		return (1);
	return (0);
}

int		save_new_cylinder_no(char **splited, t_file *configfile)
{
	t_cylinder	*cylinder;
	int			err;

	err = 0;
	if (ft_bistrlen(splited) != 6)
		return (parse_error("Cylinder Error: Bad number of arguments \n"));
	if (!ft_isfloat(splited[3]))
		return (parse_error("Cylinder  Error: Bad value for diameter \n"));
	if (!ft_isfloat(splited[4]))
		return (parse_error("Cylinder  Error: Bad value for height \n"));
	if (!(cylinder = malloc(1 * sizeof(t_cylinder))))
		return (parse_error("Cylinder Error: Malloc error on t_cylinder\n"));
	err += save_cord(&cylinder->cord, splited[1], "Cylinder");
	err += save_cord(&cylinder->norm_v, splited[2], "Cylinder");
	cylinder->diameter = ft_atof(splited[3]);
	cylinder->height = ft_atof(splited[4]);
	err += save_rgb(&cylinder->rgb, splited[5], "Cylinder");
	cylinder->refraction = 0;
	cylinder->specular = 0;
	cylinder->norm_v = norm_vec(cylinder->norm_v);
	ft_lstadd_back(&configfile->cylinder, ft_lstnew(cylinder));
	if (err)
		return (1);
	return (0);
}

int		save_new_triangle_no(char **splited, t_file *configfile)
{
	t_triangle	*triangle;
	int			err;

	err = 0;
	if (ft_bistrlen(splited) != 5)
		return (parse_error("Triangle Error: Bad number of arguments \n"));
	if (!(triangle = malloc(1 * sizeof(t_triangle))))
		return (parse_error("Triangle Error: Malloc error on t_triangle\n"));
	err += save_cord(&triangle->cord_1, splited[1], "Triangle");
	err += save_cord(&triangle->cord_2, splited[2], "Triangle");
	err += save_cord(&triangle->cord_3, splited[3], "Triangle");
	err += save_rgb(&triangle->rgb, splited[4], "Triangle");
	triangle->refraction = 0;
	triangle->specular = 0;
	ft_lstadd_back(&configfile->triangle, ft_lstnew(triangle));
	if (err)
		return (1);
	return (0);
}
