/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:00:18 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/19 23:41:05 by pablo            ###   ########.fr       */
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
    int aux;
    int j;
    int len;

    i = 0;
    len = stk_len(a);
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
int stk_is_min(stack b, int n)
{
    while (b != NULL)
    {
        if (n > b->n)
            return 0;
        b = b->next;
    }
    return 1;
}
int stk_index(stack a, int num)
{
    int i;

    i = 0;
    while (a != NULL)
    {
        if (a->n == num)
            return i;
        i++;
        a = a->next;
    }
    return -1; // error ocurred
}

typedef struct s_alg2
{
    int *soted_arr;
    int chunk;
    int total_chunks;
    int len;
    int chunk_size;
} t_alg2;

typedef struct s_aux
{
    int ra;
    int movements;
} t_aux;

void chunk_rotation(t_alg2 p, stack *a, stack *b)
{
    int i;
    int *indexes;
    int not_found;
    t_aux aux;

    i = 0;
    indexes = malloc(p.chunk_size * sizeof(int));
    not_found = 0;
    while (i < p.chunk_size)
    {
        indexes[i] = stk_index(*a, p.soted_arr[i + (p.chunk * p.chunk_size)]);
        if (indexes[i] == -1)
            not_found++;
        i++;
    }
    indexes = sorted_array(indexes, p.chunk_size);
    aux.ra = 1;
    i = 0;
    if (p.len - indexes[0 + not_found] > (indexes[p.chunk_size - 1] - p.len) * -1)
    {
        aux.ra = 0;
        aux.movements = (indexes[p.chunk_size - 1] - p.len) * -1;
    }
    else
        aux.movements = p.len - indexes[0 + not_found];
    i = 0;

    while (i < aux.movements)
    {
        if (aux.ra)
            ra(a);
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
    t_aux actions;
    int *sort_2;

    cont = 0;
    p.total_chunks = 4; //determinar chunks para cada caso
    p.chunk = 0;
    p.len = stk_len(a);
    sort_2 = sorted_stack_array(a);

    while (a != NULL)
    {
        p.soted_arr = sorted_stack_array(a);
        p.len = stk_len(a);
        p.chunk_size = p.len / p.total_chunks;
        chunk_rotation(p, &a, &b);
        pb(&a, &b);
        free(p.soted_arr);
        cont++;
    }
    //come back all the numbers
    // stk_print(b);
    // printf("aaaaa");
    // stk_print(a);
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
    int aux;

    r = 0;
    i = 0;
    len = stk_len(a);
    arr = sorted_stack_array(a);
    i = 0;
    while (stk_len(a) != 2)
    {
        if (len - stk_index(a, arr[i]) <= len / 2)
            r = 1;
        else
            r = 0;
        while (a->n != arr[i])
        {

            if (r)
                rra(&a);
            else
                ra(&a);
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
    if (stk_len(a) < 100)
        algorithm_1(a, b);
    else
        algorithm_2(a, b);
    return 0;
}
