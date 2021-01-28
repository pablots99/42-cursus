/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rt_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:39:35 by pablo             #+#    #+#             */
/*   Updated: 2021/01/28 19:29:45 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"
#include "./rt_file.h"

int save_rt_file_aux1(char **splited, t_file *configFile)
{
	int err;

	err = 0;
	if (ft_strlen(*splited) == 2 && ft_strncmp(*splited, "pl", 2) == 0)
		err = save_new_plane(splited, configFile);
	else if (ft_strlen(*splited) == 2 && ft_strncmp(*splited, "sq", 2) == 0)
		err = save_new_square(splited, configFile);
	else if (ft_strlen(*splited) == 2 && ft_strncmp(*splited, "cy", 2) == 0)
		err = save_new_cylinder(splited, configFile);
	else if (ft_strlen(*splited) == 2 && ft_strncmp(*splited, "tr", 2) == 0)
		err = save_new_triangle(splited, configFile);
	else
		err = ft_printf("Error: '%s' is a bad identifer\n", *splited);
	if (!err)
		return (0);
	else
		return (1);
}

int save_rt_file(char **splited, t_file *configFile)
{

	int err;
	if (!(configFile->mlx_ptr = mlx_init()))
		return parse_error("Minilibx Error: CAN NOT INITIALIZE MINILIBX");
	err = 0;
	if (*splited)
	{
		if (ft_strlen(*splited) == 1 && *splited[0] == 'R')
			err = save_res(splited, configFile);
		else if (ft_strlen(*splited) == 1 && *splited[0] == 'l')
			err = save_new_ligth(splited, configFile);
		else if (ft_strlen(*splited) == 1 && *splited[0] == 'A')
			err = save_ambient_ligth(splited, configFile);
		else if (ft_strlen(*splited) == 1 && *splited[0] == 'c')
			err = save_new_camera(splited, configFile);
		else if (ft_strlen(*splited) == 2 && ft_strncmp(*splited, "sp", 2) == 0)
			err = save_new_sphere(splited, configFile);
		else
			return save_rt_file_aux1(splited, configFile);
	}
	if (!err)
		return (0);
	else
		return (1);
}

int read_file(int fd, t_file *configFile)
{
	char *line;
	char **line_splited;
	int err;

	err = 0;
	while (get_next_line(fd, &line) > 0)
	{
		line_splited = ft_split(line, ' ');
		err += save_rt_file(line_splited, configFile);
		ft_bidimensional_free(line_splited);
		free(line);
	}
	line_splited = ft_split(line, ' ');
	err += save_rt_file(line_splited, configFile);
	free(line);
	ft_bidimensional_free(line_splited);
	close(fd);
	if (err)
		return (1);
	return (0);
}
int read_rt_file(char *file, t_file *configFile)
{
	int fd;
	if (!ft_strnstr(file, ".rt", ft_strlen(file)))
	{
		ft_printf("Error\n      File Error: Input file is a non rt file\n");
		return 0;
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n      File Error: no rt file named: %s\n", file);
		return 0;
	}
	if (read_file(fd, configFile) == 1)
		return (0);
	return (1);
}

void save_sq_points(t_square *sq)
{
	float side;
	t_matrix rot_mat;

	side = sq->side / 2;
	rot_mat.v3 = sq->norm_v;
	rot_mat.v1 = prod_vec(vector(0, 1, 0), sq->norm_v);
	rot_mat.v2 = prod_vec(sq->norm_v, rot_mat.v1);
	if (fabs(sq->norm_v.y) == 1)
	{
		rot_mat.v1 = esc_dot_vec(sq->norm_v.y * -1, vector(1, 0, 0));
		rot_mat.v2 = esc_dot_vec(sq->norm_v.y * -1, vector(0, 0, 1));
	}
	sq->points.p0 = sum_vec(vector_dot_matrix(rot_center_point(vector(side * -1, side, -1), sq->angle), rot_mat), sq->cord);
	sq->points.p1 = sum_vec(vector_dot_matrix(rot_center_point(vector(side, side, -1), sq->angle), rot_mat), sq->cord);
	sq->points.p2 = sum_vec(vector_dot_matrix(rot_center_point(vector(side * -1, side * -1, -1), sq->angle), rot_mat), sq->cord);
	sq->points.p3 = sum_vec(vector_dot_matrix(rot_center_point(vector(side, side * -1, -1), sq->angle), rot_mat), sq->cord);
}
