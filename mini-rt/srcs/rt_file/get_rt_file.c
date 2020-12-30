/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rt_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:39:35 by pablo             #+#    #+#             */
/*   Updated: 2020/12/30 22:06:40 by ptorres          ###   ########.fr       */
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
	if (!err)
		return (0);
	else
		return (1);
}

int save_rt_file_aux(char **splited, t_file *configFile)
{

	int err;

	err = 0;
	if (*splited[0] == 'R' && ft_strlen(*splited) == 1)
		err = save_res(splited, configFile);
	else if (*splited[0] == 'l' && ft_strlen(*splited) == 1)
		err = save_new_ligth(splited, configFile);
	else if (*splited[0] == 'A' && ft_strlen(*splited) == 1)
		err = save_ambient_ligth(splited, configFile);
	else if (*splited[0] == 'c' && ft_strlen(*splited) == 1)
		err = save_new_camera(splited, configFile);
	else if (ft_strlen(*splited) == 2 && ft_strncmp(*splited, "sp", 2) == 0)
		err = save_new_sphere(splited, configFile);
	else
		return (-1);
	if (!err)
		return (0);
	else
		return (1);
}
int save_rt_file(char **splited, t_file *configFile)
{
	int err;

	err = 0;
	if (splited[0])
	{
		err = save_rt_file_aux(splited, configFile);
		if (err == -1)
			err = save_rt_file_aux1(splited, configFile);
		if (err)
			return ft_printf("Error: '%s' is a bad identifer\n", *splited);
	}
	return (0);
}
int read_file(int fd, t_file *configFile)
{
	char *line;
	char **line_splited;
	int err;

	err = 0;
	while (get_next_line(fd, &line) > 0)
	{
		//line = ft_clean_spaces(line);
		line_splited = ft_split(line, ' ');
		err += save_rt_file(line_splited, configFile);
		ft_bidimensional_free(line_splited);
		free(line);
	}
	//line = ft_clean_spaces(line);
	// line_splited = ft_split(ft_clean_spaces(line), ' ');
	// err += save_rt_file(line_splited, configFile);
	// ft_bidimensional_free(line_splited);
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