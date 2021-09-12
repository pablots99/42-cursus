/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 03:21:03 by pablo             #+#    #+#             */
/*   Updated: 2021/09/12 12:49:44 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	save_double_redir(char *str, t_cmds *cmd)
{
	char	*aux;
	int		fd;

	if (cmd->input_fd)
		close_fd(cmd->input_fd);
	fd = open("/tmp/minishelltmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	aux = readline("> ");
	while (!ft_str_equal(aux, str) || aux[ft_strlen(aux)] == '\04')
	{
		if (aux == 0)
			exit(0);
		write(fd, aux, ft_strlen(aux));
		write(fd, "\n", 1);
		free(aux);
		aux = readline("> ");
	}
	close_fd(fd);
	fd = open("/tmp/minishelltmp", O_RDONLY);
	unlink("/tmp/minishelltmp");
	cmd->input_fd = fd;
	free(aux);
	return (fd);
}

void	double_redir(t_cmds *cmd, int *aux)
{
	int	i;

	i = 0;
	while (cmd->input_type && cmd->input_type[i])
	{
		if (cmd->input_type[i] == '1')
		{
			*aux = i;
			cmd->exit_cond = 1;
			signal(SIGINT, handle_sigint3);
			cmd->input_fd = save_double_redir(cmd->input_fds[i], cmd);
		}
		i++;
	}
}

void	is_empty(t_cmds *d, int i)
{
	if ( !d->cmd || i)
	{
		if (!d->comillas)
			exit(0);
		else
		{
			ft_putstr_fd("minishell: : command not found\n", 2);
			exit(127);
		}
	}
}

void	fd_inputs(t_cmds *cmd)
{
	int	i;
	int	aux;
	int	aux_fd;
	int	err;

	i = 0;
	aux = 0;
	err = 0;
	double_redir(cmd, &aux);
	aux_fd = cmd->input_fd;
	while (cmd->input_type && cmd->input_type[i])
	{
		if (cmd->input_type[i] == '0')
			err = read_inputs(cmd, cmd->input_fds[i]);
		if (cmd->input_type[i] == '2' && !err)
			create_output(cmd, cmd->input_fds[i], 1, 0);
		if (cmd->input_type[i] == '3' && !err)
			create_output(cmd, cmd->input_fds[i], 0, 1);
		if (!(i >= aux) && !err)
			cmd->input_fd = aux_fd;
		i++;
	}
	if(err)
		exit(1);
	is_empty(cmd,i);
}
