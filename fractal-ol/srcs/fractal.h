/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 23:05:01 by pablo             #+#    #+#             */
/*   Updated: 2021/06/13 16:19:02 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <math.h>
#define THREADS 4
#define PRECISION 100

typedef struct s_img
{
	void *mlx_img;
	char *address;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_img;
typedef struct s_julia
{
	double x;
	double y;
	double move_x;
	double move_y;
	long double zoom;
	long double zoom_value;
} t_julia;


typedef struct s_fractal
{
	void *mlx_ptr;
	void *win_ptr;
	int win_heigth;
	int win_width;
	double move_x;
	double move_y;
	long double zoom;
	long double zoom_value;
	int 		is_julia;
	int 		precision;
	t_julia		*julia;
	t_img img;

} t_fractal;


typedef struct s_threads
{
	unsigned int thread;
	t_fractal *f;
} t_threads;

typedef struct s_range
{
	double start;
	double end;
} t_range;
/*mlx*/
void my_mlx_pixel_put(t_img *data, int x, int y, int color);

int exit_win(t_fractal *f);
/*colors*/
int int_from_rgb(int r, int g, int b);
