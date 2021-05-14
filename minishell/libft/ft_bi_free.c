/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bi_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:36:55 by ptorres           #+#    #+#             */
/*   Updated: 2021/05/14 13:44:16 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


void ft_bi_free(char **arr)
{
	
	int	i;
	i = 0;
	while (arr[i])
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