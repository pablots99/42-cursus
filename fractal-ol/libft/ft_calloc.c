/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:43:03 by pablo             #+#    #+#             */
/*   Updated: 2020/08/17 20:56:00 by pablo            ###   ########.fr       */
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
