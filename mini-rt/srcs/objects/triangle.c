/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:06:16 by pablo             #+#    #+#             */
/*   Updated: 2021/01/25 16:15:34 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_tr_inter(t_ray *ray, t_triangle tr)
{
    float len;
    float den;
    t_cord ab;
    t_cord normal;
    t_cord p;

    normal = norm_vec(prod_vec((rest_vec(tr.cord_2, tr.cord_3)),
                               (rest_vec(tr.cord_3, tr.cord_1))));
    den = prod_esc(ray->direction, normal);
    if (fabs(den) > 0)
    {
        if ((len = prod_esc(rest_vec(tr.cord_1, ray->origin), normal) / den) > 0)
        {
            p = ray_intersection(*ray, len);
            ab = barycentric_cords(tr, p);
            if (len < ray->len && (ab.x <= 1 && ab.x >= 0) &&
                (ab.y <= 1 && ab.y >= 0) &&  (ab.z <= 1 && ab.z >= 0))
            {
                ray->normal = esc_dot_vec(-1, normal);
                ray->len = len - BIAS;
                return 1;
            }
        }
    }
    return -1;
}



int select_tr(t_file *c)
{
    if (c->tr_count == 0)
    {
        c->curr_tr = c->triangle;
        c->tr_count++;
    }
    else
    {
        if (c->curr_tr->next)
        {
            c->tr_count++;
            c->curr_tr = c->curr_tr->next;
        }
        else
        {
            c->tr_count = 1;
            c->curr_tr = c->triangle;
        }
    }
    ft_printf("Cylinder: %d selected.\n", c->tr_count);
    return (1);
}

void move_triangle(t_triangle *tr, int axis)
{
    if (axis == 123)
        sum_vec2(-10,&tr->cord_1.x,&tr->cord_2.x,&tr->cord_3.x);
    if (axis == 124)
        sum_vec2(10,&tr->cord_1.x,&tr->cord_2.x,&tr->cord_3.x);
    if (axis == 126)
        sum_vec2(10,&tr->cord_1.y,&tr->cord_2.y,&tr->cord_3.y);
    if (axis == 125)
        sum_vec2(-10,&tr->cord_1.y,&tr->cord_2.y,&tr->cord_3.y);
    if (axis == 45)
        sum_vec2(10,&tr->cord_1.z,&tr->cord_2.z,&tr->cord_3.z);
    if (axis == 46)
        sum_vec2(-10,&tr->cord_1.z,&tr->cord_2.z,&tr->cord_3.z);
    ft_printf("     Triangle Moved\n");
}
void size_triangle(t_triangle *tr, int k)
{
    if (k == 30)
    {
       tr->cord_1 = esc_dot_vec(1.3,tr->cord_1);
       tr->cord_2 = esc_dot_vec(1.3,tr->cord_2);
       tr->cord_3 = esc_dot_vec(1.3,tr->cord_3);
    }
    if (k == 44)
    {
       tr->cord_1 = esc_dot_vec(0.7,tr->cord_1);
       tr->cord_2 = esc_dot_vec(0.7,tr->cord_2);
       tr->cord_3 = esc_dot_vec(0.7,tr->cord_3);
    }
    ft_printf("     Triangle Resized\n");
}
