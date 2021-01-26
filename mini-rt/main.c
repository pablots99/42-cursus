/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:14:12 by pablo             #+#    #+#             */
/*   Updated: 2021/01/25 23:41:54 by pablo            ###   ########.fr       */
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
    mlx_clear_window(c->mlx_ptr, c->win_ptr);
    while (y < c->win_heigth)
    {
        x = 0;
        while (x < c->win_width)
        {
            ray = generate_ray(x, y, *c);
            color = get_intersections(&ray, c);
            if (c->ligth )
                color = shading(&ray, color, c);
            my_mlx_pixel_put(&c->img, x, y, color);
            x++;
        }
        ft_printf("\rLoading: %d%%", y / (c->win_heigth / 100));

        y++;
    }
    ft_printf("\rLoading: %d%%\n", 100);
}

int init_window(t_file *c)
{
    if (!(c->mlx_ptr = mlx_init()))
        return parse_error("Minilibx Error: CAN NOT INITIALIZE MINILIBX");
    adjust_res(c);
    if (!(c->win_ptr = mlx_new_window(c->mlx_ptr, c->win_width, c->win_heigth, "MiniRt")))
        return parse_error("Minilibx Error: CAN NOT OPEN A WINDOW");
    mlx_hook(c->win_ptr, 2, 1L << 0, exit_win, c);
    mlx_hook(c->win_ptr, 17, 1L << 2, exit_win2, c);
    mlx_key_hook(c->win_ptr, detect_key, c);
     c->img.mlx_img = mlx_new_image(c->mlx_ptr, c->win_width, c->win_heigth);
    c->img.address = mlx_get_data_addr(c->img.mlx_img, &c->img.bits_per_pixel,
        &c->img.line_length, &c->img.endian);
    paint_scene(c);
    mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img.mlx_img, 0, 0);
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
