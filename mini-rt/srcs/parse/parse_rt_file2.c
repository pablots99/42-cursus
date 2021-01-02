/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_file2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:08:44 by ptorres           #+#    #+#             */
/*   Updated: 2021/01/02 21:01:32 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int save_new_sphere(char **splited, t_file *configFile)
{
	t_sphere *sphere;
	int err;

	err = 0;
	if (ft_bistrlen(splited) != 4)
		return (parse_error("Sphere Error: Bad number of arguments \n"));
	if(!ft_isfloat(splited[2]))
		return (parse_error("Sphere Error: Bad value for Diameter \n"));
		if(!(sphere = malloc(1 * sizeof(t_sphere))))
		return (parse_error("Sphere Error: Malloc error on t_sphere\n"));
	err += save_cord(&sphere->cord, splited[1], "Sphere");
	err += save_rgb(&sphere->rgb, splited[3], "Sphere");
	sphere->diameter = ft_atof(splited[2]);
	ft_lstadd_back(&configFile->sphere, ft_lstnew(sphere));
	if (err)
	{
		//free(sphere);
		return (1);
	}
	return (0);
}

int save_new_plane(char **splited, t_file *configFile)
{
	t_plane *plane;
	int err;

	err = 0;
	if (ft_bistrlen(splited) != 4)
		return (parse_error("Plane Error: Bad number of arguments \n"));
	if(!(plane = malloc(1 * sizeof(t_plane))))
		return (parse_error("Plane Error: Malloc error on t_plane\n"));
	err += save_cord(&plane->cord, splited[1], "Plane");
	err += save_cord(&plane->norm_v, splited[2], "Plane");
	err += save_rgb(&plane->rgb, splited[3], "Plane");
	if (!is_norm_vec(&plane->norm_v))
		err += (parse_error("Plane Error: vector not normalized \n"));
	ft_lstadd_back(&configFile->plane, ft_lstnew(plane));
	if (err)
	{
		//free(plane);
		return (1);
	}
	return (0);
}
int save_new_square(char **splited, t_file *configFile)
{
	t_square *square;
	int err;

	err = 0;
	if (ft_bistrlen(splited) != 5)
		return (parse_error("Square Error: Bad number of arguments \n"));
	if (!ft_isfloat(splited[3]))
		return (parse_error("Square Ligth Error: Bad value for side size \n"));
	if(!(square = malloc(1 * sizeof(t_square))))
		return (parse_error("Square Error: Malloc error on t_square\n"));
	err += save_cord(&square->cord, splited[1], "PlSquareane");
	err += save_cord(&square->norm_v, splited[2], "Square");
	square->side = ft_atof(splited[3]);
	err += save_rgb(&square->rgb, splited[4], "Square");
	if (!is_norm_vec(&square->norm_v))
		err += (parse_error("Square Error: vector not normalized \n"));
	ft_lstadd_back(&configFile->square, ft_lstnew(square));
	if (err)
	{
		//free(square);
		return (1);
	}
	return (0);
}
int save_new_cylinder(char **splited, t_file *configFile)
{
	t_cylinder*cylinder;
	int err;

	err = 0;
	if (ft_bistrlen(splited) != 6)
		return (parse_error("Cylinder Error: Bad number of arguments \n"));
	if (!ft_isfloat(splited[3]))
		return (parse_error("Cylinder  Error: Bad value for diameter \n"));
	if (!ft_isfloat(splited[4]))
		return (parse_error("Cylinder  Error: Bad value for height \n"));
	if(!(cylinder = malloc(1 * sizeof(t_cylinder))))
		return (parse_error("Cylinder Error: Malloc error on t_cylinder\n"));
	err += save_cord(&cylinder->cord, splited[1], "Cylinder");
	err += save_cord(&cylinder->norm_v, splited[2], "Cylinder");
	cylinder->diameter= ft_atof(splited[3]);
	cylinder->height= ft_atof(splited[4]);
	err += save_rgb(&cylinder->rgb, splited[5], "Cylinder");
	if (!is_norm_vec(&cylinder->norm_v))
		err += (parse_error("Cylinder Error: vector not normalized \n"));
	ft_lstadd_back(&configFile->cylinder, ft_lstnew(cylinder));
	if (err)
	{
		//free(cylinder);
		return (1);
	}
	return (0);
}
int save_new_triangle(char **splited, t_file *configFile)
{
	t_triangle *triangle;
	int err;

	err = 0;
	if (ft_bistrlen(splited) != 5)
		return (parse_error("Triangle Error: Bad number of arguments \n"));
	if(!(triangle = malloc(1 * sizeof(t_triangle))))
		return (parse_error("Triangle Error: Malloc error on t_triangle\n"));
	err += save_cord(&triangle->cord_1, splited[1], "Triangle");
	err += save_cord(&triangle->cord_2, splited[2], "Triangle");
	err += save_cord(&triangle->cord_3, splited[3], "Triangle");
	err += save_rgb(&triangle->rgb, splited[4], "Triangle");
	ft_lstadd_back(&configFile->triangle, ft_lstnew(triangle));
	if (err)
	{
		//free(triangle);
		return (1);
	}
	return (0);
}


