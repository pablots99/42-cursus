/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:19:10 by pablo             #+#    #+#             */
/*   Updated: 2021/01/15 17:22:11 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int spheres_intersection(t_ray *ray, t_list *list, t_file c)
{
    t_sphere sp;
    t_list *aux;
    int color;
    float len_aux;

    color = 0;
    sp = *(t_sphere *)list->content;
    aux = list;
    while (aux->next)
    {
        len_aux = ray->len;
        sp = *(t_sphere *)aux->content;
        if (get_sp_inter(ray, sp) && ray->len < len_aux)
            color = create_int_color(sp.rgb, c.ambient_ligth);
        aux = aux->next;
    }
    len_aux = ray->len;
    sp = *(t_sphere *)aux->content;
    if (get_sp_inter(ray, sp) && ray->len < len_aux)
        color = create_int_color(sp.rgb, c.ambient_ligth);
    return (color);
}


int plane_intersection(t_ray *ray, t_list *plane,t_file c)
{
    t_plane pl;
    t_list *aux;
    int color;
    float len_aux;

    color = 0;
    pl = *(t_plane *)plane->content;
    aux = plane;
    while (aux->next)
    {
        len_aux = ray->len;
        pl = *(t_plane *)aux->content;
        if (get_pl_inter(ray, pl) && ray->len < len_aux)
            color = create_int_color(pl.rgb,c.ambient_ligth);
        aux = aux->next;
    }
    len_aux = ray->len;
    pl = *(t_plane *)aux->content;
   if (get_pl_inter(ray, pl) && ray->len < len_aux)
            color = create_int_color(pl.rgb,c.ambient_ligth);
    aux = aux->next;
    return color;
}

int triangle_intersection(t_ray *ray, t_list *plane, t_file c)
{
    t_triangle tr;
    t_list *aux;
    int color;
    float len_aux;

    color = 0;
    tr = *(t_triangle *)plane->content;
    aux = plane;
    while (aux->next)
    {
        len_aux = ray->len;
        tr = *(t_triangle *)aux->content;
        if (get_tr_inter(ray, tr) && ray->len < len_aux)
            color = create_int_color(tr.rgb, c.ambient_ligth);
        aux = aux->next;
    }
    len_aux = ray->len;
    tr = *(t_triangle *)aux->content;
    if (get_tr_inter(ray, tr) && ray->len < len_aux)
        color = create_int_color(tr.rgb, c.ambient_ligth);
    aux = aux->next;
    return color;
}
int square_intersection(t_ray *ray, t_list *plane,t_file c)
{
    t_square sq;
    t_list *aux;
    int color;
    float len_aux;

    color = 0;
    sq = *(t_square *)plane->content;
    aux = plane;
    while (aux->next)
    {
        len_aux = ray->len;
        sq = *(t_square *)aux->content;
        if (get_sq_inter(ray, sq) && ray->len < len_aux)
            color = create_int_color(sq.rgb,c.ambient_ligth);
        aux = aux->next;
    }
    len_aux = ray->len;
    sq = *(t_square *)aux->content;
   if (get_sq_inter(ray, sq) && ray->len < len_aux)
            color = create_int_color(sq.rgb,c.ambient_ligth);
    aux = aux->next;
    return color;
}
int cylinder_intersection(t_ray *ray, t_list *list, t_file c)
{
    t_cylinder cy;
    t_list *aux;
    int color;
    float len_aux;

    color = 0;
    cy = *(t_cylinder *)list->content;
    aux = list;
    while (aux->next)
    {
        len_aux = ray->len;
        cy = *(t_cylinder *)aux->content;
        if (get_cy_inter(ray, cy))
            color = create_int_color(cy.rgb, c.ambient_ligth);
        aux = aux->next;
    }
    len_aux = ray->len;
    cy = *(t_cylinder *)aux->content;
    if (get_cy_inter(ray, cy))
        color = create_int_color(cy.rgb, c.ambient_ligth);

    return (color);
}
