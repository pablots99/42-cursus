/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   session_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:09:52 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/13 15:48:44 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	add_sesion_aux(t_session_v **s, t_session_v *new)
{
	t_session_v	*list;

	list = *s;
	while (1)
	{
		if (ft_str_equal(list->name, new->name))
		{
			free(list->value);
			list->value = new->value;
			free(new->name);
			free(new);
			if (list->exp)
				return (1);
			return (0);
		}
		if (!list->next)
		{
			list->next = new;
			break ;
		}
		list = list->next;
	}
	return (0);
}

void	init_sesion_env(t_data *d)
{
	t_session_v	*new;

	new = malloc(sizeof(t_session_v));
	new->name = ft_strdup("minishell");
	new->value = ft_strdup("beatifull as hell");
	new->next = NULL;
	d->session_env = new;
}

void	add_session_env(t_data *d, char *cmd, int exp)
{
	t_session_v	*new;
	char		**spl;

	spl = split_asign(cmd);
	new = malloc(sizeof(t_session_v));
	new->name = ft_strdup(spl[0]);
	if (spl[1])
		new->value = ft_strdup(spl[1]);
	else
		new->value = ft_strdup("");
	new->exp = exp;
	new->next = NULL;
	if (!d->session_env)
		init_sesion_env(d);
	exp = add_sesion_aux(&d->session_env, new);
	if (exp)
		set_env_ms(d, cmd, 1);
	else if (is_exportable(d, cmd))
		set_env_ms(d, cmd, 1);
	ft_bi_free(spl);
}

char	*get_session_env(t_data *d, char *name)
{
	int			i;
	char		*ret;
	t_session_v	*aux;

	i = 0;
	ret = NULL;
	aux = d->session_env;
	while (aux)
	{
		if (ft_str_equal(aux->name, name))
			ret = ft_strdup(aux->value);
		aux = aux->next;
	}
	return (ret);
}

void	print_session_env(t_session_v *s)
{
	t_session_v	*aux;

	aux = s;
	while (aux)
	{
		printf("%s=%s\n", aux->name, aux->value);
		aux = aux->next;
	}
	exit(0);
}
