/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:51:00 by pablo             #+#    #+#             */
/*   Updated: 2021/01/21 17:34:45 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_sp_inter(t_ray *ray, t_sphere sp)
{
    t_cord l;
    float tca;
    float d;
    float l_p1;

    l = rest_vec(sp.cord, ray->origin);
    tca = proy_vect(ray->direction, l);
    if (tca < 0)
        return (-1);
    d = sqrt(prod_esc(l, l) - (tca * tca));
    if (d < 0 || d > sp.diameter / 2)
        return (-1);
    l_p1 = tca - sqrt(pow(sp.diameter / 2, 2) - pow(d, 2));
    if (l_p1 < ray->len)
    {
        ray->len = l_p1 - 1;
        ray->normal = norm_vec(rest_vec(ray_cut_point(*ray),sp.cord));
    }
    return (1);
}



void move_sphere(t_sphere *sp, int axis)
{
    if (axis == 123)
        sp->cord.x -= 10;
    if (axis == 124)
        sp->cord.x += 10;
    if (axis == 126)
        sp->cord.y += 10;
    if (axis == 125)
        sp->cord.y -= 10;
    if (axis == 45)
        sp->cord.z += 10;
    if (axis == 46)
        sp->cord.z -= 10;
    ft_printf("     Sphere Moved\n");
}
void size_sphere(t_sphere *sp, int k)
{
    if (k == 30)
        sp->diameter += 10;
    if (k == 44)
        sp->diameter -= 10;
    if(sp->diameter < 1)
        sp->diameter = 1;
    ft_printf("     Sphere Resized\n");

}

int select_sp(t_file *c)
{
    if (c->sp_count == 0)
    {
        c->curr_sp = c->sphere;
        c->sp_count++;
    }
    else
    {
        if (c->curr_sp->next)
        {
            c->sp_count++;
            c->curr_sp = c->curr_sp->next;
        }
        else
        {
            c->sp_count = 1;
            c->curr_sp = c->sphere;
        }
    }
    ft_printf("Sphere: %d selected.\n", c->sp_count);
    return (1);
}
