/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:48:22 by pablo             #+#    #+#             */
/*   Updated: 2021/07/07 21:40:37 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int execute(t_cmds *cmd, int fd[2], t_data *d)
{
	int err;
	int is;

	is = 0;
	err = 0;
	if (!ft_strncmp(cmd->options[0], "cd", 2) && ft_strlen(cmd->options[0]) == 2)
	{

		if (cmd->options[1])
			err = chdir(cmd->options[1]);
		if (err)
			printf("%s\n", strerror(errno));
		close(fd[1]);
		is = 1;
	}
	else if (ft_str_equal(cmd->options[0], "set"))
		print_session_env(d->session_env),is = 1;
	else if (cmd->var_asign)
		add_session_env(d, cmd->options[0], 0),is=1;
	else if (!ft_strncmp(cmd->options[0], "export", 6) && ft_strlen(cmd->options[0]) == 6)
		set_env_ms(d, cmd->options[1],0),is=1;
	return (is);
}

void execute_commands(t_data *d)
{
	int pid;
	int fd[2];
	int fd_in;
	int i;
	int cond;
	t_cmds *aux;
	t_cmds *first;

	fd_in = 0;
	first = d->cmds;
	while (d->cmds)
	{
		i = 0;
		aux = d->cmds;
		if (aux->childs)
			cond = 1;
		else
			cond = 0;
		while (aux != NULL && cond)
		{
			if (aux->childs)
				pipe(fd);
			pid = fork();
			if (pid == 0)
			{
				dup2(fd_in, 0);
				if (aux->childs != NULL)
					dup2(fd[1], 1);
				close(fd[0]);
				if (execve(aux->cmd, aux->options, d->env) == -1)
				{
					printf("Error Executing %s\n", aux->options[0]);
					exit(1);
				}
			}
			else
			{
				wait(NULL);
				close(fd[1]);
				fd_in = fd[0];
			}
			aux = aux->childs;
			i++;
		}
		if (i == 0 && d->cmds->childs == NULL)
		{
			if(!execute(d->cmds,fd,d))
			{
				pid = fork();
				if (pid == 0)
				{
					if (execve(d->cmds->cmd, d->cmds->options, d->env) == -1)
					{
						printf("Error Executing %s\n", d->cmds->options[0]);
						exit(1);
					}
				}
				else
					wait(NULL);
				}
		}
		d->cmds = d->cmds->next;
	}
	d->cmds = first;
}
