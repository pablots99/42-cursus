/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:18:57 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/12 00:34:23 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmds	*new_cmd(void)
{
	t_cmds	*new;

	new = malloc(sizeof(t_cmds));
	new->apppend = NULL;
	new->options = NULL;
	new->childs = NULL;
	new->cmd = NULL;
	new->err = 0;
	new->otput_fd = 0;
	new->input_fd = 0;
	new->var_asign = 0;
	new->input_fds = NULL;
	new->input_type = NULL;
	new->exit_cond = 0;
	new->comillas = 0;
	return (new);
}

t_parse	init_parse(void)
{
	t_parse	res;

	res.d_quote = 0;
	res.s_quote = 0;
	res.i = 0;
	res.n_pipe = 0;
	res.space = 0;
	res.do_redir = 0;
	res.so_redir = 0;
	res.si_redir = 0;
	res.di_redir = 0;
	res.var = 0;
	res.var_name = NULL;
	res.var_end = 0;
	return (res);
}

int	no_asignation(t_data *d, char **var)
{
	char	*var_aux;
	char	*var_aux2;

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

void aux_unsetenv(char ***new, int j, t_data *d)
{
	char	**aux;
	
	*new[j] = NULL;
	aux = d->env;
	d->env = *new;
	if (!d->first_env)
		ft_bi_free(aux);
}

char *add_export_aux(char *var)
{
	char	**spl;
	char	*res;
	
	res = NULL;
	spl = ft_split(var, '=');
	if(spl[0] && spl[1])
	{
		res = ft_append_str(ft_strdup("declare -x "), spl[0]);
		res = ft_append_str(res, "=\"");
		res = ft_append_str(res, spl[1]);
		res = ft_append_str(res, "\"");
		ft_bi_free(spl);
		return (res);
	}
	else{
		res = ft_strjoin("declare -x ", var);
	}
	ft_bi_free(spl);
	return (res);
}
