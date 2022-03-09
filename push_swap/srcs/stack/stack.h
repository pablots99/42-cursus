/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:53:36 by pablo             #+#    #+#             */
/*   Updated: 2021/04/26 17:13:06 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
}	*t_stack;

t_stack	stk_last(t_stack s);
t_stack	stk_init(int num);
void	stk_push(t_stack *s, int number);
void	stk_pop_last(t_stack *s);
void	stk_free(t_stack *s);
void	stk_push_last(t_stack *s, int number);
int		stk_len(t_stack s);
void	stk_pop(t_stack *s);
void	stk_shift(t_stack *s);
void	stk_rev_shift(t_stack *s);
void	stk_print(t_stack s);
int		stk_index(t_stack a, int num);
void	stk_free(t_stack *s);

#endif
