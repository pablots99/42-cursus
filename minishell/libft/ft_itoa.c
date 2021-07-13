/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:07:30 by pablo             #+#    #+#             */
/*   Updated: 2021/07/12 13:51:36 by pablo            ###   ########.fr       */
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
	while (n /= 10)
		i++;
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
