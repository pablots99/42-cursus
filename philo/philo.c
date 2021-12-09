/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:22:51 by pablo             #+#    #+#             */
/*   Updated: 2021/12/09 13:40:28 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/philo.h"

void	create_threads(t_data *d)
{
	int				i;
	pthread_t		*threads;
	t_thread_data	*th_data;
	pthread_mutex_t	mutex;
	int				err;

	threads = malloc(d->n_philo * sizeof(pthread_t));
	th_data = malloc(d->n_philo * sizeof(t_thread_data));
	err = 0;
	i = 0;
	gettimeofday(&d->time_start, NULL);
	while (i < d->n_philo)
	{
		th_data[i].philo = d->philos[i];
		th_data[i].th = &threads[i];
		th_data[i].forks = d->forks;
		th_data[i].n = i;
		th_data[i].d = d;
		err = pthread_create(&threads[i], 0, (void *)loop_of_life,
				(void *)&(th_data[i]));
		i++;
	}
	while (i-- > 0)
		err = pthread_join(threads[i], 0);
	printf("everyone is full\n");
}

t_philo	*create_philosophers(t_data *d)
{
	t_philo	*ph;
	int		i;
	t_fork	*f;
	t_fork	*l_f;

	f = d->forks;
	l_f = NULL;
	i = 0;
	ph = malloc((d->n_philo) * sizeof(t_philo));
	while (i < d->n_philo)
	{
		ph[i].n = i + 1;
		ph[i].r_fork = f;
		ph[i].n_fork = 0;
		ph[i].n_eat = 0;
		gettimeofday(&ph[i].dying, NULL);
		if (i != 0)
			ph[i].l_fork = l_f;
		if (i == d->n_philo - 1)
			ph[0].l_fork = f;
		l_f = f;
		f = f->next;
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
	d = save_data(argv, argc);
	printf("t_die: %d\n", d.t_die);
	create_forks(&d);
	d.philos = create_philosophers(&d);
	create_threads(&d);
	return (0);
}
