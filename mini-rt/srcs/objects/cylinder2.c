/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:00:01 by pablo             #+#    #+#             */
/*   Updated: 2021/01/24 14:17:45 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int select_cy(t_file *c)
{
    if (c->cy_count == 0)
    {
        c->curr_cy = c->cylinder;
        c->cy_count++;
    }
    else
    {
        if (c->curr_cy->next)
        {
            c->cy_count++;
            c->curr_cy = c->curr_cy->next;
        }
        else
        {
            c->cy_count = 1;
            c->curr_cy = c->cylinder;
        }
    }
    ft_printf("Cylinder: %d selected.\n", c->cy_count);
    return (1);
}

void move_cylinder(t_cylinder *cy, int axis)
{
    if (axis == 123)
        cy->cord.x -= 10;
    if (axis == 124)
        cy->cord.x += 10;
    if (axis == 126)
        cy->cord.y += 10;
    if (axis == 125)
        cy->cord.y -= 10;
    if (axis == 45)
        cy->cord.z += 10;
    if (axis == 46)
        cy->cord.z -= 10;
    ft_printf("     Cylinder Moved\n");
}
void size_cylinder(t_cylinder *cy, int k)
{
    if (k == 30)
    {
        cy->height += 10;
        cy->diameter += 10;
    }
    if (k == 44)
    {
        cy->height -= 10;
        cy->diameter -= 10;
    }
    if (cy->height < 1)
        cy->height = 1;
     if (cy->diameter < 1)
        cy->diameter = 1;
    ft_printf("     Cylinder Resized\n");
}