/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:56:26 by pablo             #+#    #+#             */
/*   Updated: 2020/09/07 15:27:05 by pablo            ###   ########.fr       */
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
		if (!(src = malloc(sizeof(char))))
			return (NULL);
		src[0] = '\0';
		return (src);
	}
	if (!(src = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (s[start] && len--)
	{
		src[i] = (char)s[start];
		start++;
		i++;
	}
	src[i] = '\0';
	return (src);
}
