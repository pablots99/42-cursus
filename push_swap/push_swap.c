/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:00:18 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/11 18:17:16 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/push_swap.h"





void print_commands(stack a)
{
    stack b;
    b = NULL;
    stk_print(a);
}

int main(int argc, char **argv)
{
    stack a;
    int input_err;

    A = NULL;
    input_err = save_input(&a,argv);
    if (argc < 2)
        input_err = 1;
    if (input_err)
    {
        //stk_free(&s);
        write(1, "Error\n", ft_strlen("Error\n"));
        return (1);
    }
    print_commands(a);
    return 0;
}

