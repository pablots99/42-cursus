/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:06:14 by ptorres           #+#    #+#             */
/*   Updated: 2021/02/16 17:09:16 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	size_sphere(t_sphere *sp, int k)
{
	if (k == 30)
		sp->diameter += 10;
	if (k == 44)
		sp->diameter -= 10;
	if (sp->diameter < 1)
		sp->diameter = 1;
	ft_printf("     Sphere Resized\n");
}

int		select_sp(t_file *c)
{
	if (c->sp_count == 0)
	{
		c->curr_sp = c->sphere;
		c->sp_count++;
	}
	else
	{
		if (c->curr_sp->next)
		{
			c->sp_count++;
			c->curr_sp = c->curr_sp->next;
		}
		else
		{
			c->sp_count = 1;
			c->curr_sp = c->sphere;
		}
	}
	ft_printf("Sphere: %d selected.\n", c->sp_count);
	return (1);
}
