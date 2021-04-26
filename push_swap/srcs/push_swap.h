/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:59:28 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/26 12:42:10 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "stack/stack.h"

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
typedef struct s_aux
{
	int ra;
	int movements;
} t_aux;

void ft_bidimensional_free(char **arr);
void swap_top(t_stack a);
void push_from_stack(t_stack *dest, t_stack *origin);
int is_stack_order(t_stack a);
int save_input(t_stack *s, char **input);
int input_errors(t_stack s, char *input);
void sa(t_stack *a);
void sb(t_stack *a);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);
int *sorted_stack_array(t_stack a);
int *sorted_array(int *arr, int len);
void algorithm_3(t_stack a, t_stack b);
int ft_sqrt(int n);
void algorithm_2(t_stack a, t_stack b);

#endif
