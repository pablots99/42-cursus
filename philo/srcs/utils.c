/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 22:23:18 by pablo             #+#    #+#             */
/*   Updated: 2021/12/13 18:59:51 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(struct timeval start)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (((now.tv_sec * 1000) + (now.tv_usec / 1000))
		- ((start.tv_sec * 1000) + (start.tv_usec / 1000)));
}

long int	ft_atoi(const char *str)
{
	int			i;
	int			cont;
	long int	num;

	num = 0;
	i = 0;
	cont = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			cont++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (cont)
		return (num * -1);
	return (num);
}

int	is_char_num(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (num[i] > '9' || num[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

void	ft_sleep(int n)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	while (get_time(now) < n)
		usleep(0);
}

void	mutex_print(long int timestamp, int n_philo, char *mesage, t_data *d)
{
	pthread_mutex_lock(&d->mutex_write);
	if (!d->deaths && !d->finish_eating)
		printf("%ld %d %s\n", timestamp, n_philo, mesage);
	pthread_mutex_unlock(&d->mutex_write);
}
