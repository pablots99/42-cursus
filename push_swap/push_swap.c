/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:00:18 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/26 11:59:17 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/push_swap.h"


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
	//stk_free(&a);
    // printf("plen:%d sqrt:%d",stk_len(a), ft_sqrt(stk_len(a)));
	//system("leaks push_swap");
    return 0;
}