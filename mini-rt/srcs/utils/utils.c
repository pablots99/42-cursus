/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:18:03 by pablo             #+#    #+#             */
/*   Updated: 2020/12/28 23:47:38 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../mini_rt.h"

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

int ft_str_isnum(char *num)
{
    int i;

    i = 0;
    while (num[i])
    {
        if (!ft_isdigit(num[i]))
            return (0);
        i++;
    }
    return (1);
}
int ft_bistrlen(char **str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}
int parse_error( char *err)
{
    //liberar config;

    ft_printf("Error\n     %s\n",err);
    return (1);
}

void free_struct(t_file config)
{
    
}