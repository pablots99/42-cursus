/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:42:58 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/12 00:56:22 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_in_str(char *s1,char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		if(s1[i] == '=' && s2[i] == '=')
			return (1);
		i++;
	}
	if ((s2[i] == 0  || s2[i] == '=') && s1[i] == 0)
		return (1);
	return (0);
}

int ft_is_stralphanum(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{	
		if(!ft_isalnum(str[i]))
		{
			if(str[i] != '=')
				return (0);
			else
				return (1);
		}
		i++;
	}
	return (1);
}