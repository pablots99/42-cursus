/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:23:32 by pablo             #+#    #+#             */
/*   Updated: 2021/08/26 00:42:30 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <time.h>

typedef struct s_philo
{
	int n;
	struct s_fork	*l_fork;
	struct s_fork	*r_fork;
	int				n_fork;
	int 			n_eatten;
	int				dying;
}					t_philo;

typedef struct s_fork
{
	int				n;
	pthread_mutex_t mutex;
	struct s_fork	*next;
}					t_fork;

typedef struct s_data
{
	int		n_philo;
	int		t_die;
	int		t_eat;
	int		t_think;
	int		t_sleep;
	int		n_eats;
	t_fork	*forks;
	t_philo	*philos;
	struct timeval	time_start;
}			t_data;

typedef struct s_thread_data
{
	t_philo	philo;
	t_fork	*forks;
	int		n;
	pthread_t *th;
	pthread_t th_l_fork;
	pthread_t th_r_fork;
	pthread_t th_dead;
	t_data d;
}			t_thread_data;

// struct timeval
// {
// 	time_t tv_sec;		 /* seconds since Jan. 1, 1970 */
// 	suseconds_t tv_usec; /* and microseconds */
// };

// struct timezone
// {
// 	int tz_minuteswest; /* of Greenwich */
// 	int tz_dsttime;		/* type of dst correction to apply */
// };

long int ft_atoi(const char *str);
int is_char_num(char *num);
void print_state(t_data *d);
long int get_time(struct timeval start);
