/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 23:05:01 by pablo             #+#    #+#             */
/*   Updated: 2021/06/04 16:36:09 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
# include "../minilibx/mlx.h"
#include <math.h>

typedef struct	s_img
{
	void	*mlx_img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;


typedef struct s_fractal
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_heigth;
	int				win_width;
	t_img			img;

}	t_fractal;

typedef struct s_range
{
	double start;
	double end;
}	t_range;
/*mlx*/
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

int		exit_win(t_fractal *f);
/*colors*/
int		int_from_rgb(int r, int g, int b);
