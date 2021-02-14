/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:11:14 by pablo             #+#    #+#             */
/*   Updated: 2021/02/14 21:54:52 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_py_inter(t_ray *ray, t_pyramid py)
{
    int cond;

    cond = 0;
    cond += get_sq_inter(ray,&py.base);
    cond += get_tr_inter(ray,py.tr1);
    cond += get_tr_inter(ray,py.tr2);
    cond += get_tr_inter(ray,py.tr3);
    cond += get_tr_inter(ray,py.tr4);
  
    if(cond > -5)
        return 1;
    return 0;
}

int select_py(t_file *c)
{
    if (c->py_count == 0)
    {
        c->curr_py = c->pyramid;
        c->py_count++;
    }
    else
    {
        if (c->curr_py->next)
        {
            c->py_count++;
            c->curr_py = c->curr_py->next;
        }
        else
        {
            c->py_count = 1;
            c->curr_py = c->pyramid;
        }
    }
    ft_printf("Pyramid: %d selected.\n", c->py_count);
    return (1);
}

void move_pyramid(t_pyramid *py, int axis)
{
	if (axis == 123)
		py->cord.x -= 10;
	if (axis == 124)
		py->cord.x += 10;
	if (axis == 126)
		py->cord.y += 10;
	if (axis == 125)
		py->cord.y -= 10;
	if (axis == 45)
		py->cord.z += 10;
	if (axis == 46)
		py->cord.z -= 10;
    save_sq_points(&py->base);
    save_py_faces(py);
	ft_printf("     Pyramid Moved\n");
}

void rot_py(t_pyramid *py, int key)
{
    rot_sq(&py->base,key);
    save_py_faces(py);
}
