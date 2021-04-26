/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:34:20 by pablo             #+#    #+#             */
/*   Updated: 2021/04/26 12:43:40 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stk_push(t_stack *s, int num)
{
	t_stack	f;

	f = stk_init(num);
	f->next = *s;
	*s = f;
}

int	stk_len(t_stack s)
{
	int	i;

	i = 0;
	while (s != NULL)
	{
		i++;
		s = s->next;
	}
	return (i);
}
