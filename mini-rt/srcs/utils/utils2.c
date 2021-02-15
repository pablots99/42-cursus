/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:34:52 by pablo             #+#    #+#             */
/*   Updated: 2021/02/15 20:30:34 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"
#include <math.h>

int save_cord(t_cord *cord, char *vec, char *msg)
{
    char **split;

    split = ft_split(vec, ',');
    if (ft_bistrlen(split) != 3)
    {
        ft_bidimensional_free(split);
        ft_printf("%s", msg);
        return (parse_error("Error: Bad number of arguments in the x,y,z cords \n"));
    }
    cord->x = ft_atof(split[0]);
    cord->y = ft_atof(split[1]);
    cord->z = ft_atof(split[2]);
    if (!ft_isfloat(split[0]) || !ft_isfloat(split[1]) || !ft_isfloat(split[2]))
    {
        ft_printf("%s", msg);
        ft_bidimensional_free(split);
        return (parse_error("Error: invalid value for x,y,z \n"));
    }
    ft_bidimensional_free(split);
    return (0);
}

int save_rgb(t_rgb *rgb, char *vec, char *msg)
{
    char **split;

    split = ft_split(vec, ',');
    if (ft_bistrlen(split) != 3)
    {
        ft_bidimensional_free(split);
        ft_printf("%s", msg);
        return (parse_error("Error: Bad number of arguments for R,G,B  \n"));
    }
    rgb->r = ft_atoi(split[0]);
    rgb->g = ft_atoi(split[1]);
    rgb->b = ft_atoi(split[2]);
    if (!(rgb->r < 256 && rgb->r > -1) || !(rgb->g < 256 && rgb->g > -1) || !(rgb->b < 256 && rgb->b > -1) || !ft_str_isnum(split[0]) ||
        !ft_str_isnum(split[1]) || !ft_str_isnum(split[2]))
    {
        ft_printf("%s", msg);
        ft_bidimensional_free(split);
        return (parse_error("Error: invalid value for R,G,B \n"));
    }
    ft_bidimensional_free(split);
    return (0);
}

int ft_isfloat(char *num)
{
    int dot;
    int i;

    dot = 0;
    i = 0;
    if(num[i] == '-')
        i++;
    while (num[i])
    {
        if (!dot && num[i] == '.')
        {
            i++;
            dot++;
        }
        if (!ft_isdigit(num[i]))
            return (0);
        i++;
    }
    return (1);
}
int is_norm_vec(t_cord *cord)
{
    float len;

    len = sqrt(pow(cord->x,2) + pow(cord->y,2) + pow(cord->z,2));
    if(len != 1)
        return (0);
    return (1);
}