/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:56:26 by pablo             #+#    #+#             */
/*   Updated: 2021/03/15 13:19:41 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*src;
	int		i;

	i = 0;
	if ((!s))
		return (NULL);
	if (start > ft_strlen((char *)s))
	{
		src = malloc(sizeof(char));
		src[0] = '\0';
		return (src);
	}
	src = malloc((len + 1) * sizeof(char));
	while (s[start] && len--)
	{
		src[i] = (char)s[start];
		start++;
		i++;
	}
	src[i] = '\0';
	return (src);
}
