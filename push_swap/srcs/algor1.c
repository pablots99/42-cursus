/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:57:30 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/21 00:57:41 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_half(stack *a, stack *b, int *sorted, int len)
{
    int i;
    int j;
    t_aux aux;
    int *indexes;
    int *indexes2;
    stack moved;
    int len_index;

    //calculate len idex;
    moved = NULL;
    i = 0;

    while (i < len / 2 && a != NULL)
    {
        len_index = 0;
        j = 0;

        while (j < len / 2)
        {
            if (stk_index(moved, sorted[j]) == -1)
                len_index++;
            j++;
        }
        indexes = malloc(len_index * sizeof(int));
        indexes2 = malloc(len_index * sizeof(int));
        len_index = 0;
        j = 0;
        while (j < len / 2)
        {
            if (stk_index(moved, sorted[j]) == -1)
            {
                indexes[len_index] = stk_index(*a, sorted[j]);
                indexes2[len_index] = sorted[j];
                len_index++;
            }
            j++;
        }
        printf("len:%d, len_index:%d\n", len, len_index);
        printf("moved\n");
        stk_print(moved);
        printf("a\n");
        stk_print(*a);
        j = 0;
        while (j < len_index)
        {
            printf("%d- ", indexes[j]);
            j++;
        }
        printf("\n");
        j = 0;
        while (j < len_index)
        {
            printf("%d- ", indexes2[j]);
            j++;
        }
        printf("\n");
        j = 0;
        indexes = sorted_array(indexes, len_index);
        while (j < len_index)
        {
            printf("%d- ", indexes[j]);
            j++;
        }
        printf("\n");
        aux.ra = 1;
        if (indexes[0] > len - indexes[len_index - 1])
        {
            aux.ra = 0;
            aux.movements = len - indexes[len_index - 1];
        }
        else
            aux.movements = indexes[0];
        j = 0;
        while (j < aux.movements)
        {
            if (aux.ra)
                ra(a);
            else
                rra(a);
            j++;
        }
        stack aa = *a;
        stk_push(&moved, aa->n);
        pb(a, b);
        free(indexes);
        i++;
    }
}

void algorithm_3(stack a, stack b)
{
    int *sorted_a;
    int *sort_2;
    int len_a;
    int index;
    int cont;

    len_a = 0;
    if (is_stack_order(a))
        return;
    sort_2 = sorted_stack_array(a);
    while (stk_len(a) > 1)
    {
        len_a = stk_len(a);
        sorted_a = sorted_stack_array(a);
        move_half(&a, &b, sorted_a, len_a);
        free(sorted_a);
    //     printf("bbbbbb\n");
    //     stk_print(b);
     }
    pb(&a, &b);
    len_a = stk_len(b);
    // printf("len_a:%d",len_a);
    while (len_a--)
    {
        index = stk_index(b, sort_2[len_a]);

        if (index < len_a / 2)
            cont = 1;
        else
            cont = 0;
        while (b->n != sort_2[len_a])
        {
            if (!cont)
                rrb(&b);
            else
                rb(&b);
        }
        pa(&a, &b);
    }
}