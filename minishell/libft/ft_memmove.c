/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 20:16:04 by pablo             #+#    #+#             */
/*   Updated: 2021/03/15 13:26:32 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = len;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (s < d)
		while (len--)
			d[len] = s[len];
	else
	{
		while (i)
		{
			*d = *s;
			d++;
			s++;
		}
	}
	return (dst);
}
