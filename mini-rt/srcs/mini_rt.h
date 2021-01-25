/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:15:09 by pablo             #+#    #+#             */
/*   Updated: 2021/01/24 18:03:24 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>

#define SPHERE 1
#define CAMERA 2
#define SQUARE 3
#define PLANE 4
#define TRIANGLE 5
#define CYLINDER 6

#define SPECULAR_EXPONENT 50
#define SPECULAR_KS 0.01
#define BIAS 1

typedef struct s_cord
{
	float x;
	float y;
	float z;
} t_cord;

typedef struct s_sqpoints
{
	t_cord p0;
	t_cord p1;
	t_cord p2;
	t_cord p3;

} t_sqpoints;

typedef struct s_matrix
{
	t_cord v1;
	t_cord v2;
	t_cord v3;
} t_matrix;
typedef struct s_canvas
{
	float canvas_w;
	float canvas_h;
	t_matrix matrix;
} t_canvas;

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
	t_canvas canvas;
} t_camera;
typedef struct s_sphere
{
	t_cord cord;
	float diameter;
	t_rgb rgb;
	float refraction;

} t_sphere;
typedef struct s_plane
{
	t_cord cord;
	t_cord norm_v;
	t_rgb rgb;
	float refraction;

} t_plane;
typedef struct s_square
{
	t_cord cord;
	t_cord norm_v;
	float side;
	float angle;
	t_rgb rgb;
	t_sqpoints points;
	float refraction;

} t_square;
typedef struct s_cylinder
{
	t_cord cord;
	t_cord norm_v;
	float diameter;
	float height;
	t_rgb rgb;
	float refraction;
} t_cylinder;
typedef struct s_triangle
{
	t_cord cord_1;
	t_cord cord_2;
	t_cord cord_3;
	t_rgb rgb;
	float refraction;

} t_triangle;
typedef struct s_ray
{
	t_cord origin;
	t_cord direction;
	t_cord normal;
	int object;
	float refraction;
	float len;
} t_ray;
typedef struct s_img
{
	void *mlx_img;
	char *address;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_img;

typedef struct s_file
{
	void *mlx_ptr;
	void *win_ptr;
	int win_heigth;
	int win_width;
	float aspect_ratio;
	int cam_count;
	int sp_count;
	int sq_count;
	int tr_count;
	int pl_count;
	int cy_count;
	int obj_selected;
	t_img img;
	t_ambient_ligth ambient_ligth;
	t_list *first_cam;
	t_list *camera;
	t_list *ligth;
	t_list *curr_sp;
	t_list *sphere;
	t_list *curr_pl;
	t_list *plane;
	t_list *curr_sq;
	t_list *square;
	t_list *curr_cy;
	t_list *cylinder;
	t_list *curr_tr;

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

t_cord prod_vec(t_cord v1, t_cord v2);

t_cord vector_dot_matrix(t_cord v, t_matrix matrix);

t_cord esc_dot_vec(float num, t_cord c);

int get_intersections(t_ray *ray, t_file *c);

int spheres_intersection(t_ray *ray, t_list *list);

int ambient_color(t_rgb color, t_ambient_ligth ambient);

float prod_esc(t_cord v1, t_cord v2);

float rad_ang_vec(t_cord v1, t_cord v2);

float proy_vect(t_cord v1, t_cord v2); //V2 SOBRE V1

int plane_intersection(t_ray *ray, t_list *plane);

t_cord sum_vec(t_cord v1, t_cord v2);

t_cord rest_vec(t_cord v1, t_cord v2);

int shading(t_ray *ray, int color, t_file *c);

t_cord vector(float x, float y, float z);

int create_shade_color(t_rgb color, t_ligth ligth,float brigth,float specular);

t_rgb rgb_from_int(int color);

t_cord ray_cut_point(t_ray ray);

int cylinder_intersection(t_ray *ray, t_list *list);

int get_pl_inter(t_ray *ray, t_plane pl);

int square_intersection(t_ray *ray, t_list *plane);

t_cord ray_intersection(t_ray ray, float len);

int triangle_intersection(t_ray *ray, t_list *plane);

t_cord barycentric_cords(t_triangle tr, t_cord point);

int select_camera(t_file *c);

int detect_key(int keycode, t_file *c);

void paint_scene(t_file *c);

void my_mlx_pixel_put(t_img *data, int x, int y, int color);

void adjust_res(t_file *c);

int int_from_rgb(int r, int g, int b);

void move_sphere(t_sphere *sp, int axis);

void size_sphere(t_sphere *sp, int k);

void move_camera(t_camera *c, int axis);

void zoom_camera(t_camera *c, int k);

int select_camera(t_file *c);

int select_sp(t_file *c);

int get_tr_inter(t_ray *ray, t_triangle tr);

int get_sq_inter(t_ray *ray, t_square sq);

int get_pl_inter(t_ray *ray, t_plane pl);

int get_cy_inter(t_ray *ray, t_cylinder cy);

int get_sp_inter(t_ray *ray, t_sphere sp);

t_cord rot_center_point(t_cord p, int ang);

void save_sq_points(t_square *sq);

t_triangle new_triangle(t_cord p1, t_cord p2, t_cord p3);

int select_sq(t_file *c);

void size_square(t_square *sq, int k);

void move_square(t_square *sq, int axis);

void rot_square(t_square *sq, int k);

float max_float(float a, float b);

t_ray refracted_ray(t_ray *ray);

float min_float(float a, float b);

t_rgb sum_colors(t_rgb c1,t_rgb c2);

int select_cy(t_file *c);

void size_cylinder(t_cylinder *cy, int k);

void move_cylinder(t_cylinder *cy, int axis);

void sum_vec2(float num,float *x,float *y,float *z);

void size_triangle(t_triangle *tr, int k);

void move_triangle(t_triangle *tr, int axis);

int select_tr(t_file *c);

int select_pl(t_file *c);

void move_plane(t_plane *pl, int axis);