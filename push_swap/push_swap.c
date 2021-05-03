/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:00:18 by ptorres           #+#    #+#             */
/*   Updated: 2021/05/03 21:19:39 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/push_swap.h"

void	alg1_aux(t_stack *a, t_stack *b, int *arr, int n)
{
	int		r;
	int		i;
	t_stack	aa;

	i = 0;
	r = 0;
	while (!(stk_len(*a) <= n))
	{
		aa = *a;
		if (stk_index(*a, arr[i]) < (stk_len(*a) / 2))
			r = 1;
		else
			r = 0;
		while (aa->n != arr[i])
		{
			if (r)
				ra(a);
			else
				rra(a);
			aa = *a;
		}
		pb(a, b);
		i++;
	}
}

void	algorithm_1(t_stack a, t_stack b)
{
	int	*arr;
	int	len;

	len = stk_len(a);
	arr = sorted_stack_array(a);
	alg1_aux(&a, &b, arr, 3);
	while (stk_len(a) == 3
		&& !(stk_last(a)->n > a->n && stk_last(a)->n > a->next->n))
		ra(&a);
	if (a->n > a->next->n)
		sa(&a);
	while (b != NULL)
		pa(&a, &b);
	free(arr);
	stk_free(&a);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		input_err;

	b = NULL;
	a = NULL;
	input_err = save_input(&a, argv);
	if (argc < 2)
		input_err = 1;
	if (input_err)
	{
		write(1, "Error\n", ft_strlen("Error\n"));
		return (1);
	}
	if (is_stack_order(a))
		return (0);
	if (stk_len(a) < 20)
		algorithm_1(a, b);
	else if (stk_len(a) < 200)
		algorithm_2(a, b);
	else
		algorithm_3(a, b);
	return (0);
}
