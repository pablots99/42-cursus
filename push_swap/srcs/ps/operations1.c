/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:08:59 by pablo             #+#    #+#             */
/*   Updated: 2021/04/26 17:10:57 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb(t_stack *b)
{
	stk_shift(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	stk_shift(a);
	stk_shift(b);
	write(1, "rr\n", 3);
}

void	rra(t_stack *a)
{
	stk_rev_shift(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	stk_rev_shift(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	stk_rev_shift(a);
	stk_rev_shift(b);
	write(1, "rrr\n", 4);
}
