/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_qs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:35:07 by pablo             #+#    #+#             */
/*   Updated: 2021/05/03 21:14:28 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra_n(t_stack *a, char **res)
{
	stk_rev_shift(a);
	*res = gn_ft_strjoin(*res, "rra\n");
}

void	rrb_n(t_stack *b, char **res)
{
	stk_rev_shift(b);
	*res = gn_ft_strjoin(*res, "rrb\n");
}

void	rb_n(t_stack *b, char **res)
{
	stk_shift(b);
	*res = gn_ft_strjoin(*res, "rb\n");
}
