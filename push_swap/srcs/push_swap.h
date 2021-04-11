/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:59:28 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/11 18:29:38 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "stack.h"

#ifndef PUSH_SWAP_H
	#define PUSH_SWAP_H


	void	ft_bidimensional_free(char **arr);
	void swap_top (stack a);
	void push_from_stack(stack *dest,stack *origin);
	int is_stack_order(stack a);
	int save_input(stack *s, char **input);
	int input_errors(stack s, char *input);
	void sa(stack *a);
	void sb(stack *a);
	void ss(stack *a,stack *b);
	void pa(stack *a,stack *b);
	void pb(stack *a,stack *b);
	void ra(stack *a);
	void rb(stack *b);
	void rr(stack *a,stack *b);
	void rra(stack *a);
	void rrb(stack *b);
	void rrr(stack *a,stack *b);
#endif