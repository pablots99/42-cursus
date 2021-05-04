/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_qs_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:54:04 by pablo             #+#    #+#             */
/*   Updated: 2021/05/04 12:14:47 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stk_l_median(t_stack s, int len)
{
	int	*arr;
	int	i;
	int	aux;

	i = 0;
	arr = malloc(len * sizeof(int));
	while (s != NULL && i < len)
	{
		arr[i] = s->n;
		s = s->next;
		i++;
	}
	arr = sorted_array(arr, len);
	aux = arr[len / 2];
	free(arr);
	return (aux);
}

void	push_to_aa_aux(t_qs *info, int len, int moved)
{
	int	i;

	i = 0;
	while (i++ < moved)
		rrb_n(info->b, &info->res);
	push_to_b(info, len / 2 + len % 2, 0);
	push_to_aa(info, len / 2);
}

void	push_to_aa(t_qs *info, int len)
{
	int	i;
	int	moved;
	int	median;

	moved = 1;
	i = 0;
	if (len == 2 && (*(info)->b)->n < (*(info)->b)->next->n)
		sb_n(info->b, &info->res);
	if (is_stack_order_desc(*(info)->b, len) || len <= 1)
	{
		while (len--)
			pa_n(info->a, info->b, &info->res);
		return ;
	}
	median = stk_l_median(*(info)->b, len);
	while (i++ < len)
	{
		if ((*(info)->b)->n >= median)
			pa_n(info->a, info->b, &info->res);
		else if (moved++)
			rb_n(info->b, &info->res);
	}
	push_to_aa_aux(info, len, moved -1);
}
