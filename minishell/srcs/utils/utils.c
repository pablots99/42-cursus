/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 03:21:03 by pablo             #+#    #+#             */
/*   Updated: 2021/07/07 22:24:42 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int ft_str_equal(char *s1, char *s2)
{
	int i;
	int len1;
	int len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	if(len1 != len2)
		return (0);
	while(i < len1)
	{
		if(s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char *ft_append_char(char *str, char c)
{
	int len;
	char *res;
	int i;

	res = malloc(ft_strlen(str)+2 *sizeof(char));
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	i++;
	res[i] = 0;
	free(str);
	return (res);

}
