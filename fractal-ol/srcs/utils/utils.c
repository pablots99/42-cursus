/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 01:39:59 by pablo             #+#    #+#             */
/*   Updated: 2021/06/20 02:18:53 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

double norme_x1(t_fractal f, int x)
{
	double x1;
	x1 = resize_value(x, (t_range){0, f.win_width},
			(t_range){-f.zoom + f.move_x, f.zoom + f.move_x});

	return (x1);
}
double norme_y1(t_fractal f, int y)
{
	double y1;
	y1 = resize_value(y, (t_range){0, f.win_heigth},
			(t_range){-f.zoom + f.move_y, f.zoom + f.move_y});
	return (y1);
}

int help()
{
	printf("Invalid parameters!\n");
	printf("	Execute with parameters:\n");
	printf("		-> julia\n");
	printf("		-> mandelbort\n");
	return (1);
}
int valid_parameters(char *p,t_fractal *f)
{
	printf("param: %s\n",p);
	if(!ft_strncmp("mandelbort",p,10) && ft_strlen(p) == 10)
		return (1);
	if(!ft_strncmp("julia",p,5) && ft_strlen(p) == 5)
	{
		f->is_fullJulia = 1;
		f->julia->x = 0.854400 ;
		f->julia->y =  0.230400;
		return (1);
	}
	return (0);
}
