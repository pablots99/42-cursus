/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:58:14 by pablo             #+#    #+#             */
/*   Updated: 2021/06/02 11:39:53 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_set_split(char *str,char *set)
{
	int i;
	char last;
	int len;

	i  =0;
	len = ft_strlen(str);
	last = set[ft_strlen(set) -1];
	while(len--)
	{
		i=0;
		while(set[i+1])
		{
			if(str[len] == set[i])
				str[len] = last;
			i++;
		}
	}
	return ft_split(str,last);
}
