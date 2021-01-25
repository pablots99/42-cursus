/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:15:50 by pablo             #+#    #+#             */
/*   Updated: 2021/01/25 18:13:40 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

float max_float(float a, float b)
{
    return ((a>b)?a:b);
}


float min_float(float a, float b)
{
    return ((a<b)?a:b);
}

int min_int(int a, int b)
{
    return ((a<b)?a:b);
}