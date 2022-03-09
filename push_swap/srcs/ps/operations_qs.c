/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_qs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:48:49 by pablo             #+#    #+#             */
/*   Updated: 2021/05/04 12:05:32 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa_n(t_stack *a, t_stack *b, char **res)
{
	if (!b || *b == NULL)
		return ;
	push_from_stack(a, b);
	*res = ft_append(res, "pa\n");
}

void	pb_n(t_stack *a, t_stack *b, char **res)
{
	push_from_stack(b, a);
	*res = ft_append(res, "pb\n");
}

void	ra_n(t_stack *a, char **res)
{
	stk_shift(a);
	*res = ft_append(res, "ra\n");
}

void	sa_n(t_stack *a, char **res)
{
	swap_top(*a);
	*res = ft_append(res, "sa\n");
}

void	sb_n(t_stack *b, char **res)
{
	swap_top(*b);
	*res = ft_append(res, "sb\n");
}
