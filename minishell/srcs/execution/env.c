/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 02:34:42 by pablo             #+#    #+#             */
/*   Updated: 2021/07/06 14:19:35 by pablo            ###   ########.fr       */
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
		return (0);
	return (1);
}

void set_env_ms(t_data *d, char *var)
{
	int len;
	char **new_env;
	int i;
	char **aux;
	int exists;

	i = 0;
	exists = 0;
	if (!is_asign(var))
		return;
	len = ft_bi_strlen(d->env);
	new_env = malloc((len + 2) * sizeof(char *));
	while (d->env[i])
	{
		if (_exists(var, d->env[i]) && !exists)
			new_env[i] = ft_strdup(var), exists = 1;
		else
			new_env[i] = ft_strdup(d->env[i]);
		i++;
	}
	if (!exists)
		new_env[i] = ft_strdup(var), i++;
	new_env[i] = NULL;
	aux = d->env;
	d->env = new_env;
	if (d->first_env)
		d->first_env = 0;
	else
		free(aux);
}

void add_session_env(t_data *d, char *cmd)
{
	t_session_v *new;
	t_session_v *aux;
	char **spl;


	printf("cmd:%s\n",cmd);
	printf("-------------\n");
	print_session_env(d->session_env);
	spl = ft_split(cmd, '=');
	new = malloc(sizeof(t_session_v));
	new->name = ft_strdup(spl[0]);
	new->value = ft_strdup(spl[1]);
	new->next = NULL;
	if (!d->session_env)
	{
		d->session_env = new;
	}
	else
	{
		aux = d->session_env;
		while (aux->next)
		{
			aux = aux->next;
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
		if (ft_str_equal(aux->name,name))
			ret = ft_strdup(aux->value);
		aux = aux->next;
	}
	return ret;
}

void	print_session_env(t_session_v *s)
{
	t_session_v	*aux;

	aux = s;
	while (aux)
	{
		printf("%s=%s\n",aux->name,aux->value);
		aux = aux->next;
	}
}
