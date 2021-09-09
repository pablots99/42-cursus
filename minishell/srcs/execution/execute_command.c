/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:48:22 by pablo             #+#    #+#             */
/*   Updated: 2021/09/08 20:59:24 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int execute_asignations(t_cmds *cmd, int fd[2], t_data *d)
{
	int is;

	is = 0;
	if (cmd->otput_fd)
		fd[1] = cmd->otput_fd;
	if (!cmd->options || !cmd->options[0])
		return (0);
	if (ft_str_equal(cmd->options[0], "unset"))
		unset_env(d, cmd->options[1]), is = 1;
	else if (cmd->var_asign)
		add_session_env(d, cmd->options[0], 0), is = 1;
	else if (ft_str_equal("export", cmd->options[0]) && cmd->options[1])
		set_env_ms(d, cmd->options[1], 0), is = 1;
	else if (ft_str_equal(cmd->options[0], "exit"))
		free_command(d), exit(0);
	if (cmd->otput_fd && is)
		cmd->otput_fd = 0;
	return (is);
}

int execute_builtins(t_cmds *cmd, int fd[2], t_data *d)
{
	int is;

	is = 0;
	if (cmd->otput_fd)
		fd[1] = cmd->otput_fd;
	if (!cmd->options || !cmd->options[0])
		return (0);
	if (ft_str_equal(cmd->options[0], "cd"))
		execute_cd(cmd, fd), is = 1;
	else if (ft_str_equal(cmd->options[0], "env"))
		print_env(d->env, fd), is = 1;
	else if (ft_str_equal(cmd->options[0], "echo"))
		execute_echo(cmd), is = 1;
	else if (ft_str_equal(cmd->options[0], "pwd"))
		execute_pwd(d, fd[1]), is = 1;
	else if (ft_str_equal(cmd->options[0], "set"))
		print_session_env(d->session_env), is = 1;
	else if (ft_str_equal("export", cmd->options[0]) && !cmd->options[1])
	{
		print_env(d->exportables, fd);
		is = 1;
	}
	if (cmd->otput_fd && is)
		cmd->otput_fd = 0;
	return (is);
}

void handle_sigint2(int sig)
{
	write(1, "\b\b", 2);
}

void init_vars(t_data *d, t_cmds **first)
{
	*first = d->cmds;
	d->fd[1] = 1;
	d->fd[0] = 0;
	d->fd_in = 0;
	d->status = 0;
}

void execute_child(t_data *d, int fd[2])
{
	dup2(d->fd_in, 0);
	if (d->cmds->childs != NULL)
		dup2(d->fd[1], 1);
	if (d->cmds->otput_fd != 0)
		dup2(d->cmds->otput_fd, 1);
	if (execute_builtins(d->cmds, d->fd, d))
		exit(0);
	else if (execve(d->cmds->cmd, d->cmds->options, d->env) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(d->cmds->cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
}

void execute_command(t_data *d, int fd[2])
{
	int pid;

	if (d->cmds->childs != NULL)
		pipe(d->fd);
	pid = fork();
	signal(SIGINT, handle_sigint2);
	signal(SIGQUIT, handle_sigint2);
	if (pid == 0)
		execute_child(d, d->fd);
	else
	{
		if (d->cmds->otput_fd)
			close(d->cmds->otput_fd), d->cmds->otput_fd = 0;
		if (d->fd[1] != 1)
			close(d->fd[1]);
		if (d->fd_in)
			close(d->fd_in);
		d->fd_in = d->fd[0];
	}
}

void execute_commands(t_data *d)
{
	int i;
	t_cmds *first;

	i = 0;
	init_vars(d, &first);
	while (d->cmds)
	{
		if (d->cmds->err)
			break;
		if (d->cmds->input_fd)
			d->fd_in = d->cmds->input_fd;
		if (d->cmds->options && !execute_asignations(d->cmds, d->fd, d))
			execute_command(d,d->fd);
		i++;
		d->cmds = d->cmds->childs;
	}
	i++;
	while (i--)
	{
		wait(&d->status);
		if (d->status != 0)
			d->status /= 256;
	}
	d->cmds = first;
}
