/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:15:50 by pablo             #+#    #+#             */
/*   Updated: 2021/02/05 00:42:27 by pablo            ###   ########.fr       */
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

float rand_unit_float()
{
    srand(time(NULL));
    return  (float)rand()/RAND_MAX;
}