/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:21:52 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/11 19:31:50 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	dup_cmd(t_cmds *cmd, t_data *d)
{
	cmd->cmd = ft_strdup(d->raw_cmd);
	d->cmds = cmd;
	return (1);
}

int	is_sintax_error2(t_data *d, t_cmds *cmd)
{	
	char	token;

	token = is_data_redir(d->raw_cmd);
	if (token != -1)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token \'", 2);
		if (!token)
			ft_putstr_fd("newline", 2);
		else
			ft_putchar_fd(token, 2);
		ft_putstr_fd("\'\n", 2);
		return (dup_cmd(cmd, d));
	}
	return (0);
}

int	is_sintax_error(t_data *d, t_cmds *cmd)
{
	if (!is_pipe_closed(d->raw_cmd))
	{
		ft_putstr_fd(
			"minishell: syntax error near unexpected token `|'\n",
			2);
		return (dup_cmd(cmd, d));
	}
	if (!is_quote_closed(d->raw_cmd))
	{
		ft_putstr_fd(
			"minishell: syntax error quotes not closed\n",
			2);
		return (dup_cmd(cmd, d));
	}
	return (is_sintax_error2(d, cmd));
}
