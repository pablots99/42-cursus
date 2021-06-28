/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 23:05:01 by pablo             #+#    #+#             */
/*   Updated: 2021/06/21 18:47:39 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <pthread.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# define THREADS 50
# define PRECISION 80

typedef struct s_img
{
	void	*mlx_img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;
typedef struct s_rgb{
	double	r;
	double	g;
	double	b;
}			t_rgb;

typedef struct s_hsv{
	double	h;
	double	s;
	double	v;
}			t_hsv;

typedef struct s_julia
{
	double		x;
	double		y;
	double		move_x;
	double		move_y;
	long double	zoom;
	long double	zoom_value;
}				t_julia;

typedef struct s_fractal
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_heigth;
	int			win_width;
	double		move_x;
	double		move_y;
	long double	zoom;
	long double	zoom_value;
	int			is_julia;
	int			is_fullJulia;
	int			precision;
	t_julia		*julia;
	t_img		img;
}				t_fractal;

typedef struct s_threads
{
	unsigned int	thread;
	t_fractal		*f;
}					t_threads;

typedef struct s_range
{
	double	start;
	double	end;
}			t_range;

void		my_mlx_pixel_put(t_img *data, int x, int y, int color);

int			exit_win(t_fractal *f);

int			int_from_rgb(int r, int g, int b);

t_rgb		hsv2rgb(t_hsv in);

int			get_color(t_fractal t, int z);

long double	resize_value(double value, t_range initial, t_range new);

int			mouse_actions(int button, int x, int y, t_fractal *f);

int			detect_key(int keycode, t_fractal *c);

int			threads(t_fractal *c);

double		norme_x1(t_fractal f, int x);

double		norme_y1(t_fractal f, int x);

int			help(void);

int			valid_parameters(char **p, t_fractal *f);

#endif
