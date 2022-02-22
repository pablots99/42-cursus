/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:14:12 by pablo             #+#    #+#             */
/*   Updated: 2021/02/17 11:44:58 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/mini_rt.h"

int		init_window(t_file *c, int save)
{
	adjust_res(c);
	if (!(c->win_ptr = mlx_new_window(c->mlx_ptr, c->win_width,
		c->win_heigth, "MiniRt")))
		return (parse_error("Minilibx Error: CAN NOT OPEN A WINDOW"));
	mlx_hook(c->win_ptr, 2, 1L << 0, exit_win, c);
	mlx_hook(c->win_ptr, 17, 1L << 2, exit_win2, c);
	mlx_key_hook(c->win_ptr, detect_key, c);
	c->img.mlx_img = mlx_new_image(c->mlx_ptr, c->win_width, c->win_heigth);
	c->img.address = mlx_get_data_addr(c->img.mlx_img, &c->img.bits_per_pixel,
		&c->img.line_length, &c->img.endian);
	threats(c, save);
	mlx_loop(c->mlx_ptr);
	return (0);
}

int		main(int argc, char **argv)
{
	t_file	config;
	int		save;

	save = 0;
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6) &&
		ft_strlen(argv[2]) == 6)
		save = 1;
	if (argc == 2 || (argc == 3 & save == 1))
	{
		ft_bzero(&config, sizeof(t_file));
		if (read_rt_file(argv[1], &config))
		{
			ft_printf("BONUS:%d\nTHREADS:%d\nANTIALIASING:%d\n",
				BONUS, THREADS, config.antialiasing);
			init_window(&config, save);
		}
	}
	else
	{
		ft_printf("Error:Bad number of Parameters");
		return (0);
	}
	free_config(&config);
	return (0);
}
