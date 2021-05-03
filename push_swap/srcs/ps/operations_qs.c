/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_qs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:48:49 by pablo             #+#    #+#             */
/*   Updated: 2021/05/03 21:14:07 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa_n(t_stack *a, t_stack *b, char **res)
{
	if (!b || *b == NULL)
		return ;
	push_from_stack(a, b);
	*res = gn_ft_strjoin(*res, "pa\n");
}

void	pb_n(t_stack *a, t_stack *b, char **res)
{
	push_from_stack(b, a);
	*res = gn_ft_strjoin(*res, "pb\n");
}

void	ra_n(t_stack *a, char **res)
{
	stk_shift(a);
	*res = gn_ft_strjoin(*res, "ra\n");
}
