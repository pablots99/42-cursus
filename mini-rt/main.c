/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:14:12 by pablo             #+#    #+#             */
/*   Updated: 2020/12/22 11:22:46 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void draw_square(t_config config, int x, int y, int width)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < width)
    {
        mlx_pixel_put(config.mlx, config.mlx_win, x + i, y, 233);
        mlx_pixel_put(config.mlx, config.mlx_win, x, y + i, 233);
        mlx_pixel_put(config.mlx, config.mlx_win, x + i, y + width, 233);
        mlx_pixel_put(config.mlx, config.mlx_win, x + width, y + i, 233);
        i++;
    }
    while (j < width / 2.7)
    {
        mlx_pixel_put(config.mlx, config.mlx_win, x + j, y + j, 233);
        mlx_pixel_put(config.mlx, config.mlx_win, x + width + j, y + j, 233);
        mlx_pixel_put(config.mlx, config.mlx_win, x + width + j, y + width + j, 233);
        mlx_pixel_put(config.mlx, config.mlx_win, x + j, y + width + j, 233);

        j++;
    }
    i = 0;
    x += j;
    y += j;
    while (i < width)
    {
        mlx_pixel_put(config.mlx, config.mlx_win, x + i, y, 233);
        mlx_pixel_put(config.mlx, config.mlx_win, x, y + i, 233);
        mlx_pixel_put(config.mlx, config.mlx_win, x + i, y + width, 233);
        mlx_pixel_put(config.mlx, config.mlx_win, x + width, y + i, 233);
        i++;
    }
}

int main()
{
    t_config config;

    config.mlx = mlx_init();
    config.mlx_win = mlx_new_window(config.mlx, 900, 600, "hola");
    draw_square(config, 50, 50, 100);

    mlx_loop(config.mlx);
}
