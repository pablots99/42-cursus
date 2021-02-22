/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:40:22 by pablo             #+#    #+#             */
/*   Updated: 2020/09/08 00:15:18 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static unsigned int	isequalto(char a, const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
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
	len = ((start - end) < 0) ? ((start - end) * -1) + 2 : start - end + 2;
	if (!(str = malloc(sizeof(char) * len)))
		return (NULL);
	ft_strlcpy(str, &s1[start], len);
	return (str);
}
