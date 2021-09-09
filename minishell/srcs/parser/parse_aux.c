/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:25:58 by pablo             #+#    #+#             */
/*   Updated: 2021/09/09 17:10:23 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_data_redir(char *cmd)
{
	int	i;
	int	is_redir;

	i = 0;
	is_redir = 0;
	while (cmd[i])
	{
		if (cmd[i] == '>' || cmd[i] == '<')
			is_redir = 1;
		else if (cmd[i] != ' ' && cmd[i] != '	' && is_redir == 1)
			return (1);
		i++;
	}
	if (!is_redir)
		return (1);
	return (0);
}

int	is_sintax_error(t_data *d, t_cmds *cmd)
{
	if (!is_quote_closed(d->raw_cmd) || !is_data_redir(d->raw_cmd))
	{
		ft_putstr_fd(
			"minishell: syntax error near unexpected token `newline'\n",
			2);
		cmd->cmd = ft_strdup(d->raw_cmd);
		d->cmds = cmd;
		return (1);
	}
	return (0);
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

void	save_data(t_data *d, t_parse *p, t_cmds *cmd, char **str)
{
	if ((p->do_redir || p->so_redir) && d->raw_cmd[p->i] != '>')
	{
		create_output(cmd, *str, p->do_redir, p->so_redir), p->so_redir = 0;
		p->do_redir = 0;
	}
	else if ((p->di_redir) && d->raw_cmd[p->i] != '<')
	{
		cmd->input_fd = save_double_redir(*str, cmd, p->di_redir);
		p->di_redir = 0;
	}
	else if ((p->si_redir) && d->raw_cmd[p->i] != '<')
		read_inputs(cmd, *str), p->si_redir = 0;
	else if (!cmd->cmd)
		save_first_cmd(d, str, &cmd);
	else
	{
		cmd->options = ft_append_string(cmd->options, *str);
		if (*str != NULL && *str[0] != 0)
			free(*str);
	}
}

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
	return (new);
}
