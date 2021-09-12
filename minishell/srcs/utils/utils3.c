/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:51:18 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/12 12:47:07 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_outpput(t_cmds *cmd, char *str, int s, int d)
{
	if (s)
		add_fd_in(str, cmd, '2', 1);
	if (d)
		add_fd_in(str, cmd, '3', 1);
}

void	add_fd_in(char *str, t_cmds *cmd, char d, int c)
{
	if (!(c < 3))
	{
		free(str);
		return ;
	}
	cmd->input_fds = ft_append_string(cmd->input_fds, str);
	cmd->input_type = ft_append_char(cmd->input_type, d);
	free(str);
}

int	read_inputs(t_cmds *cmd, char *str)
{
	int	fd;

	fd = 0;
	if (cmd->input_fd != 0)
		close_fd(cmd->input_fd);
	fd = open(str, O_RDWR);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(str);
		cmd->err = 1;
		return (1);
	}
	else
		cmd->input_fd = fd;
	if (str && str[0] != 0)
		free(str);
	return (0);
}

int	is_quote_closed(char *input)
{
	int		i;
	int		cond;
	char	quote;

	cond = 0;
	i = 0;
	quote = 0;
	while (input[i])
	{
		if ((input[i] == '"' || input[i] == '\'') && cond == 0)
		{
			quote = input[i];
			cond = 1;
		}
		else if (cond == 1 && input[i] == quote)
			cond = 0;
		i++;
	}
	if (cond)
		return (0);
	return (1);
}

int	is_pipe_closed(char *input)
{
	int	i;
	int	open;
	int	data;

	data = 0;
	i = 0;
	open = 0;
	while (input[i])
	{
		if (input[i] == '|')
		{
			open = 1;
			if (!data)
				return (0);
			data = 0;
		}
		else if (input[i] != ' ' && input[i] != '	')
			data = 1;
		i++;
	}
	if (open && !data)
		return (0);
	return (1);
}
