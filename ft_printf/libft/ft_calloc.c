/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:43:03 by pablo             #+#    #+#             */
/*   Updated: 2020/11/25 20:17:29 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void*
	ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	int		i;
	int		x;

	ptr = (void *)malloc(count * size);
	i = 0;
	x = count * size;
	if (!ptr)
		return (NULL);
	while (x--)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
