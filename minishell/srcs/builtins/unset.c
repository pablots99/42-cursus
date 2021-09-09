/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:06:27 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/09 21:17:31 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void unset_session(t_data *d,char *var_name)
{
	t_session_v *ses;
	t_session_v *aux;
	int i;;

	i = 0;
	aux = NULL;
	ses = d->session_env;
	while (d->session_env && d->session_env->next)
	{
		if(ft_str_equal(d->session_env->next->name,var_name))
		{
			aux = d->session_env->next;
			if(d->session_env->next->next)
				d->session_env->next = d->session_env->next->next;
			else 
				d->session_env->next = NULL;
			free(aux->name);
			free(aux->value);
			free(aux);
		}
		d->session_env = d->session_env->next;
	}
	d->session_env = ses;
	i++;
}

int exists_export(char **exportables,char *name)
{
	int i;
	char *exp;

	i = 0;
	exp = ft_strjoin("declare -x ",name);
	while (exportables[i])
	{
		if(ft_strncmp(exportables[i],exp,ft_strlen(exp)) == 0 && (exportables[i][ft_strlen(exp)] == 0
			|| exportables[i][ft_strlen(exp)] == '=' ))
		{
			free(exp);
			return (i);
		}
		i++;
	}
	free(exp);
	return (-1);
}

void unset_export(t_data *d,char *var_name)
{
	int i;
	int j;
	char **new;
	char **aux;
	int exists;

	exists = exists_export(d->exportables,var_name);
	if(exists < 0)
		return ;
	i = 0;
	j = 0;
	new = malloc(ft_bi_strlen(d->exportables) * sizeof(char *));
	while(d->exportables[i])
	{
		if(i != exists)
		{
			new[j] = ft_strdup(d->exportables[i]);
			j++;
		}
		i++;
	}
	aux =d->exportables;
	d->exportables = new;
	ft_bi_free(aux);
}

void unset_env(t_data *d,char *var_name)
{
	char	*exists;
	char 	**new;
	int		i;
	int		j;
	char	**aux;

	j = 0;
	i = 0; 
	exists = get_env_ms(d,var_name);
	if(!exists)
		return ;
	new = malloc((ft_bi_strlen(d->env) *sizeof(char *)));
	while (d->env[i])
	{
		aux = ft_split(d->env[i],'=');
		if(!ft_str_equal(aux[0],var_name))
		{
			new[j] = ft_strdup(d->env[i]);
			j++;
		}
		ft_bi_free(aux);
		i++;
	}
	new[j] = NULL;
	aux = d->env;
	d->env = new;
	if(!d->first_env)
		ft_bi_free(aux);
	free(exists);
}

void unset(t_data *d, char *var_name)
{
	if(!var_name)
		return ;
	if(is_asign(var_name))
	{
		ft_putstr_fd("minishell: unset: '",2);
		ft_putstr_fd(var_name,2);
		ft_putstr_fd("': not a valid identifier\n",2);
		d->status = 1;
		return ;
	}
	unset_env(d,var_name);
	unset_export(d,var_name);
	unset_session(d,var_name);
	d->status = 0;
}

