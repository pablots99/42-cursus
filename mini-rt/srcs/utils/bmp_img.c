/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:27:31 by pablo             #+#    #+#             */
/*   Updated: 2021/01/27 09:44:27 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"


int create_bmp(t_file *c,char *file)
{
    int fd;

    if (!(fd = open(file,O_CREAT)))
        return ft_printf("Bmp Error: Can´t create Bmp file\n");

    return 0;
}