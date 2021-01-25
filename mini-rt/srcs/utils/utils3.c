/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:05:59 by ptorres           #+#    #+#             */
/*   Updated: 2021/01/19 22:28:35 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int exit_win(int keycode, t_file *c)
{
	if (keycode == 53)
	{
		mlx_destroy_window(c->mlx_ptr, c->win_ptr);
		free_config(c);
		ft_printf("\n\n\n\n------------------LEAKS---------------------------------------\n");
		system("leaks minirt");
		ft_printf("--------------------------------------------------------\n");
		exit(0);
	}
	return (0);
}
int exit_win2(t_file *c)
{
	mlx_destroy_window(c->mlx_ptr, c->win_ptr);
	free_config(c);
	exit(0);
	return (0);
}
void adjust_res(t_file *c)
{
	int h;
	int w;

	mlx_get_screen_size(c->mlx_ptr, &w, &h);
	if (c->win_width > w)
		c->win_width = w;
	if (c->win_heigth > h)
		c->win_heigth = h;
	c->aspect_ratio = (float)((float)c->win_width / (float)c->win_heigth);
}