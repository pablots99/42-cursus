/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:14:12 by pablo             #+#    #+#             */
/*   Updated: 2020/12/29 18:52:02 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/mini_rt.h"


void init_window(t_file *c)
{
    //printf("fov%d",((t_camera*)ft_lstlast(c->camera)->content)->fov);
    c->mlx_ptr = mlx_init();
    c->win_ptr = mlx_new_window(c->mlx_ptr,c->win_width,c->win_heigth,"MiniRt");
    mlx_loop(c->mlx_ptr);
}

int main(int argc, char **argv)
{
    t_file config;
    
    if (argc == 2)
    {
       if(read_rt_file(argv[1],&config))
            init_window(&config);
        //else libero structura
    }
    else
    {
        ft_printf("Error: incorrect number of parameters");
        return 0;
    }
    return 0;
}
