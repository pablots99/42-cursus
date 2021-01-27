/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:27:31 by pablo             #+#    #+#             */
/*   Updated: 2021/01/27 19:18:02 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void write_headder(int fd, t_file *c)
{
	unsigned char headder[54];
	int i;

	i = 0;
	while (i < 54)
		headder[i++] = (unsigned char)0;
	headder[0] = 'B';
	headder[1] = 'M';
	headder[10] = (unsigned char)(54);
	headder[14] = (unsigned char)(40);
	headder[18] = (unsigned char)(c->win_width);
	headder[19] = (unsigned char)(c->win_width >> 8);
	headder[20] = (unsigned char)(c->win_width >> 16);
	headder[21] = (unsigned char)(c->win_width >> 24);
	headder[22] = (unsigned char)(c->win_heigth);
	headder[23] = (unsigned char)(c->win_heigth >> 8);
	headder[24] = (unsigned char)(c->win_heigth >> 16);
	headder[25] = (unsigned char)(c->win_heigth >> 24);
	headder[26] = (unsigned char)1;
	headder[28] = (unsigned char)32;
	write(fd, headder, 54);
}

int create_bmp_file(t_file *c, char *file)
{
	int fd;
	int x;
	int y;
	t_img *data;

	data = &c->img;
	if ((fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0744)) == -1)
		return ft_printf("Bmp Error: Can´t create Bmp file\n");
	write_headder(fd, c);
	y =  c->win_heigth -1;
	while (y > 0)
	{
		x = 0;
		while (x < c->win_width)
		{
			write(fd,data->address + ((y) * data->line_length + x * (data->bits_per_pixel / 8)),(data->bits_per_pixel / 8));
			x++;
		}
		y--;
	}
	close(fd);
	return 0;
}