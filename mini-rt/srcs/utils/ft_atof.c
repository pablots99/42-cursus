/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:15:14 by pablo             #+#    #+#             */
/*   Updated: 2020/12/28 19:49:24 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

float ft_atof(char *num)
{
    float res;
    float cont;
    int i;

    i = 0;
    cont = 0;
    res = 0;
    while (num[i])
    {
        if(num[i] == '.' && !cont)
        {
            cont = 1;
            i++;
        }
        if(ft_isdigit(num[i]))
        {
            res = (res * 10 )+ (num[i] - '0');
            if(cont)
                cont *= 10;
        }
        i++;
    }
    if(cont == 0)
        cont = 1;
    if(*num == '-')
        res*=-1;
    return (res / (cont) + ft_atoi(""));
}