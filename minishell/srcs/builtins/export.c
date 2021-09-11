/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 23:26:46 by pablo             #+#    #+#             */
/*   Updated: 2021/09/12 01:09:21 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**add_declare(char **str)
{
	int		i;
	char	**res;

	i = 0;
	res = malloc((ft_bi_strlen(str) + 1) * sizeof(char *));
	while (str[i])
	{
		res[i] = add_export_aux(str[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**save_exportables(char **env2)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	while (env2[i])
	{
		j = i + 1;
		while (env2[j])
		{
			if (ft_strncmp(env2[i], env2[j], ft_strlen(env2[i])) > 0)
			{
				aux = env2[i];
				env2[i] = env2[j];
				env2[j] = aux;
			}
			j++;
		}
		i++;
	}
	env2 = add_declare(env2);
	return (env2);
}

void	add_exportable_var(t_data *d, char *val)
{
	char	*new;
	int		i;
	int		cond;

	i = 0;
	cond = 0;
	new = add_export_aux(val);
	if (!is_exportable(d, val))
		d->exportables = ft_append_string(d->exportables, new);
	free(new);
}

void	export_exec(t_data *d, char **options,int x)
{
	int	i;
		
	i = 0;
	while (options[i])
	{
		if (!ft_is_stralphanum(options[i]))
		{
			ft_putstr_fd("minishell: export: '", 2);
			ft_putstr_fd(options[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			if (x)
				exit(1);
			d->status = 1;
			return ;
		}
		set_env_ms(d, options[i], 0);
		i++;
	}
}
