/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:06:27 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/07 17:07:40 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void unset_env(t_data *d,char *var_name)
{
	char **new_env;
	char **s;
	int exists;
	int i;
	char **aux;

	i = 0;
	exists = 0;
	new_env = malloc((ft_bi_strlen(d->env) + 2) * sizeof(char *));
	while (d->env[i])
	{
		s = ft_split(d->env[i], '=');
		if(!ft_str_equal(s[0],var_name))
			new_env[i] = ft_strdup(d->env[i]);
		ft_bi_free(s);
		i++;
	}
	new_env[i] = NULL;
	aux = d->env;
	d->env = new_env;
	if (d->first_env)
		d->first_env = 0;
	else
		ft_bi_free(aux);
}