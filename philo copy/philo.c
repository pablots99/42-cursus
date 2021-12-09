/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:22:51 by pablo             #+#    #+#             */
/*   Updated: 2021/12/08 23:53:20 by pablo            ###   ########.fr       */
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
	while (argv[i])
	{
		if (!is_char_num(argv[i]))
			return (0);
		i++;
	}
	// if(ft_atoi(argv[1]) < 2)
	// 	return (0);
	//check if times are grater than 0??????
	return (1);
}

t_data save_data(char **argv, int argc)
{
	t_data d;

	d.n_philo = ft_atoi(argv[1]);
	d.t_die = ft_atoi(argv[2]);
	d.t_eat = ft_atoi(argv[3]);
	d.t_sleep = ft_atoi(argv[4]);
	if(argv[5])
		d.n_eats = ft_atoi(argv[5]);
	else
		d.n_eats = -1;
	pthread_mutex_init(&d.mutex_dead,0);
	d.forks = NULL;
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



void death_loop(void *data)
{
	t_thread_data *d;
	int a;

	d = (t_thread_data *)data;
	//while true si la ultima vez que comio
	while (get_time(d->philo.dying) <= d->d->t_die)
		usleep(10);
	pthread_mutex_lock(&d->d->mutex_dead);
	printf("%ld %d  died\n",get_time(d->d->time_start), d->philo.n);
	exit(1);
}
void wait_left_fork(t_thread_data *d)
{
	pthread_mutex_lock(&d->philo.l_fork->mutex);
	mutex_print(get_time(d->d->time_start), d->philo.n,"Has taken left fork",d->d);

}

void wait_right_fork(t_thread_data *d)
{
	pthread_mutex_lock(&d->philo.r_fork->mutex);
	mutex_print(get_time(d->d->time_start), d->philo.n,"Has taken right fork",d->d);
}

void loop_of_life(void *data)
{
	t_thread_data *d;
	pthread_t thread;

	d = (t_thread_data *)data;
	gettimeofday(&d->philo.dying,NULL);
	pthread_create(&thread, 0, (void *)death_loop, (void *)(d));
	if(!(d->philo.n % 2))
		ft_sleep(15);
	while (1)
	{
		if(d->philo.n_eat == d->d->n_eats)
			break ;
		wait_left_fork(d);
		wait_right_fork(d);
		//eat
		d->philo.n_eat++;
		mutex_print(get_time(d->d->time_start), d->philo.n,"is eating",d->d);
		gettimeofday(&d->philo.dying,NULL);
		ft_sleep(d->d->t_eat);
		pthread_mutex_unlock(&d->philo.l_fork->mutex);
		pthread_mutex_unlock(&d->philo.r_fork->mutex);
		//sleep
		mutex_print(get_time(d->d->time_start), d->philo.n,"is sleeping",d->d);
		ft_sleep(d->d->t_sleep);
		//think
		mutex_print(get_time(d->d->time_start), d->philo.n,"is thinking",d->d);
	}
	gettimeofday(&d->philo.dying,NULL);
}

void create_threads(t_data *d)
{
	int i;
	pthread_t threads[d->n_philo];
	t_thread_data th_data[d->n_philo];
	pthread_mutex_t mutex;
	int err;
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
	printf("everyone is full\n");
}

t_philo *create_philosophers(t_data *d)
{
	t_philo *ph;
	int i;
	t_fork *f = d->forks;
	t_fork *l_f = NULL;

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
	create_threads(&d);
	return (0);
}
