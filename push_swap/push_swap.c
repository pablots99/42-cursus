/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:00:18 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/13 18:42:22 by ptorres          ###   ########.fr       */
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

int stk_is_min(stack b,int n)
{
	while (b != NULL)
	{
		if (n > b->n)
			return 0;
		b = b->next;
	}
	return 1;
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


void algorithm_2(stack a, stack b)
{
	int *sorted_list;
	int aux;
	
	if(is_stack_order(a))
		return ;
	sorted_list = sorted_array(a);
	if(b == NULL)
		pb(&a,&b);
	if(stk_len(b) != 3)
	{
		pb(&a,&b);
		if(b->n < b->next->n)
			sb(&b);
	}
	while (stk_len(a) != 0)
	{
		aux = 0;
		if(a != NULL && stk_is_min(b,a->n))
		{
			pb(&a,&b);
			rb(&b);
		}
		while(a != NULL && a->n < b->n)
		{
			rb(&b);
			aux++;
		}
		while(a != NULL && a->n > b->n)
			pb(&a,&b);
		while(aux--)
			rrb(&b);
	}
	while(b != NULL)
		pa(&a,&b);
	stk_print(a);
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
	if(is_stack_order(a))
		return ;
    len =  stk_len(a);
    arr =  sorted_array(a);
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
    if(a->n > a->next->n)
        sa(&a);
    while (b != NULL)
        pa(&a,&b);
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
    algorithm_2(a,b);
    return 0;
}

