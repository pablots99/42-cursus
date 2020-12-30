/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:05:59 by ptorres           #+#    #+#             */
/*   Updated: 2020/12/30 20:30:40 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int len_coma_spaces(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13))
			len++;
		if (str[i] == ',')
		{
			i++;
			while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			{
				len++;
				i++;
			}
			continue ;
		}
		i++;
	}
	return (len);
}

char *ft_clean_spaces(char *str)
{
	int i;
	char *res;
	int aux;

	aux = 0;
	i = 0;
	if (!(res = malloc(sizeof(char) * (ft_strlen(str) - len_coma_spaces(str) + 1))))
		return (NULL);
	//printf("len:%d,spaces:%d\n", (int)ft_strlen(str), len_coma_spaces(str));
	while (str[i])
	{
		if (!(str[i] >= 9 && str[i] <= 13))
		{
			res[aux] = str[i];
			aux++;
		}
		if (str[i] == ',')
		{
			i++;
			while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
				i++;
			continue ;
		}
		i++;
	}
	free(str);
	res[i] = 0;
	return res;
}
