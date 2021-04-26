/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:07:19 by pablo             #+#    #+#             */
/*   Updated: 2021/04/26 17:41:06 by pablo            ###   ########.fr       */
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
			if (stk_len(bb) > 4 && bb->n < bb->next->n)
				rr(a, b);
			else
				ra(a);
		}
		else
			rra(a);
		i++;
	}
}
