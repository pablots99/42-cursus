/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:23:32 by pablo             #+#    #+#             */
/*   Updated: 2021/11/29 19:47:55 by pablo            ###   ########.fr       */
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
	struct s_fork	*next;
}					t_fork;

typedef struct s_data
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_think;
	int				t_sleep;
	int				n_eats;
	int				init_cond;
	pthread_mutex_t	mutex_dead;
	pthread_mutex_t	mutex_write;
	t_fork			*forks;
	t_philo			*philos;
	struct timeval	time_start;
}			t_data;

typedef struct s_thread_data
{
	t_philo		philo;
	t_fork		*forks;
	int			n;
	pthread_t	*th;
	pthread_t	th_l_fork;
	pthread_t	th_r_fork;
	pthread_t	th_dead;
	t_data		*d;
}			t_thread_data;

long int	ft_atoi(const char *str);
int			is_char_num(char *num);
void		print_state(t_data *d);
long int	get_time(struct timeval start);
void		mutex_print(long int timestamp,
				int n_philo, char *mesage, t_data *d);
void		ft_sleep(int n);

#endif
