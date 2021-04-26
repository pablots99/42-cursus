/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:49:29 by pablo             #+#    #+#             */
/*   Updated: 2021/04/26 12:41:00 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

t_stack	stk_last(t_stack s)
{
	t_stack	res;

	res = s;
	while (res->next)
		res = res->next;
	return (res);
}

t_stack	stk_init(int num)
{
	t_stack	s;

	s = malloc(sizeof(struct s_stack));
	if (!s)
		return (NULL);
	s->n = num;
	s->next = NULL;
	return (s);
}

void	stk_push_last(t_stack *s, int number)
{
	t_stack	f;

	f = *s;
	if (f == NULL)
	{
		*s = stk_init(number);
		return ;
	}
	while (f->next)
		f = f->next;
	f->next = stk_init(number);
}

void	stk_pop_last(t_stack *s)
{
	t_stack	f;

	f = *s;
	while (f->next->next)
		f = f->next;
	free(f->next);
	f->next = NULL;
}

void	stk_pop(t_stack *s)
{
	t_stack	f;
	t_stack	f1;

	f = *s;
	if(f->next == NULL)
	{
		free(*s);
		*s = NULL;
		return ;
	}
	if (f != NULL && f->next != NULL)
	{
		f1 = f;
		f = f->next;
		*s = f;
		free(f1);
	}
}
