/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:48:22 by pablo             #+#    #+#             */
/*   Updated: 2021/07/15 14:10:49 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int execute_builtins(t_cmds *cmd, int fd[2], t_data *d)
{
	int is;

	is = 0;
	if(cmd->otput_fd)
		fd[1]  = cmd->otput_fd;
	if (!cmd->options || !cmd->options[0])
		return (0);
	if (ft_str_equal(cmd->options[0], "cd"))
		execute_cd(cmd, fd), is = 1;
	else if (ft_str_equal(cmd->options[0], "env"))
		print_env(d, fd), is = 1;
	else if (ft_str_equal(cmd->options[0], "echo"))
		execute_echo(cmd, fd), is = 1;
	else if (ft_str_equal(cmd->options[0], "unset"))
		unset_env(d, cmd->options[1]), is = 1;
	else if (ft_str_equal(cmd->options[0], "exit"))
		free_command(d), exit(0);
	else if (ft_str_equal(cmd->options[0], "pwd"))
		execute_pwd(d, fd[1]), is = 1;
	else if (ft_str_equal(cmd->options[0], "set"))
		print_session_env(d->session_env), is = 1;
	else if (cmd->var_asign)
		add_session_env(d, cmd->options[0], 0), is = 1;
	else if (!ft_strncmp(cmd->options[0], "export", 6) && ft_strlen(cmd->options[0]) == 6)
		set_env_ms(d, cmd->options[1], 0), is = 1;
	if (is)
		d->status = 0;
	if(cmd->otput_fd && is)
		cmd->otput_fd = 0;
	return (is);
}

void execute_commands(t_data *d)
{
	int pid;
	int fd[2];
	int fd_in;
	int i;
	t_cmds *first;

	i = 0;
	first = d->cmds;
	i = 0;
	fd_in = 0;
	fd[1]  = 1;
	fd[0] = 0;
	while (d->cmds)
	{

		create_outputs(d->cmds);
		if (!execute_builtins(d->cmds, fd, d) && d->cmds->options)
		{
			if (d->cmds->childs != NULL)
				pipe(fd);
			pid = fork();
			if (pid == 0)
			{
				dup2(fd_in, 0);
				close(fd[0]);
				if (d->cmds->childs != NULL) //si tiene hijos hace el dup2 del output
					dup2(fd[1], 1);
				if (d->cmds->otput_fd != 0) //si no  tiene hijos pero hay redireccion hace el dup2 del output
				{
					dup2(d->cmds->otput_fd, 1);
				}
				if (execve(d->cmds->cmd, d->cmds->options, d->env) == -1)
				{
					if (d->cmds->options && d->cmds->options[0])
						printf("minishell: %s: command not found\n", d->cmds->cmd);
					else
						printf("minishell: : command not found\n");
					exit(1);
				}
			}
			else
			{
				if(d->cmds->otput_fd)
					close(d->cmds->otput_fd), d->cmds->otput_fd = 0;
				if(fd[1] != 1)
					close(fd[1]);
				fd_in = fd[0];
				wait(&d->status);
			}
		}
		i++;
		d->cmds = d->cmds->childs;
	}
	d->cmds = first;
}
