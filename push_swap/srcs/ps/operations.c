/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:59:03 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/26 12:46:11 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap_top(t_stack a)
{
	int aux;

	if (stk_len(a) <= 1)
		return;
	aux = a->next->n;
	a->next->n = a->n;
	a->n = aux;
}

void push_from_stack(t_stack *dest, t_stack *origin)
{
	t_stack o;

	o = *origin;
	if (o != NULL)
	{
		stk_push(dest, o->n);
		stk_pop(origin);
	}
}

void sa(t_stack *a)
{
	swap_top(*a);
	write(1, "sa\n", 3);
}

void sb(t_stack *b)
{
	swap_top(*b);
	write(1, "sb\n", 3);
}
void ss(t_stack *a, t_stack *b)
{
	swap_top(*a);
	swap_top(*b);
	write(1, "ss\n", 3);
}

void pa(t_stack *a, t_stack *b)
{
	push_from_stack(a, b);
	write(1, "pa\n", 3);
}
void pb(t_stack *a, t_stack *b)
{
	push_from_stack(b, a);
	write(1, "pb\n", 3);
}
void ra(t_stack *a)
{
	stk_shift(a);
	write(1, "ra\n", 3);
}

void rb(t_stack *b)
{
	stk_shift(b);
	write(1, "rb\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
	stk_shift(a);
	stk_shift(b);
	write(1, "rr\n", 3);
}

void rra(t_stack *a)
{
	stk_rev_shift(a);
	write(1, "rra\n", 4);
}
void rrb(t_stack *b)
{
	stk_rev_shift(b);
	write(1, "rrb\n", 4);
}

void rrr(t_stack *a, t_stack *b)
{
	stk_rev_shift(a);
	stk_rev_shift(b);
	write(1, "rrr\n", 4);
}
