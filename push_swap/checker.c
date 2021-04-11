/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:47:40 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/11 17:14:15 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/push_swap.h"



int execute_comand(stack *a, stack *b, char *command)
{
    if (!ft_strncmp(command, "sa", ft_strlen(command)))
        swap_top(*a);
    else if (!ft_strncmp(command, "sb", ft_strlen(command)))
        swap_top(*b);
    else if (!ft_strncmp(command, "ss", ft_strlen(command)))
        swap_top(*a), swap_top(*b);
    else if (!ft_strncmp(command, "pa", ft_strlen(command)))
        push_from_stack(a,b);
    else if (!ft_strncmp(command, "pb", ft_strlen(command)))
        push_from_stack(b,a);
    else if (!ft_strncmp(command, "ra", ft_strlen(command)))
        stk_shift(a);
    else if (!ft_strncmp(command, "rb", ft_strlen(command)))
        stk_shift(b);
    else if (!ft_strncmp(command, "rr", ft_strlen(command)))
        stk_shift(a) , stk_shift(b);
    else if (!ft_strncmp(command, "rra", ft_strlen(command)))
        stk_rev_shift(a);
    else if (!ft_strncmp(command, "rrb", ft_strlen(command)))
        stk_rev_shift(b);
    else if (!ft_strncmp(command, "rrr", ft_strlen(command)))
        stk_rev_shift(a), stk_rev_shift(b);
    else
        return 1;
    return 0;
}
int recive_commands(stack *a, stack *b)
{
    char *line;

    get_next_line(0, &line);
    while (ft_strncmp(line, "\n", ft_strlen(line)) && ft_strlen(line))
    {
        if (execute_comand(a, b, line))
        {
            free(line);
            return 1;
        }
        free(line);
        get_next_line(0, &line);
    }
    free(line);
    return 0;
}


int main(int argc, char **argv)
{
    stack a;
    stack b;
    int input_err;

    a = NULL;
    b = NULL;
    input_err = save_input(&a, argv);
    if (argc < 2)
        input_err = 1;
    if (!input_err)
        input_err = recive_commands(&a, &b);
    if (input_err)
    {
        //stk_free(&s);
        write(1, "Error\n", ft_strlen("Error\n"));
        return (1);
    }
    if(is_stack_order(a))
        write(1,"[OK]\n",5);
    else
        write(1,"[KO]\n",5);
    printf("aaaaaaaaaaaa\n");
    stk_print(a);
    printf("bbbbbbbbbbbbb\n");
    stk_print(b);
    printf("argc: %d", argc);
    return 0;
}