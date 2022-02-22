/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:25:58 by pablo             #+#    #+#             */
/*   Updated: 2021/09/12 20:52:39 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	is_data_redir_aux(char *cmd, int *i, int *count, int is_redir)
{
	while (cmd[*i] && (cmd[*i] == ' ' || cmd[*i] == '	'))
		*i = *i + 1;
	*count = 0;
	while (cmd[*i] && cmd[*i] != is_redir && cmd[*i] != ' '
		&& cmd[*i] != '	' && cmd[*i] != '<' && cmd[*i] != '>')
	{
		*count = *count + 1;
		*i = *i + 1;
	}
}

void	id_data_redir_aux2(char *cmd, int *i, int *count, int *is_redir)
{
	*is_redir = cmd[*i];
	*i = *i + 1;
	while (cmd[*i] && cmd[*i] == *is_redir)
	{
		*i = *i + 1;
		*count = *count + 1;
	}
}

int	is_data_redir(char *cmd)
{
	int	i;
	int	is_redir;
	int	count;

	i = 0;
	is_redir = 0;
	while (cmd[i])
	{
		count = 0;
		if ((cmd[i] == '>' || cmd[i] == '<') && !is_redir)
		{
			id_data_redir_aux2(cmd, &i, &count, &is_redir);
			if (count > 1)
				return (is_redir);
			is_data_redir_aux(cmd, &i, &count, is_redir);
			if (!count)
				return (cmd[i]);
			else
				is_redir = 0;
		}
		i++;
	}
	return (-1);
}

void	save_data(t_data *d, t_parse *p, t_cmds *cmd, char **str)
{
	if ((p->do_redir || p->so_redir) && d->raw_cmd[p->i] != '>')
	{
		add_outpput(cmd, *str, p->do_redir, p->so_redir), p->so_redir = 0;
		p->do_redir = 0;
	}
	else if ((p->di_redir) && d->raw_cmd[p->i] != '<')
	{
		add_fd_in(*str, cmd, '1', p->di_redir);
		p->di_redir = 0;
	}
	else if ((p->si_redir) && d->raw_cmd[p->i] != '<')
		add_fd_in(*str, cmd, '0', 1), p->si_redir = 0;
	else if (!cmd->cmd)
		save_first_cmd(d, str, &cmd);
	else
	{
		cmd->options = ft_append_string(cmd->options, *str);
		if (*str != NULL && *str[0] != 0)
			free(*str);
	}
}

int	find_redir_out(char *str, t_parse *p, t_cmds *cmd)
{
	int	cond;

	cond = 0;
	if (str[p->i] == '>' && !p->d_quote && !p->s_quote)
	{
		if (str[p->i + 1] != '>' && str[p->i - 1] != '>')
		{
			p->so_redir = 1;
			p->space = 1;
			cmd->apppend = ft_append_char(cmd->apppend, '0');
		}
		else
		{
			p->do_redir++;
			p->space = 1;
			p->so_redir = 0;
			cmd->apppend = ft_append_char(cmd->apppend, '1');
		}
		cond = 1;
	}
	return (cond);
}
