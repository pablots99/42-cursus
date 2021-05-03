/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:07:19 by pablo             #+#    #+#             */
/*   Updated: 2021/05/03 21:16:32 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*sorted_array(int *arr, int len)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] >= arr[j])
			{
				aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	*sorted_stack_array(t_stack a)
{
	int	*arr;
	int	i;
	int	len;

	i = 0;
	len = stk_len(a);
	if (len == 0)
		return (NULL);
	arr = malloc(len * sizeof(int));
	while (a != NULL)
	{
		arr[i] = a->n;
		i++;
		a = a->next;
	}
	arr = sorted_array(arr, len);
	return (arr);
}

int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i != n && i * i < n)
		i++;
	return (i);
}
