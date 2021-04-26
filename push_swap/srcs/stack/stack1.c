/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:18:36 by pablo             #+#    #+#             */
/*   Updated: 2021/04/26 12:41:47 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stk_shift(t_stack *s)
{
	t_stack	a;

	if (*s != NULL)
	{
		a = *s;
		stk_push_last(s, a->n);
		stk_pop(s);
	}
}

void	stk_rev_shift(t_stack *s)
{
	t_stack	a;

	if (*s != NULL)
	{
		a = stk_last(*s);
		stk_push(s, a->n);
		stk_pop_last(s);
	}
}

void	stk_print(t_stack s)
{
	t_stack	f;

	f = s;
	if (!s)
		return ;
	while (s->next)
	{
		printf("s:%d-", s->n);
		s = s->next;
	}
	printf("s:%d\n", s->n);
}

int	stk_index(t_stack a, int num)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		if (a->n == num)
			return (i);
		i++;
		a = a->next;
	}
	return (-1);
}

void	stk_free(t_stack *s)
{
	t_stack	aux;
	t_stack	aux_1;

	aux = *s;
	while (aux != NULL)
	{
		aux_1 = aux;
		aux = aux->next;
		free(aux_1);
	}
}
