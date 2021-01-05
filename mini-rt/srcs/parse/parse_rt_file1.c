/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_file1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:15:34 by pablo             #+#    #+#             */
/*   Updated: 2021/01/05 18:25:47 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"


t_canvas save_canvas(float fov,t_file c)
{
	t_canvas canvas;

	canvas.canvas_w = 2*tan((fov/2) *( M_PI / 180));
	canvas.canvas_h = canvas.canvas_w / c.aspect_ratio;
	canvas.matrix.v3 = ((t_camera *)c.camera->content)->norm_v);
	return (canvas);
}

int save_res(char **splited, t_file *configFile)
{
	int err;

	err = 0;
	if (configFile->win_heigth)
		return (parse_error("Resolution  Error: Only 1 Resolution  can be defined \n"));
	if (ft_bistrlen(splited) != 3)
		return parse_error("Resolution Error: Bad number of arguments \n");
	else if (!ft_str_isnum(splited[1]) || !ft_str_isnum(splited[2]))
		err += parse_error("Resolution Error: bad formated");
	configFile->win_width = atoi(splited[1]);
	configFile->win_heigth = atoi(splited[2]);
	configFile->aspect_ratio = (float)configFile->win_width / (float)configFile->win_heigth;
	if (err)
		return (1);
	return (0);
}
int save_ambient_ligth(char **splited, t_file *configFile)
{
	int err;

	err = 0;
	if (configFile->ambient_ligth.ratio)
		return (parse_error("Ambient Ligth Error: Only 1 Ambient ligth can be defined \n"));
	if (ft_bistrlen(splited) != 3)
		return (parse_error("Ambient Ligth Error: Bad number of arguments \n"));
	if (!ft_isfloat(splited[1]))
		return (parse_error("Ambient Ligth Error: Bad value for lighting ratio \n"));
	configFile->ambient_ligth.ratio = ft_atof(splited[2]);
	err += save_rgb(&configFile->ambient_ligth.rgb, splited[2], "Ambient Light");
	if (err)
		return (1);
	return (0);
}
int save_new_ligth(char **splited, t_file *configFile)
{
	t_ligth *ligth;
	int err;

	err = 0;
	if (ft_bistrlen(splited) != 4)
		return (parse_error("Ligth Error: Bad number of arguments \n"));
	if (!ft_isfloat(splited[2]))
		return (parse_error("Ligth Error: Bad value for brigthness \n"));
	if (!(ligth = malloc(1 * sizeof(t_ligth))))
		return (parse_error("Ligth Error: Malloc error on t_ligth\n"));
	err += save_cord(&ligth->cord, splited[1], "Light");
	ligth->brigthness = ft_atof(splited[2]);
	err += save_rgb(&ligth->rgb, splited[3], "Ligth");
	ft_lstadd_back(&configFile->ligth, ft_lstnew(ligth));
	if (err)
	{
		//free(ligth);
		return (1);
	}
	return (0);
}
int save_new_camera(char **splited, t_file *configFile)
{
	t_camera *camera;
	int err;

	err = 0;
	if (ft_bistrlen(splited) != 4)
		return (parse_error("Camera Error: Bad number of arguments \n"));
	if (!(ft_str_isnum(splited[3]) && (atoi(splited[3]) >= 0 && atoi(splited[3]) <= 180)))
		return (parse_error("Camera Error: Bad value for FOV \n"));
	if (!(camera = malloc(1 * sizeof(t_camera))))
		return (parse_error("Camera Error: Malloc error on t_camera\n"));
	err += save_cord(&camera->cord, splited[1], "Camera");
	err += save_cord(&camera->norm_v, splited[2], "Camera");
	if (!is_norm_vec(&camera->norm_v))
		err += (parse_error("Camera Error: vector not normalized \n"));
	camera->fov = atoi(splited[3]);
	camera->canvas = save_canvas(camera->fov,*configFile);
	ft_lstadd_back(&configFile->camera, ft_lstnew(camera));
	if (err)
	{
		//free(camera);
		return (1);
	}
	return (0);
}
