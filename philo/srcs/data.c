/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:23:29 by ptorres           #+#    #+#             */
/*   Updated: 2021/12/13 18:48:31 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid_args(int argc, char **argv)
{
	int	i;

	i = 1;
	argc--;
	if (argc < 4 || argc > 5)
		return (0);
	while (argv[i])
	{
		if (!is_char_num(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

t_data	save_data(char **argv)
{
	t_data	d;

	d.n_philo = ft_atoi(argv[1]);
	d.t_die = ft_atoi(argv[2]);
	d.t_eat = ft_atoi(argv[3]);
	d.t_sleep = ft_atoi(argv[4]);
	d.deaths = 0;
	d.finish_eating = 0;
	if (argv[5])
		d.n_eats = ft_atoi(argv[5]);
	else
		d.n_eats = -1;
	pthread_mutex_init(&d.mutex_write, 0);
	pthread_mutex_init(&d.mutex_eat, 0);
	d.forks = NULL;
	return (d);
}

void	create_forks(t_data *d)
{
	int		i;

	i = 0;
	d->forks = malloc(d->n_philo * sizeof(t_fork));
	while (i < d->n_philo)
	{
		pthread_mutex_init(&(d->forks[i].mutex), 0);
		d->forks[i].n = i + 1;
		i++;
	}
}
