/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:13:39 by pablo             #+#    #+#             */
/*   Updated: 2021/02/15 23:14:33 by pablo            ###   ########.fr       */
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

int save_rt_file_no_bonus(char **splited, t_file *configFile);

int save_new_camera_no(char **splited, t_file *configFile);

int save_new_sphere_no(char **splited, t_file *configFile);

int save_new_plane_no(char **splited, t_file *configFile);

int save_new_square_no(char **splited, t_file *configFile);

int save_new_cylinder_no(char **splited, t_file *configFile);

int save_new_triangle_no(char **splited, t_file *configFile);

int save_new_cube(char **splited, t_file *configFile);

int save_new_pyramid(char **splited, t_file *configFile);

int get_py_inter(t_ray *ray, t_pyramid py);

int save_antialising(char **splited, t_file *configFile);


