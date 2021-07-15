/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:05:18 by pablo             #+#    #+#             */
/*   Updated: 2021/07/14 02:42:06 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//dst has to be memory allocated
void ft_append(char **dst,char *str)
{
	char *aux;

	aux = 	ft_strjoin(*dst,str);
	free(*dst);
	*dst = aux;
}
