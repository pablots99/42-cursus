/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:13:39 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 15:52:03 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_FILE_H
# define RT_FILE_H

int		save_res(char **splited, t_file *configfile);

int		save_new_ligth(char **splited, t_file *configfile);

int		save_ambient_ligth(char **splited, t_file *configfile);

int		save_new_camera(char **splited, t_file *configfile);

int		save_new_sphere(char **splited, t_file *configfile);

int		save_new_plane(char **splited, t_file *configfile);

int		save_new_square(char **splited, t_file *configfile);

int		save_new_cylinder(char **splited, t_file *configfile);

int		save_new_triangle(char **splited, t_file *configfile);

int		save_rt_file_no_bonus(char **splited, t_file *configfile);

int		save_new_camera_no(char **splited, t_file *configfile);

int		save_new_sphere_no(char **splited, t_file *configfile);

int		save_new_plane_no(char **splited, t_file *configfile);

int		save_new_square_no(char **splited, t_file *configfile);

int		save_new_cylinder_no(char **splited, t_file *configfile);

int		save_new_triangle_no(char **splited, t_file *configfile);

int		save_new_cube(char **splited, t_file *configfile);

int		save_new_pyramid(char **splited, t_file *configfile);

int		get_py_inter(t_ray *ray, t_pyramid py);

int		save_antialising(char **splited, t_file *configfile);

int		read_file(int fd, t_file *configfile);

#endif
