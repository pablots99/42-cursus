/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:05:59 by ptorres           #+#    #+#             */
/*   Updated: 2021/01/02 21:21:01 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int len_coma_spaces(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13))
			len++;
		if (str[i] == ',')
		{
			i++;
			while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			{
				len++;
				i++;
			}
			continue;
		}
		i++;
	}
	return (len);
}

char *ft_clean_spaces(char *str)
{
	int i;
	char *res;
	int aux;

	aux = 0;
	i = 0;
	if (!(res = malloc(sizeof(char) * (ft_strlen(str) - len_coma_spaces(str) + 1))))
		return (NULL);
	while (str[i])
	{
		if (!(str[i] >= 9 && str[i] <= 13))
		{
			res[aux] = str[i];
			aux++;
		}
		if (str[i] == ',')
		{
			i++;
			while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
				i++;
			continue;
		}
		i++;
	}
	free(str);
	res[i] = 0;
	return res;
}
int exit_win(int keycode, t_file *c)
{
	if (keycode == 53)
	{
		mlx_destroy_window(c->mlx_ptr, c->win_ptr);
		free_config(c);
		ft_printf("\n\n\n\n------------------LEAKS---------------------------------------\n");
		system("leaks minirt");
		ft_printf("--------------------------------------------------------\n");
		exit(0);
	}
	return (0);
}
int exit_win2(t_file *c)
{
	mlx_destroy_window(c->mlx_ptr, c->win_ptr);
	free_config(c);
	ft_printf("\n\n\n\n------------------LEAKS---------------------------------------\n");
	system("leaks minirt");
	ft_printf("--------------------------------------------------------\n");
	exit(0);
	return (0);
}
