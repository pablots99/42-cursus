/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:27:02 by ptorres           #+#    #+#             */
/*   Updated: 2021/05/04 12:09:27 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_index(t_stack *a, t_stack *b, t_aux aux)
{
	t_stack	bb;
	t_stack	aa;
	int		i;

	i = 0;
	while (i < aux.movements)
	{
		bb = *b;
		aa = *a;
		if (aux.ra)
		{
			if (stk_len(bb) > 2 && bb->n < bb->next->n)
				rr(a, b);
			else
				ra(a);
		}
		else
			rra(a);
		i++;
	}
}

void	chunk_rotation(t_alg2 *p, t_stack *a, t_stack *b)
{
	int		i;
	int		*indexes;
	t_aux	aux;

	i = 0;
	indexes = (int *)malloc((p->chunk_size) * sizeof(int));
	while (i < p->chunk_size)
	{
		indexes[i] = stk_index(*a, p->soted_arr[i]);
		i++;
	}
	indexes = sorted_array(indexes, p->chunk_size);
	aux.ra = 1;
	if (indexes[0] > p->len - indexes[p->chunk_size - 1])
	{
		aux.ra = 0;
		aux.movements = p->len - indexes[p->chunk_size - 1];
	}
	else
		aux.movements = indexes[0];
	push_to_index(a, b, aux);
	free(indexes);
}

void	push_to_a(t_stack *a, t_stack *b, int len, int *sort_2)
{
	int		cont;
	int		index;
	t_stack	bb;

	cont = 0;
	len = stk_len(*b);
	while (len--)
	{
		index = stk_index(*b, sort_2[len]);
		if (index < len / 2)
			cont = 1;
		else
			cont = 0;
		bb = *b;
		while (bb->n != sort_2[len])
		{
			if (!cont)
				rrb(b);
			else
				rb(b);
			bb = *b;
		}
		pa(a, b);
	}
}

void	algorithm_2(t_stack a, t_stack b)
{
	t_alg2		p;
	int			*sort_2;

	p.chunk = 0;
	p.len = stk_len(a);
	sort_2 = sorted_stack_array(a);
	p.total_chunks = ft_sqrt(p.len) / 2;
	while (!(stk_len(a) == 0))
	{
		p.soted_arr = sorted_stack_array(a);
		p.len = stk_len(a);
		p.chunk_size = p.len / p.total_chunks;
		if (p.chunk_size < p.total_chunks / 2)
			p.chunk_size = p.len;
		chunk_rotation(&p, &a, &b);
		pb(&a, &b);
		free(p.soted_arr);
	}
	p.soted_arr = sorted_stack_array(a);
	push_to_a(&a, &b, p.len, sort_2);
	free(sort_2);
	stk_free(&a);
}
