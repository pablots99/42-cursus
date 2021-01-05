/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:15:09 by pablo             #+#    #+#             */
/*   Updated: 2021/01/05 18:23:51 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>

typedef struct s_canvas
{
	float canvas_w;
	float canvas_h;
	t_matrix matrix;
} t_canvas;

typedef struct s_cord
{
	float x;
	float y;
	float z;
} t_cord;
typedef struct s_rgb
{
	int r;
	int g;
	int b;
} t_rgb;
typedef struct s_matrix
{
	t_cord v1;
	t_cord v2;
	t_cord v3;
} t_matrix;
typedef struct s_ambient_ligth
{
	float ratio;
	t_rgb rgb;
} t_ambient_ligth;

typedef struct s_ligth
{
	t_cord cord;
	float brigthness;
	t_rgb rgb;
} t_ligth;
typedef struct s_camera
{
	t_cord cord;
	t_cord norm_v;
	int fov;
	t_canvas canvas;
} t_camera;
typedef struct s_sphere
{
	t_cord cord;
	float diameter;
	t_rgb rgb;
} t_sphere;
typedef struct s_plane
{
	t_cord cord;
	t_cord norm_v;
	t_rgb rgb;

} t_plane;
typedef struct s_square
{
	t_cord cord;
	t_cord norm_v;
	float side;
	t_rgb rgb;

} t_square;
typedef struct s_cylinder
{
	t_cord cord;
	t_cord norm_v;
	float diameter;
	float height;
	t_rgb rgb;

} t_cylinder;
typedef struct s_triangle
{
	t_cord cord_1;
	t_cord cord_2;
	t_cord cord_3;
	t_rgb rgb;

} t_triangle;
typedef struct s_ray
{
	t_cord origin;
	t_cord direction;
	float len;
} t_ray;

typedef struct s_file
{
	void *mlx_ptr;
	void *win_ptr;
	int win_heigth;
	int win_width;
	float aspect_ratio;
	t_ambient_ligth ambient_ligth;
	t_list *camera;
	t_list *ligth;
	t_list *sphere;
	t_list *plane;
	t_list *square;
	t_list *cylinder;
	t_list *triangle;
} t_file;

int read_rt_file(char *file, t_file *configFile);

int parse_error(char *err);

int save_cord(t_cord *cord, char *vec, char *msg);

int save_rgb(t_rgb *rgb, char *vec, char *msg);

int ft_isfloat(char *num);

int is_norm_vec(t_cord *cord);

char *ft_clean_spaces(char *str);

void free_config(t_file *c);

int exit_win(int keycode, t_file *c);

int exit_win2(t_file *c);

t_cord norm_vec(t_cord cord);

void ft_bidimensional_free(char **arr);

int ft_str_isnum(char *num);

int ft_bistrlen(char **str);

float ft_atof(char *num);

t_ray generate_ray(int x, int y, t_file c);

float mod_vec(t_cord v);
