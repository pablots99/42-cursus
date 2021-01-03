/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:45:28 by pablo             #+#    #+#             */
/*   Updated: 2021/01/02 23:03:30 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_cord norm_vec(t_cord vec)
{
    t_cord norm_vec;
    float l;

    l = sqrt(pow(vec.x,2) + pow(vec.y,2) + pow(vec.z,2));
    norm_vec.x = vec.x / l;
    norm_vec.y = vec.y / l;
    norm_vec.z = vec.z / l;
    return norm_vec;
}