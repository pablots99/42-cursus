/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:15:09 by pablo             #+#    #+#             */
/*   Updated: 2021/01/02 18:39:08 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include "./utils/utils.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>

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
} t_camera;
typedef struct s_sphere
{
	t_cord cord;
	float diameter;
	t_rgb rgb;
}		t_sphere;
typedef struct s_plane
{
	t_cord cord;
	t_cord norm_v;
	t_rgb	rgb;

}		t_plane;
typedef struct s_square
{
	t_cord cord;
	t_cord norm_v;
	float side;
	t_rgb	rgb;

}		t_square;
typedef struct s_cylinder
{
	t_cord cord;
	t_cord norm_v;
	float diameter;
	float  height;
	t_rgb	rgb;

}		t_cylinder;
typedef struct s_triangle
{
	t_cord cord_1;
	t_cord cord_2;
	t_cord cord_3;
	t_rgb	rgb;

}		t_triangle;
typedef struct s_file
{
    void *mlx_ptr;
    void *win_ptr;
    int win_heigth;
    int win_width;
    t_ambient_ligth ambient_ligth;
    t_list *camera;
    t_list *ligth;
    t_list *sphere;
    t_list *plane;
    t_list *square;
    t_list *cylinder;
    t_list *triangle;
}               t_file;

int read_rt_file(char *file, t_file *configFile);

int parse_error(char *err);

int save_cord(t_cord *cord,char *vec,char *msg);

int save_rgb(t_rgb *rgb,char *vec,char *msg);

int ft_isfloat(char *num);

int is_norm_vec(t_cord *cord);

char* ft_clean_spaces(char *str);

void free_config(t_file *c);





