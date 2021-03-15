/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:59:28 by ptorres           #+#    #+#             */
/*   Updated: 2021/03/15 13:54:16 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

#ifndef PUSH_SWAP_H
	#define PUSH_SWAP_H

	int sa(int *a, int *b); // swap the first 2 elements at the top of stack a. Do nothing if there  is only one or no elements
	int sb(int *a, int *b); // - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements
	int ss(int *a, int *b); //  sa and sb at the same time.
	int pa(int *a, int *b); // take the first element at the top of b and put it at the top of a. Do nothing if b is empty
	int pb(int *a, int *b); // take the first element at the top of a and put it at the top of b. Do nothing if a is empty
	int ra(int *a, int *b); //  shift up all elements of stack a by 1. The first element becomes the last one
	int rb(int *a, int *b); // - shift up all elements of stack b by 1. The first element becomes the last one
	int rr(int *a, int *b); // ra and rb at the same time
	int rra(int *a, int *b); //  shift down all elements of stack a by 1. The last element becomes the first one
	int rrb(int *a, int *b); // shift down all elements of stack b by 1. The last element ecomes the first one
	int rrr(int *a, int *b); // rra and rrb at the same time




#endif