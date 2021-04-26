/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:27:02 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/26 11:45:21 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

typedef struct s_alg2
{
	int *soted_arr;
	int chunk;
	int total_chunks;
	int len;
	int chunk_size;
} t_alg2;

int *sorted_array(int *arr, int len)
{
	int i;
	int j;
	int aux;

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
	return arr;
}
int *sorted_stack_array(stack a)
{
	int *arr;
	int i;
	int len;

	i = 0;
	len = stk_len(a);
	if (len == 0)
		return NULL;
	arr = malloc(len * sizeof(int));
	while (a != NULL)
	{
		arr[i] = a->n;
		i++;
		a = a->next;
	}
	arr = sorted_array(arr, len);
	return arr;
}

void chunk_rotation(t_alg2 *p, stack *a, stack *b)
{
	int i;
	int *indexes;
	t_aux aux;

	i = 0;
	indexes = (int *)malloc((p->chunk_size) * sizeof(int));
	while (i < p->chunk_size)
	{
		indexes[i] = stk_index(*a, p->soted_arr[i]);
		i++;
	}
	i = 0;
	indexes = sorted_array(indexes, p->chunk_size);
	aux.ra = 1;
	if (indexes[0] > p->len - indexes[p->chunk_size - 1])
	{
		aux.ra = 0;
		aux.movements = p->len - indexes[p->chunk_size - 1];
	}
	else
		aux.movements = indexes[0];
	i = 0;
	stack bb;
	stack aa;
	while (i < aux.movements)
	{
		bb = *b;
		aa = *a;
		if (aux.ra)
		{
			if (stk_len(bb) > 4 && bb->n < bb->next->n)
				rr(a, b);
			else
				ra(a);
		}
		else
			rra(a);
		i++;
	}
	free(indexes);
}

void push_to_a(stack *a, stack *b, t_alg2 p, int *sort_2)
{
	int cont;
	int index;
	stack bb;

	cont = 0;
	p.len = stk_len(*b);
	while (p.len--)
	{
		index = stk_index(*b, sort_2[p.len]);
		if (index < p.len / 2)
			cont = 1;
		else
			cont = 0;
		bb = *b;
		while (bb->n != sort_2[p.len])
		{
			if (!cont)
				rrb(b);
			else
				rb(b);
			bb = *b;
		}
		pa(a,b);
	}
}

void algorithm_2(stack a, stack b)
{
	t_alg2 p;
	int *sort_2;

	p.chunk = 0;
	p.len = stk_len(a);
	sort_2 = sorted_stack_array(a);
	p.total_chunks = ft_sqrt(p.len) / 2;
	while (a != NULL)
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
	push_to_a(&a,&b,p,sort_2);
	free(sort_2);
}
