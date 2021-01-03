/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:13:39 by pablo             #+#    #+#             */
/*   Updated: 2021/01/03 21:44:58 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int save_res(char **splited,t_file *configFile);



int save_new_ligth(char **splited, t_file *configFile);

int save_ambient_ligth(char **splited, t_file *configFile);

int save_new_camera(char **splited, t_file *configFile);

int save_new_sphere(char **splited, t_file *configFile);

int save_new_plane(char **splited, t_file *configFile);

int save_new_square(char **splited, t_file *configFile);

int save_new_cylinder(char **splited, t_file *configFile);

int save_new_triangle(char **splited, t_file *configFile);

t_canvas save_canvas(float fov);


