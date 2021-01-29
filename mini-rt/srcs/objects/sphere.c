/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:51:00 by pablo             #+#    #+#             */
/*   Updated: 2021/01/29 16:23:53 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_sp_inter(t_ray *ray, t_sphere sp,t_file *c)
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
        ray->len = l_p1 - BIAS;
        ray->normal = norm_vec(rest_vec(ray_cut_point(*ray),sp.cord));
        if(mod_vec(rest_vec(((t_camera*)c->camera->content)->cord,sp.cord)) <= sp.diameter/2)
        {
            ray->len = l_p1 - BIAS;
            ray->normal = norm_vec(esc_dot_vec(-1,rest_vec(ray_cut_point(*ray),sp.cord)));
        }
    }
    return (1);
}
int get_sp_inter_analitic(t_ray *ray, t_sphere sp,t_file *c)
{
	return 0 ;
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
