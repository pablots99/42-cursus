/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 21:25:17 by pablo             #+#    #+#             */
/*   Updated: 2021/04/09 17:33:34 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gn_ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	gn_ft_strcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < ((unsigned int)dstsize))
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (i);
}

char	*gn_ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	if (!(ptr = (char *)malloc((ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1 && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	free((char *)s1);
	ptr[i] = '\0';
	return (ptr);
}
