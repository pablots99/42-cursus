/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:59:03 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/10 22:18:15 by pablo            ###   ########.fr       */
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

