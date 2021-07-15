/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bi_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:36:55 by ptorres           #+#    #+#             */
/*   Updated: 2021/07/13 23:15:28 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


void ft_bi_free(char **arr)
{
	int	i;

	i = 0;
	if(!arr)
		return ;
	while (arr[i] && arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void ft_bi_free_debug(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] && arr[i] != NULL)
	{
		printf("i:%d\n",i);
		free(arr[i]);
		i++;
	}
	free(arr);
}

int ft_bi_strlen(char **arr)
{
	int i;

	i = 0;
	if(!arr)
		return (0);
	while(arr[i])
		i++;
	return i;
}
