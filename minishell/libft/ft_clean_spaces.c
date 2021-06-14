/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:12:12 by pablo             #+#    #+#             */
/*   Updated: 2021/06/09 19:11:14 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int count_set(char *str,char *set)
{
	int i;
	int j;
	int count;

	count   =0 ;
	i = 0;
	while(str[i])
	{
		j  = 0;
		while(set[j])
		{
			while(str[i] == set[j])
			{
				count++;
				break ;
			}
			j++;
		}
		i++;
	}
	return count;
}

char* ft_clean_chars(char *str,char *set)
{
	char *res;
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	res = malloc((count_set(str,set) +100 )*sizeof(char));
	while(str[i])
	{
		j  = 0;
		while(set[j])
		{
			while(str[i] == set[j])
				i++;
			j++;
		}
		res[count] = str[i];
		count++;
		i++;
	}
	res[count] = 0;
	return res;
}
