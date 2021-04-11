/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:00:18 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/11 23:43:19 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/push_swap.h"



int *sorted_array(stack a)
{
    int *arr;
    int i;
    int aux;
    int j;
    int len;
    
    i = 0;
    len = stk_len(a);
    arr = malloc(len * sizeof(int));
    while(a != NULL)
    {
        arr[i] = a->n;
        i++;
        a = a->next;
    }
    i = 0;
    while (i < len -1)
    {
        j = i + 1;
        while (j < len)
        {
            if(arr[i] > arr[j])
            {
                aux =  arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
            j++;
        }
        i++;
    }
   return arr;
}


int stk_index(stack a,int num)
{
    int i;

    i = 0;
    while (a != NULL)
    {
        if(a->n == num)
            return i;
        i++;
        a = a->next;
    }
    return -1; // error ocurred
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
    len =  stk_len(a);
    arr =  sorted_array(a);
    //buscar el primer elemento y ver que sale mas rentable si rra o ra //pusearlo asi hasta que queden 3
    i = 0;
    while(stk_len(a) != 2)
    {
         if(len - stk_index(a,arr[i]) <= len/2)
            r = 1;
         else 
            r = 0;
        while(a->n != arr[i])
        {
            if(r)
                rra(&a);
            else 
                ra(&a);
        }
        pb(&a,&b);
        i++;
    }
    // ordenarlos y volver a pusher
    if(a->n > a->next->n)
        sa(&a);
    while (b != NULL)
        pa(&a,&b);
    
    // printf("aaaaaaaa\n");
    // stk_print(a);
    // printf("bbbbbbbb\n");
    // stk_print(b);
    free(arr);
}

int main(int argc, char **argv)
{
    stack a;
    stack b;
    int input_err;

    b = NULL;
    a = NULL;
    input_err = save_input(&a,argv);
    if (argc < 2)
        input_err = 1;
    if (input_err)
    {
        //stk_free(&s);
        write(1, "Error\n", ft_strlen("Error\n"));
        return (1);
    }
    algorithm_1(a,b);
    return 0;
}

