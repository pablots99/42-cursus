/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:59:03 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/26 17:11:29 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_top(t_stack a)
{
	int	aux;

	if (stk_len(a) <= 1)
		return ;
	aux = a->next->n;
	a->next->n = a->n;
	a->n = aux;
}

void	push_from_stack(t_stack *dest, t_stack *origin)
{
	t_stack	o;

	o = *origin;
	if (o != NULL)
	{
		stk_push(dest, o->n);
		stk_pop(origin);
	}
}

void	sa(t_stack *a)
{
	swap_top(*a);
	write(1, "sa\n", 3);
}
