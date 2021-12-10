/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:22:51 by pablo             #+#    #+#             */
/*   Updated: 2021/12/10 15:18:36 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/philo.h"

void	death_loop(void *d)
{
	t_thread_data	*th_data;
	t_data			*data;
	int				i;
	int				neats;
	int				total_eats;

	total_eats = 0;
	th_data = (t_thread_data *)d;
	data = th_data[0].d;
	neats = data->n_eats;
	while (1)
	{
		i = 0;
		while (i < data->n_philo - 1)
		{	
			if (total_eats == data->n_philo)
				return ;
			if ((get_time(th_data[i].philo->dying) > data->t_die) && th_data[i].philo->n_eat != neats)
			{
				total_eats++;
				pthread_mutex_lock(&data->mutex_write);
				printf("time: %ld eats: %d n_eats: %d\n",get_time(th_data[i].philo->dying),th_data[i].philo->n_eat,data->n_eats);
				printf("%ld %d  died\n", get_time(data->time_start),
					th_data[i].philo->n);
				exit(1);
			}
			i++;
		}
	}
}

void	create_threads(t_data *d)
{
	int				i;
	pthread_t		*threads;
	t_thread_data	*th_data;
	pthread_mutex_t	mutex;
	int				err;

	i = 0;
	threads = malloc((d->n_philo + 3) * sizeof(pthread_t));
	th_data = malloc((d->n_philo + 1) * sizeof(t_thread_data));
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
	pthread_detach(threads[i]);
	while (i-- > 0)
		pthread_join(threads[i], 0);
}

t_philo	*create_philosophers(t_data *d)
{
	t_philo	*ph;
	int		i;
	t_fork	aux;

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
	d = save_data(argv, argc);
	create_forks(&d);
	d.philos = create_philosophers(&d);
	create_threads(&d);
	printf("mmmmm!!\n");
	return (0);
}
