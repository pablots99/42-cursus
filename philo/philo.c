/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:22:51 by pablo             #+#    #+#             */
/*   Updated: 2021/09/06 13:51:47 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/philo.h"

int is_valid_args(int argc, char **argv)
{
	int i;

	i = 1;
	argc--;
	if (argc < 4 || argc > 5)
		return (0);
	while (i <= argc)
	{
		if (!is_char_num(argv[i]))
			return (0);
		argc--;
	}
	//check if is one or more philosophers
	//check if times are grater than 0?
	return (1);
}

t_data save_data(char **argv, int argc)
{
	t_data d;

	d.n_philo = ft_atoi(argv[1]);
	d.t_die = ft_atoi(argv[2]);
	d.t_eat = ft_atoi(argv[3]);
	d.t_sleep = ft_atoi(argv[4]);
	d.forks = NULL;
	if (argc == 6)
		d.n_eats = ft_atoi(argv[5]);
	else
		d.n_eats = 0;
	return d;
}

void add_fork(t_fork **lst, t_fork *new)
{

	t_fork *curr;

	if (!lst || !new)
		return;
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

void create_forks(t_data *d)
{
	int i;
	t_fork *fork;

	i = 0;
	if (d->n_philo == 1)
		i--;
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

void ft_sleep(int n)
{
	int i;

	i = 0;
	while (i < n)
		i++;
}

void dead_loop(void *data)
{
	t_thread_data *d;

	d = (t_thread_data *)data;
	while (d->philo.dying--)
	{
		usleep(1000);
	}
	printf("%ld %d  died\n",get_time(d->d.time_start), d->philo.n);
	exit(1);
}


void wait_left_fork(void *data)
{
	t_thread_data *d;
	d = (t_thread_data *)data;
	pthread_mutex_lock(&d->philo.l_fork->mutex);
	d->philo.n_fork++;
	printf("%ld %d  Has taken left fork\n",get_time(d->d.time_start), d->philo.n);

}

void wait_right_fork(void *data)
{
	t_thread_data *d;
	d = (t_thread_data *)data;
	pthread_mutex_lock(&d->philo.r_fork->mutex);
	d->philo.n_fork++;
	printf("%ld %d  Has taken right fork\n",get_time(d->d.time_start), d->philo.n);
}

void loop_of_life(void *data)
{
	t_thread_data *d;
	pthread_t thread;

	d = (t_thread_data *)data;
	pthread_create(&thread, 0, (void *)dead_loop, (void *)(d));
	while (1)
	{
		pthread_create(&d->th_l_fork, 0, (void *)wait_left_fork, (void *)(d));
		pthread_create(&d->th_r_fork, 0, (void *)wait_right_fork, (void *)(d));
		pthread_join(d->th_l_fork, 0);
		pthread_join(d->th_r_fork, 0);
		if (d->philo.n_fork == 2)
		{
			d->philo.dying = d->d.t_die;
			printf("%ld %d  is eating\n",get_time(d->d.time_start), d->philo.n);
			usleep(d->d.t_eat * 1000);
			printf("%ld %d  is sleeping\n",get_time(d->d.time_start), d->philo.n);
			usleep(d->d.t_sleep * 1000);
			printf("%ld %d  is thinking\n",get_time(d->d.time_start), d->philo.n);
			d->philo.n_fork = 0;
			pthread_mutex_unlock(&d->philo.l_fork->mutex);
			pthread_mutex_unlock(&d->philo.r_fork->mutex);
		}
		// printf("philo:%d, r_F:%d, l_f:%d\n",d->philo.n,d->philo.r_fork->state, d->philo.l_fork->state);
		// usleep(3000000);
	}
}

void create_threads(t_data *d)
{
	int i;
	pthread_t threads[d->n_philo];
	t_thread_data th_data[d->n_philo];
	pthread_mutex_t mutex;
	int err;


	gettimeofday(&d->time_start, NULL);
	err = 0;
	i = 0;
	while (i < d->n_philo)
	{
		th_data[i].philo = d->philos[i];
		th_data[i].th = &threads[i];
		th_data[i].forks = d->forks;
		th_data[i].n = i;
		th_data[i].d = *d;
		err = pthread_create(&threads[i], 0, (void *)loop_of_life, (void *)&(th_data[i]));
		if (err)
		{
			printf("Error: Can not create thread");
			break;
		}
		i++;
	}
	while (i-- > 0)
		err = pthread_join(threads[i], 0);
}

t_philo *create_philosophers(t_data *d)
{
	//gestionar cuando solo es un filosofo
	t_philo *ph;
	int i;
	t_fork *f = d->forks;
	t_fork *l_f = NULL;
	i = 0;
	ph = malloc((d->n_philo + 2) * sizeof(t_philo));
	while (i < d->n_philo)
	{
		ph[i].n = i + 1;
		ph[i].r_fork = f;
		ph[i].n_fork = 0;
		ph[i].dying = d->t_die;
		if (i != 0)
			ph[i].l_fork = l_f;
		if (i == d->n_philo - 1)
			ph[0].l_fork = f;
		l_f = f;
		f = f->next;
		i++;
	}
	return ph;
}

int main(int argc, char **argv)
{
	t_data d;

	if (!is_valid_args(argc, argv))
	{
		printf("Arguments Error\n");
		return (1);
	}
	d = save_data(argv, argc);
	printf("t_die: %d\n", d.t_die);
	create_forks(&d);
	d.philos = create_philosophers(&d);
	print_state(&d);
	create_threads(&d);
	return (0);
}
