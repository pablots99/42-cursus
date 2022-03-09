/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:59:28 by ptorres           #+#    #+#             */
/*   Updated: 2021/05/04 12:15:23 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "stack/stack.h"

typedef struct s_aux
{
	int	ra;
	int	movements;
}	t_aux;

typedef struct s_qs
{
	t_stack	*a;
	t_stack	*b;
	char	*res;
}	t_qs;

typedef struct s_alg2
{
	int	*soted_arr;
	int	chunk;
	int	total_chunks;
	int	len;
	int	chunk_size;
}	t_alg2;

void	ft_bidimensional_free(char **arr);
void	swap_top(t_stack a);
void	push_from_stack(t_stack *dest, t_stack *origin);
int		is_stack_order(t_stack a);
int		save_input(t_stack *s, char **input);
int		input_errors(t_stack s, char *input);
void	sa(t_stack *a);
void	sb(t_stack *a);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
int		*sorted_stack_array(t_stack a);
int		*sorted_array(int *arr, int len);
void	algorithm_3(t_stack a, t_stack b);
int		ft_sqrt(int n);
void	algorithm_2(t_stack a, t_stack b);
void	algorithm_4(t_stack a, t_stack b);
void	push_to_index(t_stack *a, t_stack *b, t_aux aux);
void	alg1_aux(t_stack *a, t_stack *b, int *arr, int n);
int		*sorted_array(int *arr, int len);
int		*sorted_stack_array(t_stack a);
void	print_nums(int *nums, int len);
int		is_stack_order_desc(t_stack a, int len);
void	algorithm_1(t_stack a, t_stack b);
void	push_to_b(t_qs *info, int len, int cond);
void	rra_n(t_stack *a, char **res);
void	rrb_n(t_stack *b, char **res);
void	rb_n(t_stack *b, char **res);
void	pa_n(t_stack *a, t_stack *b, char **res);
void	pb_n(t_stack *a, t_stack *b, char **res);
void	ra_n(t_stack *a, char **res);
void	sa_n(t_stack *a, char **res);
void	sb_n(t_stack *b, char **res);
int		stk_l_median(t_stack s, int len);
void	push_to_aa(t_qs *info, int len);
char	*ft_append(char **s1, char const *s2);
void	push_to_a(t_stack *a, t_stack *b, int len, int *sort_2);
int		pus_to_b_aux(t_qs *info, int len);

#endif
