/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:14:12 by pablo             #+#    #+#             */
/*   Updated: 2021/01/10 14:39:45 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/mini_rt.h"

void paint_scene(t_file *c)
{
    int y;
    int x;
    t_ray ray;
    int color;

    color = 0;
    y = 0;
    printf("ambient:%f\n",c->ambient_ligth.ratio);
    while (y < c->win_heigth)
    {
        x = 0;
        while (x < c->win_width)
        {
            ray = generate_ray(x, y, *c);
            color = get_intersections(&ray,*c);
            if(c->ligth && color != 0)
                 color = shading(&ray,color,*c);
            mlx_pixel_put(c->mlx_ptr,c->win_ptr,x,y,color);
            x++;
        }
        y++;
    }
}

int init_window(t_file *c)
{

    if (!(c->mlx_ptr = mlx_init()))
        return parse_error("Minilibx Error: CAN NOT INITIALIZE MINILIBX");
    if (!(c->win_ptr = mlx_new_window(c->mlx_ptr, c->win_width, c->win_heigth, "MiniRt")))
        return parse_error("Minilibx Error: CAN NOT OPEN A WINDOW");
    mlx_hook(c->win_ptr, 2, 1L << 0, exit_win, c);
    mlx_hook(c->win_ptr, 17, 1L << 2, exit_win2, c);
    printf("aspec_ratio:%f\n", c->aspect_ratio);
    printf("canvas_wid: %f, canvas_he: %f \n", ((t_camera *)c->camera->content)->canvas.canvas_w, ((t_camera *)c->camera->content)->canvas.canvas_h);
    paint_scene(c);
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
