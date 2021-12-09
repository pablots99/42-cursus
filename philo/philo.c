/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:22:51 by pablo             #+#    #+#             */
/*   Updated: 2021/12/09 16:11:36 by ptorres          ###   ########.fr       */
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

	i  = 0;
	threads = malloc((d->n_philo + 1) * sizeof(pthread_t));
	th_data = malloc((d->n_philo + 1) * sizeof(t_thread_data));
	gettimeofday(&d->time_start, NULL);
	while (i < d->n_philo)
	{
		th_data[i].philo = d->philos[i];
		th_data[i].th = &threads[i];
		th_data[i].forks = d->forks;
		th_data[i].n = i;
		th_data[i].d = d;
		th_data[i].mutex_write = &d->mutex_write;
		pthread_create(&threads[i], 0, (void *)loop_of_life,
				(void *)&(th_data[i]));
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], 0);
	printf("everyone is full\n");
}

t_philo	*create_philosophers(t_data *d)
{
	t_philo	*ph;
	int		i;
	t_fork aux;

	i = 0;
	ph = malloc((d->n_philo) * sizeof(t_philo));
	while (i < d->n_philo)
	{
		ph[i].n = i + 1;
		ph[i].n_fork = 0;
		ph[i].n_eat = 0;
		if (i == 0)
			ph[i].l_fork =  &d->forks[d->n_philo - 1];
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

void print_philos(t_philo *ph, int n) 
{
	int i;
	i = 0;
	printf("PHILOSOPHERS\n");
	while (i < n)
	{
		printf("num:%d, r_f:%d, l_f:%d\n", ph[i].n, ph[i].r_fork->n, ph[i].l_fork->n);
		i++;
	}
	printf("--------------------------------\n");
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
	print_philos(d.philos, d.n_philo);
	create_threads(&d);
	return (0);
}
