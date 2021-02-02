/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_no_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:00:12 by ptorres           #+#    #+#             */
/*   Updated: 2021/02/02 12:08:00 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"
#include "./rt_file.h"

int save_rt_file_aux1_no(char **splited, t_file *configFile)
{
	int err;

	err = 0;
	if (ft_strlen(*splited) == 2 && ft_strncmp(*splited, "pl", 2) == 0)
		err = save_new_plane_no(splited, configFile);
	else if (ft_strlen(*splited) == 2 && ft_strncmp(*splited, "sq", 2) == 0)
		err = save_new_square_no(splited, configFile);
	else if (ft_strlen(*splited) == 2 && ft_strncmp(*splited, "cy", 2) == 0)
		err = save_new_cylinder_no(splited, configFile);
	else if (ft_strlen(*splited) == 2 && ft_strncmp(*splited, "tr", 2) == 0)
		err = save_new_triangle_no(splited, configFile);
	else
		err = ft_printf("Error: '%s' is a bad identifer\n", *splited);
	if (!err)
		return (0);
	else
		return (1);
}

int save_rt_file_no_bonus(char **splited, t_file *configFile)
{

	int err;

	err = 0;
	if (*splited && *splited[0] != '#')
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
			err = save_new_sphere_no(splited, configFile);
		else
			return save_rt_file_aux1_no(splited, configFile);
	}
	return ((!err) ? 0 : 1);
}