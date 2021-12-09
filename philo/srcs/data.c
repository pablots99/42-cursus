/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:23:29 by ptorres           #+#    #+#             */
/*   Updated: 2021/12/09 13:42:13 by ptorres          ###   ########.fr       */
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

t_data	save_data(char **argv, int argc)
{
	t_data	d;

	d.n_philo = ft_atoi(argv[1]);
	d.t_die = ft_atoi(argv[2]);
	d.t_eat = ft_atoi(argv[3]);
	d.t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		d.n_eats = ft_atoi(argv[5]);
	else
		d.n_eats = -1;
	pthread_mutex_init(&d.mutex_dead, 0);
	d.forks = NULL;
	return (d);
}

void	add_fork(t_fork **lst, t_fork *new)
{
	t_fork	*curr;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		curr = *lst;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
	else
		*lst = new;
}

void	create_forks(t_data *d)
{
	int		i;
	t_fork	*fork;

	i = 0;
	while (i < d->n_philo)
	{
		fork = malloc(sizeof(t_fork));
		pthread_mutex_init(&fork->mutex, 0);
		fork->n = i + 1;
		fork->next = NULL;
		add_fork(&d->forks, fork);
		fork = NULL;
		i++;
	}
}
