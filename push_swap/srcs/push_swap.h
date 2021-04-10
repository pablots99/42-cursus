/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:59:28 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/10 22:14:58 by pablo            ###   ########.fr       */
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




#endif