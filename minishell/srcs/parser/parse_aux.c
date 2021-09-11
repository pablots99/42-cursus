/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:25:58 by pablo             #+#    #+#             */
/*   Updated: 2021/09/11 19:35:08 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_data_redir(char *cmd)
{
	int	i;
	int	is_redir;
	int count;

	i = 0;
	is_redir = 0;
	while (cmd[i])
	{
		count = 0;
		if ((cmd[i] == '>' || cmd[i] == '<') && !is_redir)
		{
			is_redir = cmd[i];
			i++;
			while (cmd[i] && cmd[i] == is_redir)
			{
				i++;
				count++;
			}
			if(count > 1)
				return is_redir;
			while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '	'))
				i++;
			count = 0;
			while(cmd[i] && cmd[i] != is_redir && cmd[i] != ' ' && cmd[i] != '	'
					&& cmd[i] != '<' && cmd[i] != '>')
			{
				count++;
				i++;
			}
			if(!count)
				return cmd[i];
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
		create_output(cmd, *str, p->do_redir, p->so_redir), p->so_redir = 0;
		p->do_redir = 0;
	}
	else if ((p->di_redir) && d->raw_cmd[p->i] != '<')
	{
		add_fd_in(*str,cmd,'1',p->di_redir);
		p->di_redir = 0;
	}
	else if ((p->si_redir) && d->raw_cmd[p->i] != '<')
		add_fd_in(*str,cmd,'0',1);
	else if (!cmd->cmd)
		save_first_cmd(d, str, &cmd);
	else
	{
		cmd->options = ft_append_string(cmd->options, *str);
		if (*str != NULL && *str[0] != 0)
			free(*str);
	}
}

