/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 22:23:18 by pablo             #+#    #+#             */
/*   Updated: 2021/08/26 00:41:50 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


long int get_time(struct timeval start)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	return (now.tv_sec - start.tv_sec) * 100;
}

long int ft_atoi(const char *str)
{
	int i;
	int cont;
	long int num;

	num = 0;
	i = 0;
	cont = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			cont++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (cont)
		return (num * -1);
	return (num);
}

int is_char_num(char *num)
{

	int i;

	i = 0;
	while (num[i])
	{
		if (num[i] > '9' || num[i] < '0')
		{
			printf("char:%c\n", num[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

void print_state(t_data *d)
{
	int i;
	t_philo *ph;

	ph = d->philos;
	i = 0;
	printf("PHILOSOPHERS\n");
	while (i < d->n_philo)
	{
		printf("num:%d, r_f:%d, l_f:%d\n", ph[i].n, ph[i].r_fork->n, ph[i].l_fork->n);
		i++;
	}
	printf("--------------------------------\n");
}
