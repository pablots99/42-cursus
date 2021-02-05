/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:27:31 by pablo             #+#    #+#             */
/*   Updated: 2021/02/05 00:31:53 by pablo            ###   ########.fr       */
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
	y = c->win_heigth - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < c->win_width)
		{
			write(fd, data->address + ((y)*data->line_length + x * (data->bits_per_pixel / 8)), (data->bits_per_pixel / 8));
			x++;
		}
		y--;
	}
	close(fd);
	ft_printf("%s Created", file);
	return 0;
}
t_bmp read_bmp(char *file, t_file *c)
{
	int fd;
	t_bmp bmp;

	fd = 0;
	bmp.width = 0;
	bmp.heigth = 0;
	printf("file: %s\n", file);
	if (!ft_strnstr(file, ".xpm", ft_strlen(file)))
		ft_printf("Error\n       Error: Map file is invalid\n");
	else
	{

		if (!(bmp.img.mlx_img = mlx_xpm_file_to_image(c->mlx_ptr, file, &bmp.width, &bmp.heigth)))
		{
			ft_printf("Error\n       Error: No map named %s\n",file);
			return bmp;
		}
		bmp.img.address = mlx_get_data_addr(bmp.img.mlx_img, &bmp.img.bits_per_pixel,
											&bmp.img.line_length, &bmp.img.endian);
	}
	return bmp;
}

int sp_bmp(t_ray ray, t_bmp bmp, t_sphere sp)
{
	float u;
	float v;
	char *dst;
	t_cord d;

	d = rest_vec(ray_cut_point(ray), sp.cord);
	if (d.z > 0 && d.x > 0)
		u = atan(d.x / d.z);
	else if (d.z > 0 && d.x < 0)
		u = (2 * M_PI) + atan(d.x / d.z);
	else if (d.z < 0)
		u = M_PI + atan(d.x / d.z);
	if (d.y > 0)
		v = atan((sqrt(d.z * d.z + d.x * d.x)) / d.y);
	else if (d.y < 0)
		v = M_PI + atan((sqrt(d.z * d.z + d.x * d.x)) / d.y);
	u = ((u) / (2 * M_PI)) * bmp.width;
	v = ((v) / (M_PI)) * bmp.heigth;
	dst = (bmp.img.address + (((int)(v)*bmp.img.line_length) + ((int)(u) * (bmp.img.bits_per_pixel / 8))));
	return (*(unsigned int *)dst);
}
int sp_bmp1(t_ray ray, t_bmp bmp, t_sphere sp)
{
	float u;
	float v;
	char *dst;
	t_cord d;
	int colors[5];

	init_int_arr(colors,5);
	d = rest_vec(ray_cut_point(ray), sp.cord);
	if (d.z > 0 && d.x > 0)
		u = atan(d.x / d.z);
	else if (d.z > 0 && d.x < 0)
		u = (2 * M_PI) + atan(d.x / d.z);
	else if (d.z < 0)
		u = M_PI + atan(d.x / d.z);
	if (d.y > 0)
		v = atan((sqrt(d.z * d.z + d.x * d.x)) / d.y);
	else if (d.y < 0)
		v = M_PI + atan((sqrt(d.z * d.z + d.x * d.x)) / d.y);
	u = ((u) / (2 * M_PI)) * bmp.width;
	v = ((v) / (M_PI)) * bmp.heigth;
	colors[0] = (*(unsigned int *)(bmp.img.address + (((int)(v)*bmp.img.line_length) + ((int)(u) * (bmp.img.bits_per_pixel / 8)))));
	colors[1] = (*(unsigned int *)(bmp.img.address + (((int)(v + 1)*bmp.img.line_length) + ((int)(u) * (bmp.img.bits_per_pixel / 8)))));
	colors[2] = (*(unsigned int *)(bmp.img.address + (((int)(v + 1)*bmp.img.line_length) + ((int)(u) * (bmp.img.bits_per_pixel / 8)))));
	colors[3] = (*(unsigned int *)(bmp.img.address + (((int)(v)*bmp.img.line_length) + ((int)(u + 1) * (bmp.img.bits_per_pixel / 8)))));
	colors[4] = (*(unsigned int *)(bmp.img.address + (((int)(v)*bmp.img.line_length) + ((int)(u - 1) * (bmp.img.bits_per_pixel / 8)))));
	return average_color(colors,4);
}
void sp_bump(t_ray ray, t_bmp bmp, t_sphere sp)
{
	float u;
	float v;
	char *dst;
	t_cord d;

	d = rest_vec(ray_cut_point(ray), sp.cord);
	if (d.z > 0 && d.x > 0)
		u = atan(d.x / d.z);
	else if (d.z > 0 && d.x < 0)
		u = (2 * M_PI) + atan(d.x / d.z);
	else if (d.z < 0)
		u = M_PI + atan(d.x / d.z);
	if (d.y > 0)
		v = atan((sqrt(d.z * d.z + d.x * d.x)) / d.y);
	else if (d.y < 0)
		v = M_PI + atan((sqrt(d.z * d.z + d.x * d.x)) / d.y);
	u = ((u) / (2 * M_PI)) * bmp.width;
	v = ((v) / (M_PI)) * bmp.heigth;
	
	dst = (bmp.img.address + (((int)(v)*bmp.img.line_length) + ((int)(u) * (bmp.img.bits_per_pixel / 8))));                                                      
}