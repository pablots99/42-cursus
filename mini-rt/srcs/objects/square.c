/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:06:52 by pablo             #+#    #+#             */
/*   Updated: 2021/01/31 17:16:11 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int get_sq_inter(t_ray *ray, t_square sq)
{
    float den;
    float len;
    t_triangle tr;
    t_cord ab;

    den = prod_esc(ray->direction, sq.norm_v);
    if (fabs(den) > 0)
    {
        len = prod_esc(rest_vec(sq.cord, ray->origin), sq.norm_v) / den;
        if ( len >= 0 && len < ray->len)
        {
            tr = new_triangle(sq.points.p0, sq.points.p1, sq.points.p2);
            ab = barycentric_cords(tr, ray_intersection(*ray, len));
            if ((ab.x <= 1 && ab.x >= 0) && (ab.y <= 1 && ab.y >= 0))
            {
                ray->len = len - BIAS;
                ray->normal =  sq.norm_v; 
                return (1);
            }
        }
    }
    return (-1);
}
void move_square(t_square *sq, int axis)
{
    if (axis == 123)
        sq->cord.x -= 10;
    if (axis == 124)
        sq->cord.x += 10;
    if (axis == 126)
        sq->cord.y += 10;
    if (axis == 125)
        sq->cord.y -= 10;
    if (axis == 45)
        sq->cord.z += 10;
    if (axis == 46)
        sq->cord.z -= 10;
    save_sq_points(sq);
    ft_printf("     Square Moved\n");
}
void size_square(t_square *sq, int k)
{
    if (k == 30)
        sq->side += 10;
    if (k == 44)
        sq->side -= 10;
    if (sq->side < 1)
        sq->side = 1;
    save_sq_points(sq);
    ft_printf("     Square Resized\n");
}

int select_sq(t_file *c)
{
    if (c->sq_count == 0)
    {
        c->curr_sq = c->square;
        c->sq_count++;
    }
    else
    {
        if (c->curr_sq->next)
        {
            c->sq_count++;
            c->curr_sq = c->curr_sq->next;
        }
        else
        {
            c->sq_count = 1;
            c->curr_sq = c->square;
        }
    }
    ft_printf("Square: %d selected.\n", c->sq_count);
    return (1);
}
void rot_sq(t_square *sq, int key)
{
	int angle;

	angle = ROT_ANGLE;
	if (key == 0)
		sq->norm_v = rot_vec_x(sq->norm_v, angle);
	if (key == 2)
		sq->norm_v = rot_vec_x(sq->norm_v ,-angle);
	if (key == 13)
		sq->norm_v = rot_vec_y(sq->norm_v, angle);
	if (key == 1)
		sq->norm_v = rot_vec_y(sq->norm_v, -angle);
	if (key == 6)
		sq->norm_v = rot_vec_z(sq->norm_v, angle);
	if (key == 7)
		sq->norm_v = rot_vec_z(sq->norm_v, -angle);
	sq->norm_v = norm_vec(sq->norm_v);
	ft_printf("Square: rotated\n");
}

