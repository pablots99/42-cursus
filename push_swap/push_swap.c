/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:00:18 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/22 00:10:10 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/push_swap.h"

int *sorted_array(int *arr, int len)
{
    int i;
    int j;
    int aux;

    i = 0;
    while (i < len - 1)
    {
        j = i + 1;
        while (j < len)
        {
            if (arr[i] >= arr[j])
            {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
            j++;
        }
        i++;
    }
    return arr;
}
int *sorted_stack_array(stack a)
{
    int *arr;
    int i;
    int len;

    i = 0;
    len = stk_len(a);
    if (len == 0)
        return NULL;
    arr = malloc(len * sizeof(int));
    while (a != NULL)
    {
        arr[i] = a->n;
        i++;
        a = a->next;
    }
    arr = sorted_array(arr, len);
    return arr;
}
typedef struct s_alg2
{
    int *soted_arr;
    int chunk;
    int total_chunks;
    int len;
    int chunk_size;
} t_alg2;

void chunk_rotation(t_alg2 *p, stack *a, stack *b)
{
    int i;
    int *indexes;
    t_aux aux;

    i = 0;
    indexes = (int *)malloc((p->chunk_size) * sizeof(int));
    while (i < p->chunk_size)
    {
        indexes[i] = stk_index(*a, p->soted_arr[i]);
        i++;
    }
    i = 0;
    indexes = sorted_array(indexes, p->chunk_size);
    aux.ra = 1;
    if (indexes[0] > p->len - indexes[p->chunk_size - 1])
    {
        aux.ra = 0;
        aux.movements = p->len - indexes[p->chunk_size - 1];
    }
    else
        aux.movements = indexes[0];
    i = 0;
    stack bb;
    stack aa;
    while (i < aux.movements)
    {
        bb = *b;
        aa = *a;
        if (aux.ra)
        {
            if (stk_len(bb) > 4 && bb->n < bb->next->n)
                rr(a, b);
            else
                ra(a);
        }
        else
            rra(a);
        i++;
    }
    free(indexes);
}
void algorithm_2(stack a, stack b)
{
    t_alg2 p;
    int cont;
    int *sort_2;

    cont = 0;
    //determinar chunks para cada caso
    p.chunk = 0;
    p.len = stk_len(a);
    sort_2 = sorted_stack_array(a);
    p.total_chunks = ft_sqrt(p.len) / 2;
    while (a != NULL)
    {
        p.soted_arr = sorted_stack_array(a);
        p.len = stk_len(a);
        p.chunk_size = p.len / p.total_chunks;
        if (p.chunk_size < p.total_chunks / 2)
            p.chunk_size = p.len;
        chunk_rotation(&p, &a, &b);
        pb(&a, &b);
        cont++;
        free(p.soted_arr);
    }
    //come back all the numbers
    int index;
    p.len = stk_len(b);
    while (p.len--)
    {
        index = stk_index(b, sort_2[p.len]);

        if (index < p.len / 2)
            cont = 1;
        else
            cont = 0;
        while (b->n != sort_2[p.len])
        {
            if (!cont)
                rrb(&b);
            else
                rb(&b);
        }
        pa(&a, &b);
    }
    free(sort_2);
}

void algorithm_1(stack a, stack b)
{
    int *arr;
    int i;
    int len;
    int r;

    r = 0;
    i = 0;
    len = stk_len(a);
    arr = sorted_stack_array(a);
    i = 0;
    while (stk_len(a) != 2)
    {
        if (stk_index(a, arr[i]) < len / 2)
            r = 1;
        else
            r = 0;
        while (a->n != arr[i])
        {
            if (r)
                ra(&a);
            else
                rra(&a);
        }
        pb(&a, &b);
        i++;
    }
    if (a->n > a->next->n)
        sa(&a);
    while (b != NULL)
        pa(&a, &b);
    free(arr);
}


//mirar lo de dividir entre 1.3
int main(int argc, char **argv)
{
    stack a;
    stack b;
    int input_err;

    b = NULL;
    a = NULL;
    input_err = save_input(&a, argv);
    if (argc < 2)
        input_err = 1;
    if (input_err)
    {
        //stk_free(&s);
        write(1, "Error\n", ft_strlen("Error\n"));
        return (1);
    }
    if (is_stack_order(a))
        return 0;
    if (stk_len(a) < 30)
        algorithm_1(a, b);
    else
        algorithm_2(a, b);
    // printf("plen:%d sqrt:%d",stk_len(a), ft_sqrt(stk_len(a)));

    return 0;
}
