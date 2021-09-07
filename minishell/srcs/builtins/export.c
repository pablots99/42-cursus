/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 23:26:46 by pablo             #+#    #+#             */
/*   Updated: 2021/09/07 17:08:40 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char **add_declare(char **str)
{
	int i;
	char *aux;
	char **res;

	i = 0;
	res = malloc((ft_bi_strlen(str) +1)*sizeof(char*));
	while (str[i])
	{
		res[i] = ft_strjoin("declare -x ", str[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

char **save_exportables(char **env2)
{
	char *aux;
	int i;
	int j;

	i = 0;
	while (env2[i])
	{
		j = i + 1;
		while (env2[j])
		{
			if (ft_strncmp(env2[i], env2[j],ft_strlen(env2[i])) > 0)
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

void add_exportable_var(t_data *d, char *val)
{	
	char *new;
	int i;
	int cond;

	i = 0;
	cond = 0;
	new = ft_strjoin("declare -x ", val);
	if(!is_exportable(d,val))
		d->exportables = ft_append_string(d->exportables,  new);

	free(new);
}

int is_exportable(t_data *d,char *asignation)
{
	int i;
	char **var_name;
	char *aux;

	var_name = ft_split(asignation,'=');
	i = 0;
	if(var_name)
		aux = ft_strjoin("declare -x ", var_name[0]);
	else 
		aux = ft_strjoin("declare -x ", asignation);
	while (d->exportables[i])
	{
		if(ft_str_equal(d->exportables[i],aux))
		{
			ft_bi_free(var_name);
			free(aux);
			return 1;
		}
		i++;
	}
	free(aux);
	ft_bi_free(var_name);
	return (0);
}