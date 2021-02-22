/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:07:30 by pablo             #+#    #+#             */
/*   Updated: 2020/09/07 21:35:35 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		is_neg(int n)
{
	if (n < 0)
		return (1);
	return (0);
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
	if (aux != -2147483648 &&
			!(ptr = (char *)malloc((i + (is_neg(aux) ? 2 : 1)) * sizeof(char))))
		return (NULL);
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
