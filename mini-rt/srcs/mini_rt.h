/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:15:09 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 17:04:28 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <pthread.h>

# define SPHERE 1
# define CAMERA 2
# define SQUARE 3
# define PLANE 4
# define TRIANGLE 5
# define CYLINDER 6
# define LIGTH 7
# define PYRAMID 8
# define CUBE 9

# define BIAS 1
# define ROT_ANGLE 50
# define NREFLEXIONS 10
# if !defined BONUS
#  define BONUS 1
# endif
# if !BONUS
#  define THREADS 1
# else
#  define THREADS 8
# endif

typedef struct	s_cord
{
	float x;
	float y;
	float z;
}				t_cord;

typedef struct	s_sqpoints
{
	t_cord p0;
	t_cord p1;
	t_cord p2;
	t_cord p3;
}				t_sqpoints;

typedef struct	s_matrix
{
	t_cord v1;
	t_cord v2;
	t_cord v3;
}				t_matrix;

typedef struct	s_canvas
{
	float		canvas_w;
	float		canvas_h;
	t_matrix	matrix;
}				t_canvas;

typedef struct	s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct	s_ambient_ligth
{
	float	ratio;
	t_rgb	rgb;
}				t_ambient_ligth;

typedef struct	s_ligth
{
	t_cord	cord;
	float	brigthness;
	t_rgb	rgb;
}				t_ligth;

typedef struct	s_camera
{
	t_cord		cord;
	t_cord		norm_v;
	int			fov;
	t_canvas	canvas;
}				t_camera;

typedef struct	s_plane
{
	t_cord	cord;
	t_cord	norm_v;
	t_rgb	rgb;
	float	refraction;
	int		specular;
}				t_plane;

typedef struct	s_square
{
	t_cord		cord;
	t_cord		norm_v;
	float		side;
	t_rgb		rgb;
	float		angle;
	t_sqpoints	points;
	float		refraction;
	int			specular;
	t_matrix	rot_mat;
}				t_square;

typedef struct	s_cylinder
{
	t_cord	cord;
	t_cord	norm_v;
	float	diameter;
	float	height;
	t_rgb	rgb;
	float	refraction;
	int		specular;

}				t_cylinder;

typedef struct	s_triangle
{
	t_cord	cord_1;
	t_cord	cord_2;
	t_cord	cord_3;
	t_rgb	rgb;
	t_cord	norm_v;
	float	refraction;
	int		specular;
}				t_triangle;

typedef struct	s_ray
{
	t_cord	origin;
	t_cord	direction;
	t_cord	normal;
	int		object;
	float	refraction;
	float	reflexion;
	int		specular;
	float	len;
}				t_ray;

typedef struct	s_img
{
	void	*mlx_img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_bmp
{
	int		width;
	int		heigth;
	t_img	img;
}				t_bmp;

typedef struct	s_sphere
{
	t_cord	cord;
	float	diameter;
	t_rgb	rgb;
	float	refraction;
	t_bmp	bmp;
	int		mapping;
	int		specular;
	t_bmp	bump;
}				t_sphere;

typedef struct	s_cube
{
	t_cord		norm_vec;
	t_cord		cord;
	float		width;
	t_rgb		rgb;
	t_square	face1;
	t_square	face2;
	t_square	face3;
	t_square	face4;
	t_square	face5;
	t_square	face6;
	float		reflexion;
	int			specular;
}				t_cube;

typedef struct	s_pyramid
{
	t_cord		cord;
	t_cord		norm_vec;
	float		width;
	float		heigth;
	t_rgb		rgb;
	float		reflexion;
	int			specular;
	t_triangle	tr1;
	t_triangle	tr2;
	t_triangle	tr3;
	t_triangle	tr4;
	t_square	base;
}				t_pyramid;

typedef struct	s_shades
{
	float		specular;
	float		difuse;
	t_ligth		ligth;
	t_rgb		ligth_color;
}				t_shades;

typedef struct	s_file
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_heigth;
	int				win_width;
	int				n_reflexions;
	float			aspect_ratio;
	int				cam_count;
	int				sp_count;
	int				py_count;
	int				sq_count;
	int				tr_count;
	int				cu_count;
	int				l_count;
	int				antialiasing;
	int				pl_count;
	int				cy_count;
	int				obj_selected;
	int				sepia;
	t_img			img;
	t_ambient_ligth	ambient_ligth;
	t_list			*first_cam;
	t_list			*camera;
	t_list			*curr_l;
	t_list			*ligth;
	t_list			*curr_sp;
	t_list			*sphere;
	t_list			*curr_py;
	t_list			*pyramid;
	t_list			*curr_cu;
	t_list			*cube;
	t_list			*curr_pl;
	t_list			*plane;
	t_list			*curr_sq;
	t_list			*square;
	t_list			*curr_cy;
	t_list			*cylinder;
	t_list			*curr_tr;
	t_list			*triangle;
}				t_file;

typedef struct	s_threads
{
	unsigned int	thread;
	t_file			*c;
}				t_threads;

int				read_rt_file(char *file, t_file *configfile);

int				parse_error(char *err);

int				save_cord(t_cord *cord, char *vec, char *msg);

int				save_rgb(t_rgb *rgb, char *vec, char *msg);

int				ft_isfloat(char *num);

int				is_norm_vec(t_cord *cord);

char			*ft_clean_spaces(char *str);

void			free_config(t_file *c);

int				exit_win(int keycode, t_file *c);

int				exit_win2(t_file *c);

t_cord			norm_vec(t_cord cord);

void			ft_bidimensional_free(char **arr);

int				ft_str_isnum(char *num);

int				ft_bistrlen(char **str);

float			ft_atof(char *num);

t_ray			generate_ray(int x, int y, t_file c, float r1[2]);

float			mod_vec(t_cord v);

t_cord			prod_vec(t_cord v1, t_cord v2);

t_cord			vector_dot_matrix(t_cord v, t_matrix matrix);

t_cord			esc_dot_vec(float num, t_cord c);

int				get_intersections(t_ray *ray, t_file *c);

int				spheres_intersection(t_ray *ray, t_list *list, t_file *c);

int				ambient_color(t_rgb color, t_ambient_ligth ambient);

float			prod_esc(t_cord v1, t_cord v2);

float			rad_ang_vec(t_cord v1, t_cord v2);

float			proy_vect(t_cord v1, t_cord v2);

int				plane_intersection(t_ray *ray, t_list *plane);

t_cord			sum_vec(t_cord v1, t_cord v2);

t_cord			rest_vec(t_cord v1, t_cord v2);

int				shading(t_ray *ray, int color, t_file *c);

t_cord			vector(float x, float y, float z);

int				create_shade_color(t_rgb color, t_ligth ligth,
					float brigth, float specular);

t_rgb			rgb_from_int(int color);

t_cord			ray_cut_point(t_ray ray);

int				cylinder_intersection(t_ray *ray, t_list *list);

int				get_pl_inter(t_ray *ray, t_plane pl);

int				square_intersection(t_ray *ray, t_list *plane);

t_cord			ray_intersection(t_ray ray, float len);

int				triangle_intersection(t_ray *ray, t_list *plane);

t_cord			barycentric_cords(t_triangle tr, t_cord point);

int				select_camera(t_file *c);

int				detect_key(int keycode, t_file *c);

void			paint_scene(void *a);

void			my_mlx_pixel_put(t_img *data, int x, int y, int color);

void			adjust_res(t_file *c);

int				int_from_rgb(int r, int g, int b);

void			move_sphere(t_sphere *sp, int axis);

void			size_sphere(t_sphere *sp, int k);

void			move_camera(t_camera *c, int axis);

void			zoom_camera(t_camera *c, int k);

int				select_camera(t_file *c);

int				select_sp(t_file *c);

int				get_tr_inter(t_ray *ray, t_triangle tr);

int				get_sq_inter(t_ray *ray, t_square *sq);

int				get_pl_inter(t_ray *ray, t_plane pl);

int				get_cy_inter(t_ray *ray, t_cylinder cy);

int				get_sp_inter(t_ray *ray, t_sphere sp, t_file *c);

t_cord			rot_center_point(t_cord p, int ang);

void			save_sq_points(t_square *sq);

t_triangle		new_triangle(t_cord p1, t_cord p2, t_cord p3);

int				select_sq(t_file *c);

void			size_square(t_square *sq, int k);

void			move_square(t_square *sq, int axis);

float			max_float(float a, float b);

t_ray			reflected_ray(t_ray *ray);

float			min_float(float a, float b);

t_rgb			sum_colors(t_rgb c1, t_rgb c2);

int				select_cy(t_file *c);

void			size_cylinder(t_cylinder *cy, int k);

void			move_cylinder(t_cylinder *cy, int axis);

void			sum_vec2(float num, float *x, float *y, float *z);

void			size_triangle(t_triangle *tr, int k);

void			move_triangle(t_triangle *tr, int axis);

int				select_tr(t_file *c);

int				select_pl(t_file *c);

void			move_plane(t_plane *pl, int axis);

int				min_int(int a, int b);

int				sum_int_colors(int color1, int color2);

int				get_shadow_intersections(t_ray ray, t_file c);

int				threats(t_file *c, int save);

int				create_bmp_file(t_file *c, char *file);

int				get_sp_inter_analitic(t_ray *ray, t_sphere sp, t_file *c);

t_bmp			read_bmp(char *file, t_file *c);

int				sp_bmp(t_ray ray, t_bmp bmp, t_sphere sp);

t_canvas		save_canvas(t_camera *cam, t_file c);

void			rot_cam(t_camera *camera, int key);

t_cord			rot_vec_z(t_cord vec, int a);

t_cord			rot_vec_y(t_cord vec, int a);

t_cord			rot_vec_x(t_cord vec, int a);

void			rot_cy(t_cylinder *cy, int key);

void			rot_pl(t_plane *pl, int key);

void			rot_sq(t_square *sq, int key);

int				select_l(t_file *c);

void			change_ligth_intesity(t_ligth *l, int k);

void			move_ligth(t_ligth *l, int axis);

void			sp_bump(t_ray ray, t_bmp bmp, t_sphere sp);

void			paint_scene(void *a);

int				average_color(int *color, int base, t_file *con);

float			rand_unit_float();

void			init_int_arr(int *color, int n);

int				create_shade_color2(t_rgb color, t_shades sh);

void			rot_sq(t_square *sq, int key);

void			save_py_faces(t_pyramid *pyramid);

int				pyramid_intersection(t_ray *ray, t_list *list);

int				get_py_inter(t_ray *ray, t_pyramid py);

int				select_py(t_file *c);

void			move_pyramid(t_pyramid *py, int axis);

void			rot_py(t_pyramid *py, int key);

int				cube_intersection(t_ray *ray, t_list *list);

int				get_cu_inter(t_ray *ray, t_cube cu);

void			save_cube_faces(t_cube *cu);

void			move_cube(t_cube *cu, int axis);

int				select_cu(t_file *c);

void			rot_cu(t_cube *cu, int key);

void			save_base_py(t_pyramid *pyramid);

void			save_cube_base(t_cube *cu, int cond);

void			select_object(t_file *c);

void			select_type_object(t_file *c);

void			move_objects(t_file *c, int key);

void			size_cu(t_cube *cu, int k);

#endif
