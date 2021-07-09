/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 02:34:42 by pablo             #+#    #+#             */
/*   Updated: 2021/07/07 22:52:11 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_asign(char *var)
{
	char **splited;

	splited = ft_split(var, '=');
	if (ft_bi_strlen(splited) != 2)
	{
		ft_bi_free(splited);
		return (0);
	}
	ft_bi_free(splited);
	return (1);
}

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
		var_aux =get_session_env(d,var);
		if(!var_aux)
		{
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

void add_session_env(t_data *d, char *cmd,int exp)
{
	t_session_v *new;
	t_session_v *aux;
	char **spl;

	spl = ft_split(cmd, '=');
	new = malloc(sizeof(t_session_v));
	new->name = ft_strdup(spl[0]);
	new->value = ft_strdup(spl[1]);
	new->exp = exp;
	new->next = NULL;
	if (!d->session_env)
		d->session_env = new;
	else
	{
		aux = d->session_env;
		while (aux->next)
		{
			if (ft_str_equal(aux->name, new->name))
			{
				if(exp)
					aux->exp = exp;
				free(aux->value);
				aux->value = new->value;
				if(aux->exp)
					set_env_ms(d,cmd,1);
				free(new->name);
				free(new);
				ft_bi_free(spl);
				return;
			}
			aux = aux->next;
		}
		if (ft_str_equal(aux->name, new->name))
		{
			if(exp)
				aux->exp = exp;
			free(aux->value);
			aux->value = new->value;
			if(aux->exp)
				set_env_ms(d,cmd,1);
			free(new->name);
			free(new);
			ft_bi_free(spl);
			return;
		}
		aux->next = new;
	}
	ft_bi_free(spl);
}

char *get_session_env(t_data *d, char *name)
{
	int i;
	char *ret;
	t_session_v *aux;

	i = 0;
	ret = NULL;
	aux = d->session_env;
	while (aux)
	{
		if (ft_str_equal(aux->name, name))
			ret = ft_strdup(aux->value);
		aux = aux->next;
	}
	return ret;
}

void print_session_env(t_session_v *s)
{
	t_session_v *aux;

	aux = s;
	while (aux)
	{
		printf("%s=%s\n", aux->name, aux->value);
		aux = aux->next;
	}
}
