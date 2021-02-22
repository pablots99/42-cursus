/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:09:22 by ptorres           #+#    #+#             */
/*   Updated: 2021/02/16 16:36:19 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	free_config(t_file *c)
{
	if (c->camera)
		ft_lstclear(&c->camera, &free);
	if (c->ligth)
		ft_lstclear(&c->ligth, &free);
	if (c->sphere)
		ft_lstclear(&c->sphere, &free);
	if (c->plane)
		ft_lstclear(&c->plane, &free);
	if (c->square)
		ft_lstclear(&c->square, &free);
	if (c->cylinder)
		ft_lstclear(&c->cylinder, &free);
	if (c->triangle)
		ft_lstclear(&c->triangle, &free);
	if (c->pyramid)
		ft_lstclear(&c->pyramid, &free);
	if (c->cube)
		ft_lstclear(&c->cube, &free);
}

void	ft_bidimensional_free(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
