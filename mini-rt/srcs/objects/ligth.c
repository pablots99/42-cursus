/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:35:38 by ptorres           #+#    #+#             */
/*   Updated: 2021/02/01 18:57:21 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"


void move_ligth(t_ligth *l, int axis)
{
	if (axis == 123)
		l->cord.x -= 10;
	if (axis == 124)
		l->cord.x += 10;
	if (axis == 126)
		l->cord.y += 10;
	if (axis == 125)
		l->cord.y -= 10;
	if (axis == 45)
		l->cord.z += 10;
	if (axis == 46)
		l->cord.z -= 10;
	ft_printf("     Ligth Moved\n");
}
void change_ligth_intesity(t_ligth *l, int k)
{
	if (k == 30)
		l->brigthness -= 0.1;
	if (k == 44)
		l->brigthness += 0.1;
	if(l->brigthness > 1)
		l->brigthness = 1;
	if(l->brigthness <= 0)
		l->brigthness = 0;
	ft_printf("     Ligth Intensity: %d\n", l->brigthness);
}
int select_l(t_file *c)
{
    if (c->l_count == 0)
    {
        c->curr_l = c->ligth;
        c->l_count++;
    }
    else
    {
        if (c->curr_l->next)
        {
            c->l_count++;
            c->curr_l = c->curr_l->next;
        }
        else
        {
            c->l_count = 1;
            c->curr_l = c->ligth;
        }
    }
    ft_printf("Ligth: %d selected.\n", c->l_count);
    return (1);
}