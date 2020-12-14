/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:22:59 by pablo             #+#    #+#             */
/*   Updated: 2020/12/13 21:51:41 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///// el ultimo free lo hace antes de terminar y se tiene que hacer fuera

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    int i;

    i = 0;
    if (!s)
        return (0);
    while (s[i] != '\0')
        i++;
    return (i);
}
char *push(char *str, char c)
{
    char *res;
    int i;

    if (c == '\n')
        c = '\0';
    i = 0;
    if (*str)
    {
        res = malloc((ft_strlen(str) + 2)* sizeof(char));
        while (str[i])
        {
            res[i] = str[i];
            i++;
        }
        res[i] = c;
        res[i + 1] = '\0';
        free(str);
    }
    else
    {
        res = malloc(3 * sizeof(char));
        *res = c;
        res[1] = '\0';
     
    }
    return res;
}

int	get_next_line(char **line)
{
    char buffer[1];

    *line = "";
    buffer[0] = '0';
    while (buffer[0] != '\n')
    {
        if (read(0, buffer, 1) > 0)
            *line = push(*line, buffer[0]);
        else
            return (0);
    }
    return (1);
}
