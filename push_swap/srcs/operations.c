/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:59:03 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/11 18:28:17 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void swap_top (stack a)
{
    int aux;

    if(stk_len(a) <= 1)
        return ;
    aux = a->next->n;
    a->next->n = a->n;
    a->n  = aux;
}

void push_from_stack(stack *dest,stack *origin)
{
    stack o;
    
    o = *origin;
    if(o != NULL)
    {
        stk_push(dest,o->n);
        stk_pop(origin);
    }
}

void sa(stack *a)
{
    swap_top(*a);
    write(1,"sa\n",3);
}

void sb(stack *b)
{
    swap_top(*b);
    write(1,"sb\n",3);
}
void ss(stack *a,stack *b)
{
    swap_top(*a);
    swap_top(*b);
    write(1,"ss\n",3);
}

void pa(stack *a,stack *b)
{
     push_from_stack(a,b);
     write(1,"pa\n",3);
}
void pb(stack *a,stack *b)
{
     push_from_stack(b,a);
     write(1,"pb\n",3);
}
void ra(stack *a)
{
    stk_shift(a);
     write(1,"ra\n",3);
}

void rb(stack *b)
{
    stk_shift(b);
     write(1,"rb\n",3);
}

void rr(stack *a,stack *b)
{
    stk_shift(a);
    stk_shift(b);
     write(1,"rr\n",3);
}

void rra(stack *a)
{
    stk_rev_shift(a);
     write(1,"rra\n",3);
}
void rrb(stack *b)
{
    stk_rev_shift(b);
     write(1,"rrb\n",3);
}

void rrr(stack *a,stack *b)
{
    stk_rev_shift(a);
    stk_rev_shift(b);
     write(1,"rrr\n",3);
}