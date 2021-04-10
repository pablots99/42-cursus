/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:53:37 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/10 22:06:40 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

int is_stack_order(stack a)
{
	int aux;

	if(a == NULL)
		return -1;
	
	aux = a->n;
	a = a->next;
	while(a != NULL)
	{
		if(aux > a->n)
			return 0;
		aux = a->n;
		a = a->next;
	}
	return 1;
}
