/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:36:30 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/08 15:36:30 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_config
{
	int width;
	int height;
	char back_char;
} t_config;

typedef struct s_square
{
	float x;
	float y;
	float width;
	float height;
	char type;
	char paint;
} t_square;

int save_config(FILE *file, t_config *config)
{
	int scan;

	scan = fscanf(file, "%d %d %c\n", &config->width, &config->height, &config->back_char);
	if (config->width > 300 || config->width <= 0 || config->height > 300 || config->height <= 0)
		return 1;
	if (scan != 3)
		return 1;
	//printf("scan: %d, w: %d, h: %d, c: %c\n", scan, config->width, config->height, config->back_char);
	return 0;
}
char is_square(int x, int y, t_square sq, char back)
{
	if(x < sq.x || y < sq.y || x > sq.x + sq.width || y > sq.y + sq.height)
		return back;
	if(sq.type == 'R')
		return sq.paint;
	if(sq.type == 'r' && (((x - sq.x < (float)1 ||  ( sq.x + sq.width ) - x < (float)1)) ||  
	   						 (y - sq.y < (float)1 ||  ( sq.y + sq.height ) - y < (float)1)))
		return sq.paint;						
	return back;
}

int paint_scene(FILE *file)
{
	int scan;
	t_square sq;
	t_config config;
	if (!file || save_config(file, &config) == 1)
		return 1;
		char grid[config.height][config.width];

	scan = fscanf(file, "%c %f %f %f %f %c\n", &sq.type, &sq.x, &sq.y, &sq.width, &sq.height, &sq.paint);
	int x = 0, y = 0;
	while (y < config.height)
	{
		x = 0;
		while (x < config.width)
		{
			grid[y][x] = config.back_char;
			x++;
		}
		y++;
	}
	while (scan == 6)
	{
		//printf("scan2:%d /%c /%f /%f /%f /%f /%c\n", scan, sq.type, sq.x, sq.y, sq.width, sq.height, sq.paint);
		x = 0, y = 0;
		if (sq.height <= 0 || sq.width <= 0 || !(sq.type == 'r' || sq.type == 'R'))
			return 1;
		while (y < config.height)
		{
			x = 0;
			while (x < config.width)
			{
				grid[y][x] = is_square(x, y, sq, grid[y][x]);
				x++;
			}
			y++;
		}
		scan = fscanf(file, "%c %f %f %f %f %c\n", &sq.type, &sq.x, &sq.y, &sq.width, &sq.height, &sq.paint);
	}
	if (scan != -1)
		return 1;
	y = 0;
	x = 0;
	while (y < config.height)
	{
		x = 0;
		while (x < config.width)
		{
			write(1, &grid[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
	return 0;
}
int main(int argc, char **argv)
{
	FILE *file;

	if (argc == 2)
	{
		file = fopen(argv[1], "r");

		if (!file || paint_scene(file) == 1)
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return 1;
		}
	}
	else
	{
		write(1, "Error: argument\n", 16);
		return 1;
	}
	return 0;
}