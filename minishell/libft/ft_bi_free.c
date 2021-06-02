/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bi_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:36:55 by ptorres           #+#    #+#             */
/*   Updated: 2021/06/02 00:49:50 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


void ft_bi_free(char **arr)
{
	int len;
	int	i;

	len = ft_bi_strlen(arr);
	i = 0;
	while (len != 1 && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int ft_bi_strlen(char **arr)
{
	int i;

	i = 0;
	while(arr[i])
		i++;
	return i;
}
