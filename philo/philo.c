/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:22:51 by pablo             #+#    #+#             */
/*   Updated: 2021/12/13 18:31:00 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/philo.h"

void	wait_threads(pthread_t *th, t_thread_data *th_d, int i)
{
	while (i > 0)
	{
		pthread_join(th[i], 0);
		i--;
	}
	pthread_detach(th[i]);
	free(th);
	free(th_d);
}

void	create_threads(t_data *d)
{
	int				i;
	pthread_t		*threads;
	t_thread_data	*th_data;

	i = 0;
	threads = malloc((d->n_philo + 2) * sizeof(pthread_t));
	th_data = malloc((d->n_philo) * sizeof(t_thread_data));
	gettimeofday(&d->time_start, NULL);
	while (i < d->n_philo)
	{
		th_data[i].philo = &d->philos[i];
		th_data[i].th = &threads[i];
		th_data[i].forks = d->forks;
		th_data[i].n = i;
		th_data[i].d = d;
		th_data[i].mutex_write = &d->mutex_write;
		pthread_create(&threads[i], 0, (void *)loop_of_life,
			(void *)&(th_data[i]));
		i++;
	}
	pthread_create(&threads[i], 0, (void *)death_loop, (void *)(th_data));
	wait_threads(threads, th_data, i);
}

t_philo	*create_philosophers(t_data *d)
{
	t_philo	*ph;
	int		i;

	i = 0;
	ph = malloc((d->n_philo) * sizeof(t_philo));
	while (i < d->n_philo)
	{
		ph[i].n = i + 1;
		ph[i].n_fork = 0;
		ph[i].n_eat = 0;
		if (i == 0)
			ph[i].l_fork = &d->forks[d->n_philo - 1];
		else
			ph[i].l_fork = &d->forks[i - 1];
		if (i == d->n_philo)
			ph[i].r_fork = &d->forks[0];
		else
			ph[i].r_fork = &d->forks[i];
		gettimeofday(&ph[i].dying, NULL);
		i++;
	}
	return (ph);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (!is_valid_args(argc, argv))
	{
		printf("Arguments Error\n");
		return (1);
	}
	d = save_data(argv);
	create_forks(&d);
	d.philos = create_philosophers(&d);
	create_threads(&d);
	return (0);
}
