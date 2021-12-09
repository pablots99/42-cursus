/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:39:09 by ptorres           #+#    #+#             */
/*   Updated: 2021/12/09 13:41:35 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_left_fork(t_thread_data *d)
{
	pthread_mutex_lock(&d->philo.l_fork->mutex);
	mutex_print(get_time(d->d->time_start), d->philo.n,
		"Has taken left fork", d->d);
}

void	wait_right_fork(t_thread_data *d)
{
	pthread_mutex_lock(&d->philo.r_fork->mutex);
	mutex_print(get_time(d->d->time_start), d->philo.n,
		"Has taken right fork", d->d);
}

void	death_loop(void *data)
{
	t_thread_data	*d;
	int				a;

	d = (t_thread_data *)data;
	while (get_time(d->philo.dying) <= d->d->t_die)
		usleep(10);
	pthread_mutex_lock(&d->d->mutex_dead);
	printf("%ld %d  died\n", get_time(d->d->time_start), d->philo.n);
	exit(1);
}

void	loop_of_life(void *data)
{
	t_thread_data	*d;
	pthread_t		thread;

	d = (t_thread_data *)data;
	gettimeofday(&d->philo.dying, NULL);
	pthread_create(&thread, 0, (void *)death_loop, (void *)(d));
	if (!(d->philo.n % 2))
		ft_sleep(15);
	while (1)
	{
		if (d->philo.n_eat == d->d->n_eats)
			break ;
		wait_right_fork(d), wait_left_fork(d);
		d->philo.n_eat++;
		mutex_print(get_time(d->d->time_start), d->philo.n, "is eating", d->d);
		gettimeofday(&d->philo.dying, NULL), ft_sleep(d->d->t_eat);
		pthread_mutex_unlock(&d->philo.l_fork->mutex);
		pthread_mutex_unlock(&d->philo.r_fork->mutex);
		mutex_print(get_time(d->d->time_start), d->philo.n,
			"is sleeping", d->d);
		ft_sleep(d->d->t_sleep);
		mutex_print(get_time(d->d->time_start), d->philo.n,
			"is thinking", d->d);
	}
	gettimeofday(&d->philo.dying, NULL);
}
