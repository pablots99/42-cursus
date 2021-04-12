/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:49:29 by pablo             #+#    #+#             */
/*   Updated: 2021/04/12 12:35:27 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

stack stk_last(stack s)
{
    stack res;
    res = s;
    while( res->next)
        res = res->next;
    return res;
}

stack  stk_init(int num)
{
    stack s;
    
    s = malloc(sizeof(struct s_stack));
    if(!s)
        return NULL;
    s->n = num;
    s->next = NULL;
    return s;
}

void stk_push_last(stack *s, int number)
{
    stack f;
    
    f = *s;
    if(f == NULL)
    {
        *s = stk_init(number);
        return ;
    }
    while(f->next)
        f = f->next;
    f->next = stk_init(number);
}

void  stk_pop_last(stack *s)
{
    stack f;
    f = *s;
    while(f->next->next)
        f = f->next;
    free(f->next);
    f->next = NULL;
}
void stk_pop(stack *s)
{
    stack f;
    stack f1;
    f = *s;
    if(f != NULL)
    {  
       f1 = f;
        f = f->next;
        *s = f;
        free(f1);
    }
}

void stk_push(stack *s, int num)
{
    stack f;
    f = stk_init(num);
    f->next = *s;
    *s = f;
}

int stk_len(stack s)
{
    int i;

    i = 0;
    while(s != NULL)
    {
        i++;
        s = s->next;
    }
    return i;
}

void stk_shift(stack *s)
{
    stack a;

  
    if(*s != NULL)
    {
        
		a = *s;
        stk_push_last(s,a->n);
		stk_pop(s);
    }
}
void stk_rev_shift(stack *s)
{
    stack a;

    if(*s != NULL)
    {
		a = stk_last(*s);
        stk_push(s,a->n);
		stk_pop_last(s);
    }
}

void stk_print(stack s)
{
    stack f;

    f = s;
    if (!s)
        return;
    while (s->next)
    {
        printf("s:%d\n", s->n);
        s = s->next;
    }
    printf("s:%d\n", s->n);
}