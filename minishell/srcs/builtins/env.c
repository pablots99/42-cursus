/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 02:34:42 by pablo             #+#    #+#             */
/*   Updated: 2021/09/07 17:13:18 by ptorres          ###   ########.fr       */
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





void print_env(char **env,int  fd[2])
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_putstr_fd(env[i],1);
		ft_putchar_fd('\n',1);
		i++;
	}
}


char *get_env_ms(t_data *d,char* name)
{
	char **splited;
	char i;
	char *res;

	res = NULL;
	i = 0;
	while (d->env[i])
	{
		splited = ft_split(d->env[i],'=');
		if(ft_str_equal(splited[0],name))
			res = ft_strdup(splited[1]);
		i++;
		ft_bi_free(splited);
	}
	return (res);
}

void set_env_ms(t_data *d, char *var,int env)
{
	int len;
	char **new_env;
	int i;
	char **aux;
	int exists;
	char *var_aux;
	char *var_aux2;
	int cond;

	i = 0;
	cond = 0;
	exists = 0;

	//export var from set
	if (!is_asign(var))
	{
		var_aux = get_session_env(d,var);
		if(!var_aux)
		{
			add_exportable_var(d,var);
			free(var_aux);
			return ;
		}
		else
		{
			cond = 1;
			var = ft_strjoin(var,"=");
			var_aux2 = var;
			var = ft_strjoin(var_aux2,var_aux);
			free(var_aux2);
			free(var_aux);
		}
	}
	add_exportable_var(d,var);
	len = ft_bi_strlen(d->env);
	new_env = malloc((len + 2) * sizeof(char *));
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
	aux = d->env;
	d->env = new_env;
	if (d->first_env)
		d->first_env = 0;
	else
		ft_bi_free(aux);
	if(!env)
		add_session_env(d,var,1);
	if(cond)
		free(var);
}


