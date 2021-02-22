/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:16:04 by pablo             #+#    #+#             */
/*   Updated: 2020/11/30 21:36:40 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_toupper(char *s)
{
	while (*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
}

int		num_len(long int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n /= 10)
		i++;
	return (i + 1);
}

int		ft_put_spaces(int len, int is_zero)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (is_zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		i++;
	}
	return (len);
}

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putnbr_unsigned_fd(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
}

int		input_loop_aux(char a)
{
	ft_putchar_fd(a, 1);
	return (1);
}
