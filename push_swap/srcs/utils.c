/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:53:37 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/21 17:33:22 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_bidimensional_free(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

int is_stack_order(stack a)
{
    int aux;

    if (a == NULL)
        return -1;

    aux = a->n;
    a = a->next;
    while (a != NULL)
    {
        if (aux > a->n)
            return 0;
        aux = a->n;
        a = a->next;
    }
    return 1;
}

int save_input(stack *s, char **input)
{
    int i;
    int j;
    char **splited;

    i = 1;
    while (input[i])
    {
        j = 0;
        splited = ft_split(input[i], ' ');
        while (splited[j])
        {
            if (input_errors(*s, splited[j]))
            {
                ft_bidimensional_free(splited);
                return 1;
            }
            stk_push_last(s, (int)ft_atoi(splited[j]));
            j++;
        }
        ft_bidimensional_free(splited);
        i++;
    }
    return 0;
}

int input_errors(stack s, char *input)
{
    int i;
    long int num;

    i = 0;
    while (input[i])
    {
        if (!ft_isdigit(input[i]))
            return (1);
        i++;
    }
    num = ft_atoi(input);
    if (ft_strlen(input) > 11 || num > 2147483647 || num < -2147483648)
        return (1);
    while (s)
    {
        if (s->n == (int)num)
            return (1);
        s = s->next;
    }
    return 0;
}

int ft_sqrt(int n)
{
    int i;
    i = 0;
    while (i * i != n && i * i < n )
        i++;
    return i;
}
