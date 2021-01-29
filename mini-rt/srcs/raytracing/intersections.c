/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:19:10 by pablo             #+#    #+#             */
/*   Updated: 2021/01/29 16:17:30 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int spheres_intersection(t_ray *ray, t_list *list,t_file *c)
{
    t_sphere sp;
    t_list *aux;
    int color;
    float len_aux;

    color = 0;
    sp = *(t_sphere *)list->content;
    aux = list;
    while (aux)
    {
        len_aux = ray->len;
        sp = *(t_sphere *)aux->content;
        if (get_sp_inter(ray, sp,c) && ray->len < len_aux)
        {
            color = int_from_rgb(sp.rgb.r,sp.rgb.g,sp.rgb.b);
            ray->object = SPHERE;
            ray->reflexion = sp.refraction;
		if(sp.mapping == 1)
			color = sp_bmp(*ray,sp.bmp,sp);
        }
        aux = aux->next;
    }
    return (color);
}
int plane_intersection(t_ray *ray, t_list *plane)
{
    t_plane pl;
    t_list *aux;
    int color;
    float len_aux;

    color = 0;
    pl = *(t_plane *)plane->content;
    aux = plane;
    while (aux)
    {
        len_aux = ray->len;
        pl = *(t_plane *)aux->content;
        if (get_pl_inter(ray, pl) && ray->len < len_aux)
        {
            color = int_from_rgb(pl.rgb.r,pl.rgb.g,pl.rgb.b);
            ray->object = PLANE;
            ray->reflexion = pl.refraction;
        }
        aux = aux->next;
    }
    return color;
}

int triangle_intersection(t_ray *ray, t_list *plane)
{
    t_triangle tr;
    t_list *aux;
    int color;
    float len_aux;

    color = 0;
    tr = *(t_triangle *)plane->content;
    aux = plane;
    while (aux)
    {
        len_aux = ray->len;
        tr = *(t_triangle *)aux->content;
        if (get_tr_inter(ray, tr) && ray->len < len_aux)
        {
            color = int_from_rgb(tr.rgb.r,tr.rgb.g,tr.rgb.b);
            ray->object = TRIANGLE;
            ray->reflexion = tr.refraction;
        }
        aux = aux->next;
    }
    return color;
}
int square_intersection(t_ray *ray, t_list *plane)
{
    t_square sq;
    t_list *aux;
    int color;
    float len_aux;

    color = 0;
    sq = *(t_square *)plane->content;
    aux = plane;
    while (aux)
    {
        len_aux = ray->len;
        sq = *(t_square *)aux->content;
        if (get_sq_inter(ray, sq) && ray->len < len_aux)
        {
            color = int_from_rgb(sq.rgb.r,sq.rgb.g,sq.rgb.b);
            ray->object = SQUARE;
            ray->reflexion = sq.refraction;
        }
        aux = aux->next;
    }
    return color;
}
int cylinder_intersection(t_ray *ray, t_list *list)
{
    t_cylinder cy;
    t_list *aux;
    int color;
    float len_aux;

    color = 0;
    cy = *(t_cylinder *)list->content;
    aux = list;
    while (aux)
    {
        len_aux = ray->len;
        cy = *(t_cylinder *)aux->content;
        if (get_cy_inter(ray, cy) && ray->len < len_aux)
        {
            color = int_from_rgb(cy.rgb.r,cy.rgb.g,cy.rgb.b);
            ray->object = CYLINDER;
            ray->reflexion = cy.refraction;
        }
        aux = aux->next;
    }
    return (color);
}
