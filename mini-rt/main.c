/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:14:12 by pablo             #+#    #+#             */
/*   Updated: 2021/01/02 20:06:47 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/mini_rt.h"



int init_window(t_file *c)
{

    if (!(c->mlx_ptr = mlx_init()))
        return parse_error("Minilibx Error: CAN NOT INITIALIZE MINILIBX");
    if (!(c->win_ptr = mlx_new_window(c->mlx_ptr, c->win_width, c->win_heigth, "MiniRt")))
        return parse_error("Minilibx Error: CAN NOT OPEN A WINDOW");
    mlx_hook(c->win_ptr, 2, 1L << 0, exit_win, c);
    mlx_hook(c->win_ptr, 17, 1L << 2, exit_win2, c);
    mlx_loop(c->mlx_ptr);
    return 0;
}

int main(int argc, char **argv)
{
    t_file config;

    if (argc == 2)
    {
        ft_bzero(&config, sizeof(t_file));
        if (read_rt_file(argv[1], &config))
            init_window(&config);
    }
    else
    {
        ft_printf("Error: incorrect number of parameters");
        return 0;
    }
    free_config(&config);
    ft_printf("\n\n\n\n------------------LEAKS---------------------------------------\n");
    system("leaks minirt");
    ft_printf("--------------------------------------------------------\n");

    return 0;
}
