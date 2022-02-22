/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:51:00 by pablo             #+#    #+#             */
/*   Updated: 2021/02/16 22:33:06 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	sp_inter_aux(t_cord *l, t_ray *ray, t_sphere sp, float *tca)
{
	*l = rest_vec(sp.cord, ray->origin);
	*tca = prod_esc(ray->direction, *l);
}

int		get_sp_inter(t_ray *ray, t_sphere sp, t_file *c)
{
	t_cord	l;
	float	tca;
	float	d;
	float	l_p;
	float	tch;

	sp_inter_aux(&l, ray, sp, &tca);
	d = sqrt(prod_esc(l, l) - (tca * tca));
	if (d < 0 || d > sp.diameter / 2)
		return (-1);
	tch = (sqrt(pow(sp.diameter / 2, 2) - pow(d, 2)));
	l_p = tca - tch;
	if (l_p < 0)
		l_p = tca + tch;
	if (l_p < 0)
		return (-1);
	if (!(l_p < ray->len))
		return (-1);
	ray->len = l_p - BIAS;
	ray->normal = norm_vec(rest_vec(ray_cut_point(*ray), sp.cord));
	if (mod_vec(rest_vec(((t_camera *)c->camera->content)->cord, sp.cord))
		<= sp.diameter / 2)
		ray->normal = norm_vec(esc_dot_vec(-1,
			rest_vec(ray_cut_point(*ray), sp.cord)));
	return (1);
}

void	move_sphere(t_sphere *sp, int axis)
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
