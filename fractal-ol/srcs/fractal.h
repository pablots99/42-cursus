/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 23:05:01 by pablo             #+#    #+#             */
/*   Updated: 2021/06/02 23:33:36 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
# include "../minilibx/mlx.h"


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

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

int		exit_win(t_fractal *f);
