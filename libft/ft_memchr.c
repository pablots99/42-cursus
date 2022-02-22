/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 20:16:33 by pablo             #+#    #+#             */
/*   Updated: 2021/03/15 13:08:06 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	c1;

	c1 = (unsigned char)c;
	src = (unsigned char *)s;
	while (n--)
	{
		if (*src == c1)
			return ((void *)src);
		src++;
	}
	return (NULL);
}
