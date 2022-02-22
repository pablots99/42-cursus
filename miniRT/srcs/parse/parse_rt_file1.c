/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_file1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:15:34 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 15:34:18 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_canvas	save_canvas(t_camera *cam, t_file c)
{
	t_canvas canvas;

	canvas.canvas_w = 2 * tan((cam->fov / 2) * (M_PI / 180)) * c.aspect_ratio;
	canvas.canvas_h = 2 * tan((cam->fov / 2) * (M_PI / 180));
	if (fabs(cam->norm_v.y) == 1)
	{
		canvas.matrix.v3 = esc_dot_vec(1, cam->norm_v);
		canvas.matrix.v1 = esc_dot_vec(cam->norm_v.y, vector(1, 0, 0));
		canvas.matrix.v2 = esc_dot_vec(cam->norm_v.y * -1, vector(0, 0, 1));
	}
	else
	{
		cam->norm_v.z *= -1;
		canvas.matrix.v3 = esc_dot_vec(1, cam->norm_v);
		canvas.matrix.v1 = prod_vec(vector(0, 1, 0), cam->norm_v);
		canvas.matrix.v2 = prod_vec(cam->norm_v, canvas.matrix.v1);
	}
	return (canvas);
}

int			save_res(char **splited, t_file *configfile)
{
	int err;

	err = 0;
	if (configfile->win_heigth)
		return (parse_error("Resolution  Error:Only 1 Resolution\n"));
	if (ft_bistrlen(splited) != 3)
		return (parse_error("Resolution Error: Bad number of arguments \n"));
	else if (!ft_str_isnum(splited[1]) || !ft_str_isnum(splited[2]))
		err += parse_error("Resolution Error: bad formated");
	configfile->win_width = atoi(splited[1]);
	configfile->win_heigth = atoi(splited[2]);
	configfile->aspect_ratio = (float)configfile->win_width /
		(float)configfile->win_heigth;
	if (err)
		return (1);
	return (0);
}

int			save_ambient_ligth(char **splited, t_file *configfile)
{
	int err;

	err = 0;
	if (configfile->ambient_ligth.ratio)
		return (parse_error("Ambient Ligth Error: Only 1 Ambient ligth\n"));
	if (ft_bistrlen(splited) != 3)
		return (parse_error("Ambient Ligth Error: Bad number of arguments \n"));
	if (!ft_isfloat(splited[1]))
		return (parse_error("Ambient Ligth Error: lighting ratio \n"));
	configfile->ambient_ligth.ratio = ft_atof(splited[1]);
	err += save_rgb(&configfile->ambient_ligth.rgb,
		splited[2], "Ambient Light");
	if (err)
		return (1);
	return (0);
}

int			save_new_ligth(char **splited, t_file *configfile)
{
	t_ligth	*ligth;
	int		err;

	err = 0;
	if (ft_bistrlen(splited) != 4)
		return (parse_error("Ligth Error: Bad  arguments \n"));
	if (!ft_isfloat(splited[2]))
		return (parse_error("Ligth Error: Bad value for brigthness \n"));
	if (!(ligth = malloc(1 * sizeof(t_ligth))))
		return (parse_error("Ligth Error: Malloc error on t_ligth\n"));
	err += save_cord(&ligth->cord, splited[1], "Light");
	ligth->brigthness = ft_atof(splited[2]);
	err += save_rgb(&ligth->rgb, splited[3], "Ligth");
	ft_lstadd_back(&configfile->ligth, ft_lstnew(ligth));
	if (err)
		return (1);
	return (0);
}

int			save_new_camera(char **splited, t_file *configfile)
{
	t_camera	*camera;
	int			err;

	err = 0;
	if (ft_bistrlen(splited) != 4)
		return (parse_error("Camera Error: Bad number of arguments \n"));
	if (!(ft_str_isnum(splited[3]) && (atoi(splited[3]) >= 0
		&& atoi(splited[3]) <= 180)))
		return (parse_error("Camera Error: Bad value for FOV \n"));
	if (!(camera = malloc(1 * sizeof(t_camera))))
		return (parse_error("Camera Error: Malloc error on t_camera\n"));
	err += save_cord(&camera->cord, splited[1], "Camera");
	err += save_cord(&camera->norm_v, splited[2], "Camera");
	camera->norm_v = norm_vec(camera->norm_v);
	camera->fov = atoi(splited[3]);
	ft_lstadd_back(&configfile->camera, ft_lstnew(camera));
	if (err)
		return (1);
	camera->canvas = save_canvas(camera, *configfile);
	if (!configfile->first_cam && configfile->camera)
		configfile->first_cam = configfile->camera;
	configfile->cam_count = 1;
	return (0);
}
