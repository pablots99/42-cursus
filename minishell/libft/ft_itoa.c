/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:07:30 by pablo             #+#    #+#             */
/*   Updated: 2021/09/11 20:42:12 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	is_neg(int n)
{
	if (n < 0)
		return (2);
	return (1);
}

void	is_neg2(int *aux, char *ptr, int *i)
{
	if (*aux < 0)
	{
		ptr[0] = '-';
		*aux *= -1;
		*i += 1;
	}
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		aux;

	i = 1;
	aux = n;
	n /= 10;
	while (n)
	{
		i++;
		n /= 10;
	}
	if (aux != -2147483648)
		ptr = (char *)malloc((i + (is_neg(aux)) * sizeof(char)));
	if (aux == -2147483648)
		return (ft_strdup("-2147483648"));
	is_neg2(&aux, ptr, &i);
	ptr[i] = '\0';
	while (i-- && ptr[i] != '-')
	{
		ptr[i] = '0' + aux % 10;
		aux /= 10;
	}
	return (ptr);
}
