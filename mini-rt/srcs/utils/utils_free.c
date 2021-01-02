/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:09:22 by ptorres           #+#    #+#             */
/*   Updated: 2021/01/02 18:18:57 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void free_config(t_file *c)
{
    if (c->camera)
        ft_lstclear(&c->camera, &free);
    if (c->ligth)
        ft_lstclear(&c->ligth, &free);
    if (c->sphere)
        ft_lstclear(&c->sphere, &free);
    if (c->plane)
        ft_lstclear(&c->plane, &free);
    if (c->square)
        ft_lstclear(&c->square, &free);
    if (c->cylinder)
        ft_lstclear(&c->cylinder, &free);
    if (c->triangle)
        ft_lstclear(&c->triangle, &free);
}
