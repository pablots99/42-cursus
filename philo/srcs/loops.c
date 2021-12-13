/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:39:09 by ptorres           #+#    #+#             */
/*   Updated: 2021/12/13 18:59:57 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_left_fork(t_thread_data *d)
{
	pthread_mutex_lock(&d->philo->l_fork->mutex);
	mutex_print(get_time(d->d->time_start), d->philo->n,
		"Has taken a fork", d->d);
}

void	wait_right_fork(t_thread_data *d)
{
	pthread_mutex_lock(&d->philo->r_fork->mutex);
	mutex_print(get_time(d->d->time_start), d->philo->n,
		"Has taken a fork", d->d);
}

void	loop_of_life(void *data)
{
	t_thread_data	*d;

	d = (t_thread_data *)data;
	gettimeofday(&d->philo->dying, NULL);
	while (1 && !d->d->deaths && !d->d->finish_eating)
	{
		if (d->philo->n % 2)
			wait_right_fork(d), wait_left_fork(d);
		else
			wait_left_fork(d), wait_right_fork(d);
		d->philo->n_eat++;
		mutex_print(get_time(d->d->time_start), d->philo->n, "is eating", d->d);
		gettimeofday(&d->philo->dying, NULL), ft_sleep(d->d->t_eat);
		pthread_mutex_unlock(&d->philo->l_fork->mutex);
		pthread_mutex_unlock(&d->philo->r_fork->mutex);
		mutex_print(get_time(d->d->time_start), d->philo->n,
			"is sleeping", d->d);
		ft_sleep(d->d->t_sleep);
		mutex_print(get_time(d->d->time_start), d->philo->n,
			"is thinking", d->d);
	}
}

int	check_death(t_data *data, t_thread_data *th_data, int i, int total_eats)
{
	if (total_eats == data->n_philo)
	{
		pthread_mutex_lock(&data->mutex_write);
		data->finish_eating = 1;
		pthread_mutex_unlock(&data->mutex_write);
		return (1);
	}
	if (get_time(th_data[i].philo->dying) > data->t_die)
	{
		pthread_mutex_lock(&data->mutex_write);
		data->deaths = 1;
		printf("%ld %d  died\n", get_time(data->time_start),
			th_data[i].philo->n);
		pthread_mutex_unlock(&data->mutex_write);
		return (1);
	}
	return (0);
}

void	death_loop(void *d)
{
	t_dh_loop	l;

	l.th_data = (t_thread_data *)d;
	l.data = l.th_data[0].d;
	l.neats = l.data->n_eats;
	l.total_eats = 0;
	l.i = 0;
	while (1)
	{
		l.i = 0;
		while (l.i < l.data->n_philo)
		{	
			if (l.th_data[l.i].philo->n_eat == l.neats)
				l.total_eats++;
			if (check_death(l.data, l.th_data, l.i, l.total_eats))
				break ;
			l.i++;
		}
		if (l.data->deaths || l.data->finish_eating)
			break ;
		usleep(0);
	}
}
