/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:14:18 by pablo             #+#    #+#             */
/*   Updated: 2021/03/15 13:27:48 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdlib.h>

unsigned int	parts(char const *s, char c)
{
	unsigned int	i;
	unsigned int	cont;

	if (!s[0])
		return (0);
	i = 0;
	cont = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			cont++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		cont++;
	return (cont);
}

int	len_part2(char *s, int i, char c)
{
	int	j;

	j = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		len_parts;
	int		var[3];

	var[1] = -1;
	var[0] = 0;
	if (!s)
		return (NULL);
	len_parts = parts(s, c);
	res = malloc((len_parts + 1) * sizeof(char *));
	while (var[1]++ < len_parts)
	{
		while (s[var[0]] && s[var[0]] == c)
			var[0]++;
		if (var[0] == (int)ft_strlen((char *)s))
			break ;
		var[2] = len_part2((char *)s, var[0], c);
		res[var[1]] = malloc(var[2] * sizeof(char *));
		ft_strlcpy(res[var[1]], &s[var[0]], var[2] + 1);
		var[0] += var[2];
	}
	res[var[1]] = NULL;
	return (res);
}
