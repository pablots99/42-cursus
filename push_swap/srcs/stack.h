/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:53:36 by pablo             #+#    #+#             */
/*   Updated: 2021/04/13 18:41:09 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

typedef struct s_stack
{
	int n;
	struct s_stack *next;
} * stack;

stack 	stk_last(stack s);
stack 	stk_init(int num);
void 	stk_push(stack *s, int number);
void	stk_pop_last(stack *s);
void 	stk_free(stack *s);
void stk_push_last(stack *s, int number);
int 	stk_len(stack s);
void stk_pop(stack *s);
void stk_shift(stack *s);
void stk_rev_shift(stack *s);
void stk_print(stack s);

#endif
