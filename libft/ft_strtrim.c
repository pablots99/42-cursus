/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:40:22 by pablo             #+#    #+#             */
/*   Updated: 2021/03/15 13:21:46 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static unsigned int	isequalto(char a, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	unsigned int	len;
	int				start;
	int				end;
	char			*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && isequalto(s1[i], set))
		i++;
	start = i;
	i = ft_strlen((char *)s1) - 1;
	while (i >= 0 && isequalto(s1[i], set))
		i--;
	end = i;
	if ((start - end) < 0)
		len = ((start - end) * -1) + 2;
	else
		len = start - end + 2;
	str = malloc(sizeof(char) * len);
	ft_strlcpy(str, &s1[start], len);
	return (str);
}
