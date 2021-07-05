/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:48:22 by pablo             #+#    #+#             */
/*   Updated: 2021/07/06 01:48:18 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int dups(int i, t_cmds cmd, int fd[100][2])
{
	if (i == 0)
	{
		printf("entra1, fd1: %d, fd2: %d,i:%d\n", fd[i][0], fd[i][1], i);
		close(fd[i][0]);
		// if (pipex.infile)
		// {
		// 	dup2(pipex.infile, 0);
		// 	close(pipex.infile);
		// }
		dup2(fd[i][1], 1);
		close(fd[i][1]);
	}
	else if (cmd.childs == NULL)
	{
		printf("entra2, fd1: %d, fd2: %d,i: %d\n", fd[i - 1][0], fd[i - 1][1], i);
		dup2(fd[i - 1][0], 0);
		close(fd[i - 1][0]);
		close(fd[i - 1][1]);
		// dup2(pipex.outfile, 1);
		// close(pipex.outfile);
	}
	else
	{
		printf("entra3, fd1: %d, fd2: %d\n", fd[i][0], fd[i][1]);
		dup2(fd[i][1], 1);
		close(fd[i][1]);
		dup2(fd[i][0], 0);
		close(fd[i][0]);
	}
	if (execve(cmd.cmd, cmd.options, NULL) == -1)
		printf("Error Executing %s\n", cmd.options[0]);
	return (0);
}

void execute(t_cmds *cmd,int fd[2])
{
	int err;

	err = 0;
	if(!ft_strncmp(cmd->options[0],"cd",2) && ft_strlen(cmd->options[0]) == 2)
	{
		if(cmd->options[1])
			err = chdir(cmd->options[1]);
		if(err)
			printf("%s\n",strerror(errno));
		close(fd[1]);
	}
	else if (execve(cmd->cmd, cmd->options, NULL) == -1)
	{
		printf("Error Executing %s\n", cmd->options[0]);
		exit(1);
	}
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
				execute(aux,fd);
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
			pid = fork();
			if (pid == 0)
				execute(aux,fd);
			else
				wait(NULL);
		}
		d->cmds = d->cmds->next;
	}
	d->cmds = first;
}
