/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:23:32 by pablo             #+#    #+#             */
/*   Updated: 2021/12/13 18:33:29 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <time.h>

typedef struct s_philo
{
	int				n;
	struct s_fork	*l_fork;
	struct s_fork	*r_fork;
	int				n_fork;
	int				n_eat;
	struct timeval	dying;
}					t_philo;

typedef struct s_fork
{
	int				n;
	pthread_mutex_t	mutex;
}					t_fork;

typedef struct s_data
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				deaths;
	int				t_think;
	int				t_sleep;
	int				n_eats;
	int				finish_eating;
	pthread_mutex_t	mutex_write;
	pthread_mutex_t	mutex_eat;
	t_fork			*forks;
	t_philo			*philos;
	struct timeval	time_start;
}			t_data;

typedef struct s_thread_data
{
	t_philo			*philo;
	t_fork			*forks;
	int				n;
	pthread_t		*th;
	pthread_t		th_dead;
	t_data			*d;
	pthread_mutex_t	*mutex_write;
}			t_thread_data;

typedef struct s_dh_loop
{
	t_thread_data	*th_data;
	t_data			*data;
	int				i;
	int				neats;
	int				total_eats;
}				t_dh_loop;

long int	ft_atoi(const char *str);
int			is_char_num(char *num);
void		print_state(t_data *d);
long int	get_time(struct timeval start);
void		mutex_print(long int timestamp,
				int n_philo, char *mesage, t_data *d);
void		ft_sleep(int n);
int			is_valid_args(int argc, char **argv);
void		create_forks(t_data *d);
void		add_fork(t_fork **lst, t_fork *new);
void		create_forks(t_data *d);
t_data		save_data(char **argv);
void		loop_of_life(void *data);
void		death_loop(void *d);

#endif
