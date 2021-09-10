/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 02:34:42 by pablo             #+#    #+#             */
/*   Updated: 2021/09/10 16:49:56 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int _exists(char *var, char *env)
{
	char **splited;
	char **splited2;

	splited = ft_split(env, '=');
	splited2 = ft_split(var, '=');
	if (!ft_str_equal(splited[0], splited2[0]))
	{
		ft_bi_free(splited);
		ft_bi_free(splited2);
		return (0);
	}
	ft_bi_free(splited);
	ft_bi_free(splited2);
	return (1);
}

void print_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_putstr_fd(env[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	exit(0);
}

char *get_env_ms(t_data *d, char *name)
{
	char **splited;
	int i;
	char *res;

	res = NULL;
	i = 0;
	while (d->env[i])
	{
		splited = ft_split(d->env[i], '=');
		if (ft_str_equal(splited[0], name))
			res = ft_strdup(splited[1]);
		i++;
		ft_bi_free(splited);
	}
	return (res);
}

int no_asignation(t_data *d, char **var)
{
	char *var_aux;
	char *var_aux2;

	if (!is_asign(*var))
	{
		var_aux = get_session_env(d, *var);
		if (!var_aux)
		{
			add_exportable_var(d, *var);
			free(var_aux);
			return (2);
		}
		else
		{
			*var = ft_strjoin(*var, "=");
			var_aux2 = *var;
			*var = ft_strjoin(var_aux2, var_aux);
			free(var_aux2);
			free(var_aux);
			return (1);
		}
	}
	return (0);
}

char **new_env(t_data *d, char *var)
{
	int i;
	int exists;
	char **new_env;

	new_env = malloc((ft_bi_strlen(d->env) + 2) * sizeof(char *));
	exists = 0;
	i = 0;
	while (d->env[i])
	{
		if (!exists && _exists(var, d->env[i]))
		{
			new_env[i] = ft_strdup(var);
			exists = 1;
		}
		else
			new_env[i] = ft_strdup(d->env[i]);
		i++;
	}
	if (!exists)
		new_env[i] = ft_strdup(var);
	else
		new_env[i] = NULL;
	i++;
	new_env[i] = NULL;
	return (new_env);
}

void set_env_ms(t_data *d, char *var, int env)
{
	char **aux;
	int cond;

	cond = no_asignation(d, &var);
	if (cond == 2)
		return;
	add_exportable_var(d, var);
	aux = d->env;
	d->env = new_env(d, var);
	if (d->first_env)
		d->first_env = 0;
	else
		ft_bi_free(aux);
	if (!env)
		add_session_env(d, var, 1);
	if (cond == 1)
		free(var);
}
