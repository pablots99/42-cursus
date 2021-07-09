/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:48:22 by pablo             #+#    #+#             */
/*   Updated: 2021/07/09 17:25:13 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int execute_builtins(t_cmds *cmd, int fd[2], t_data *d)
{
	int err;
	int is;

	is = 0;
	err = 0;
	if (ft_str_equal(cmd->options[0], "cd"))
	{

		if (cmd->options[1])
			err = chdir(cmd->options[1]);
		if (err)
			printf("%s\n", strerror(errno));
		close(fd[1]);
		is = 1;
	}
	else if (ft_str_equal(cmd->options[0], "pwd"))
		execute_pwd(d,fd[1]),is = 1;
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

	 // input redirections aqui
	first = d->cmds;
	while (d->cmds)
	{
		i = 0;
		fd_in = 0;
		aux = d->cmds;
		if (aux->childs)
			cond = 1;
		else
			cond = 0;
		while (aux != NULL && cond)
		{
			if (aux->childs != NULL)
				pipe(fd);
			pid = fork();
			if (pid == 0)
			{
				create_outputs(aux);
				dup2(fd_in, 0);
				close(fd[0]);
				if (aux->childs  != NULL) //si tiene hijos hace el dup2 del output
				{
					printf("hola\n");
					dup2(fd[1], 1);
				}
				if(aux->otput_fd && aux->childs == NULL) //si no  tiene hijos pero hay redireccion hace el dup2 del output
				{
					printf("output: %d\n",aux->otput_fd);
					dup2(d->cmds->otput_fd,1);
				}
				if (execve(aux->cmd, aux->options, d->env) == -1)
				{
					printf("Error Executing %s\n", aux->options[0]);
					exit(1);
				}
			}
			else
			{
				if(aux->otput_fd)
					close(aux->otput_fd);
				close(fd[1]);
					fd_in = fd[0];
				wait(NULL);
			}
			aux = aux->childs;
			i++;
		}
		//solo un comando funciona bien
		if (i == 0 && d->cmds->childs == NULL)
		{
			create_outputs(d->cmds);
			fd[0] = 0;
			fd[1] = d->cmds->otput_fd;
			if(!execute_builtins(d->cmds,fd,d))
			{
				pid = fork();
				if (pid == 0)
				{
					if(d->cmds->otput_fd)
					{
						printf("output: %d\n",d->cmds->otput_fd);
						dup2(d->cmds->otput_fd,1);
					}
					if (execve(d->cmds->cmd, d->cmds->options, d->env) == -1)
					{
						printf("Error Executing %s\n", d->cmds->options[0]);
						exit(1);
					}
				}
				else
					if(d->cmds->otput_fd)
						close(d->cmds->otput_fd);
					wait(NULL);
				}
		}
		d->cmds = d->cmds->next;
	}
	d->cmds = first;
}
