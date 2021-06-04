/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 00:34:01 by pablo             #+#    #+#             */
/*   Updated: 2021/06/03 00:36:30 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int		int_from_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}