/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:07:19 by pablo             #+#    #+#             */
/*   Updated: 2021/05/04 12:15:35 by pablo            ###   ########.fr       */
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

char	*ft_append(char **s1, char const *s2)
{
	char	**aux;
	char	*aux1;

	aux = s1;
	aux1 = ft_strjoin(*s1, s2);
	free(*aux);
	return (aux1);
}

int	pus_to_b_aux(t_qs *info, int len)
{
	if (len <= 1 || is_stack_order(*(info)->a))
		return (1);
	if (len == 2 && (*(info)->a)->n > (*(info)->a)->next->n)
	{
		sa_n(info->a, &info->res);
		return (1);
	}
	return (0);
}
