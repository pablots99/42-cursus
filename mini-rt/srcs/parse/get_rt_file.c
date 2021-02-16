/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rt_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:39:35 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 18:01:52 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"
#include "./rt_file.h"

int		save_rt_file_aux1(char **splited, t_file *configfile)
{
	int err;

	err = 0;
	if (ft_strlen(*splited) == 2 && ft_strncmp(*splited, "pl", 2) == 0)
		err = save_new_plane(splited, configfile);
	else if (ft_strlen(*splited) == 2 && ft_strncmp(*splited, "sq", 2) == 0)
		err = save_new_square(splited, configfile);
	else if (ft_strlen(*splited) == 2 && ft_strncmp(*splited, "cy", 2) == 0)
		err = save_new_cylinder(splited, configfile);
	else if (ft_strlen(*splited) == 2 && ft_strncmp(*splited, "tr", 2) == 0)
		err = save_new_triangle(splited, configfile);
	else if (ft_strlen(*splited) == 2 && ft_strncmp(*splited, "py", 2) == 0)
		err = save_new_pyramid(splited, configfile);
	else if (ft_strlen(*splited) == 2 && ft_strncmp(*splited, "cu", 2) == 0)
		err = save_new_cube(splited, configfile);
	else if (ft_strlen(*splited) == 5 && ft_strncmp(*splited, "SEPIA", 5) == 0)
		configfile->sepia = 1;
	else
		err = ft_printf("Error: '%s' is a bad identifer\n", *splited);
	if (!err)
		return (0);
	else
		return (1);
}

int		save_rt_file(char **splited, t_file *configfile)
{
	int err;

	err = 0;
	if (*splited && *splited[0] != '#')
	{
		if (ft_strlen(*splited) == 1 && *splited[0] == 'R')
			err = save_res(splited, configfile);
		else if (ft_strlen(*splited) == 1 && *splited[0] == 'l')
			err = save_new_ligth(splited, configfile);
		else if (ft_strlen(*splited) == 1 && *splited[0] == 'A')
			err = save_ambient_ligth(splited, configfile);
		else if (ft_strlen(*splited) == 1 && *splited[0] == 'c')
			err = save_new_camera(splited, configfile);
		else if (ft_strlen(*splited) == 2 && ft_strncmp(*splited, "sp", 2) == 0)
			err = save_new_sphere(splited, configfile);
		else if (ft_strlen(*splited) == 12 &&
			ft_strncmp(*splited, "ANTIALIASING", 12) == 0)
			err = save_antialising(splited, configfile);
		else
			return (save_rt_file_aux1(splited, configfile));
	}
	return ((!err) ? 0 : (1));
}

int		read_file(int fd, t_file *configfile)
{
	char	*line;
	char	**line_splited;
	int		err;

	if (!(configfile->mlx_ptr = mlx_init()))
		return (parse_error("Minilibx Error: CAN NOT INITIALIZE MINILIBX"));
	err = 0;
	while (get_next_line(fd, &line) > 0)
	{
		line_splited = ft_split(line, ' ');
		if (BONUS == 1)
			err += save_rt_file(line_splited, configfile);
		else
			err += save_rt_file_no_bonus(line_splited, configfile);
		ft_bidimensional_free(line_splited);
		free(line);
	}
	line_splited = ft_split(line, ' ');
	err += (BONUS == 1) ? save_rt_file(line_splited, configfile) :
		save_rt_file_no_bonus(line_splited, configfile);
	free(line);
	ft_bidimensional_free(line_splited);
	close(fd);
	return ((err) ? 1 : 0);
}

int		read_rt_file(char *file, t_file *configfile)
{
	int fd;

	if (!ft_strnstr(file, ".rt", ft_strlen(file)))
	{
		ft_printf("Error\n      File Error: Input file is a non rt file\n");
		return (0);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n      File Error: no rt file named: %s\n", file);
		return (0);
	}
	if (read_file(fd, configfile) == 1)
		return (0);
	if (!configfile->first_cam ||
		!(configfile->ambient_ligth.rgb.r) || !configfile->win_width)
	{
		ft_printf("Error:\n	\
			Parse Error: No cam or No Rmbient Rigth or no Resolution\n");
		return (0);
	}
	if (!configfile->antialiasing)
		configfile->antialiasing = 1;
	return (1);
}

void	save_sq_points(t_square *sq)
{
	float side;

	side = sq->side / 2;
	if (fabs(sq->norm_v.y) == 1)
	{
		sq->rot_mat.v3 = esc_dot_vec(1, sq->norm_v);
		sq->rot_mat.v1 = esc_dot_vec(sq->norm_v.y, vector(1, 0, 0));
		sq->rot_mat.v2 = esc_dot_vec(sq->norm_v.y * -1, vector(0, 0, 1));
	}
	else
	{
		sq->rot_mat.v3 = esc_dot_vec(1, sq->norm_v);
		sq->rot_mat.v1 = prod_vec(vector(0, 1, 0), sq->norm_v);
		sq->rot_mat.v2 = prod_vec(sq->norm_v, sq->rot_mat.v1);
	}
	sq->points.p0 = sum_vec(vector_dot_matrix(
		vector(side * -1, side, -1), sq->rot_mat), sq->cord);
	sq->points.p1 = sum_vec(vector_dot_matrix(
			vector(side, side, -1), sq->rot_mat), sq->cord);
	sq->points.p2 = sum_vec(vector_dot_matrix(
			vector(side * -1, side * -1, -1), sq->rot_mat), sq->cord);
	sq->points.p3 = sum_vec(vector_dot_matrix(
			vector(side, side * -1, -1), sq->rot_mat), sq->cord);
}
