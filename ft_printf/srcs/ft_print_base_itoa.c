/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base_itoa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:10:31 by pablo             #+#    #+#             */
/*   Updated: 2020/11/30 21:36:09 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_negb(long int n)
{
	if (n < 0)
		return (1);
	return (0);
}

void	is_neg2b(long int *aux, char *ptr, int *i)
{
	if (*aux < 0)
	{
		ptr[0] = '-';
		*aux *= -1;
		*i += 1;
	}
}

char	*ft_print_base_itoa(long int n, int base, int mayus)
{
	char	*ptr;
	int		i;
	long	aux;
	char	*base_str;

	base_str = "0123456789abcdef";
	i = 1;
	aux = n;
	while (n /= base)
		i++;
	if (!(ptr = (char *)malloc((i + (is_negb(aux) ? 2 : 1)) * sizeof(char))))
		return (0);
	is_neg2b(&aux, ptr, &i);
	ptr[i] = '\0';
	while (i-- && ptr[i] != '-')
	{
		ptr[i] = base_str[aux % base];
		aux /= base;
	}
	i = ft_strlen(ptr);
	if (mayus == 1)
		ft_str_toupper(ptr);
	return (ptr);
}
