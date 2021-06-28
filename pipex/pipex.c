/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:09:47 by pablo             #+#    #+#             */
/*   Updated: 2021/06/28 01:00:34 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/pipex.h"

#include <unistd.h>

char *get_cmd(t_pipex *p, char *cmd)
{
	int i;
	char *aux;
	int fd;

	fd = 0;
	i  =0;

	while(p->paths[i])
	{
		aux =  ft_strjoin(p->paths[i], cmd);
		fd = open(aux, O_RDONLY);
		if(!(fd < 0))
		{
			close(fd);
			return aux;
		}
		free(aux);
		i++;
	}
	return NULL;
}
int saveCmds(char **args, t_pipex *p)
{
	int i;
	int j;
	char **splited;
	char *aux;
	j = 0;
	i = 0;
	p->cmds = malloc(p->argc + 1 * sizeof(char **));

	while (p->cmds[i] && i < p->argc)
	{
		splited = ft_split(args[i + 2], ' ');
		aux = ft_strjoin("/",*splited);
		splited[0] = get_cmd(p,aux);
		if(!splited[0])
			splited[0] = aux+1;
		printf("cmd: %s\n", splited[0]);
		free(aux);
		p->cmds[i] = splited;
		i++;
	}
	p->cmds[i] = NULL;
	return (1);
}

char **get_paths(char **env)
{
	int i;
	char **paths;

	i = 0;
	while(env[i])
	{
		if(!ft_strncmp("PATH",env[i],4))
		{
			paths = ft_split(env[i],':');
			return paths;
		}
		i++;
	}
	paths = NULL;
	return paths;
}

int executeCommands(char **cmds, int argc,char **env)
{
	t_pipex pipex;
	int pid;
	int i;
	int fd[argc - 4][2];

	i = 0;
	pipex.paths = get_paths(env);
	if(!pipex.paths)
		return (1);
	pipex.infile = cmds[1];
	pipex.outfile = cmds[argc];
	pipex.argc = argc - 3;
	saveCmds(cmds, &pipex);
	while (i < pipex.argc)
	{
		if(i != pipex.argc -1)
			pipe(fd[i]);
		pid = fork();
		if (pid == 0)
		{
			if(i==0)
			{
				dup2(fd[i][0],STDOUT_FILENO);
			}
			if(i == pipex.argc)
			{
				dup2(fd[i][1],STDIN_FILENO);
			}
			else
			{
				dup2(fd[i][1],STDOUT_FILENO);
				dup2(fd[i][0],STDIN_FILENO);
			}
			if (execve(pipex.cmds[i][0], pipex.cmds[i], NULL) == -1)
				printf("Error Executing command or invalid command\n");

		}
		i++;
	}

	i = 0;
	while (i < pipex.argc)
	{
		wait(NULL);
		i++;
	}
	return (0);
}

int main(int argc, char **argv, char **env)
{
	if (argc < 5)
	{
		write(1, "Arguments Error\n", ft_strlen("Arguments Error\n"));
		return (1);
	}
	else
	{
		if (executeCommands(argv, argc,env))
		{
			write(1, "Command Error\n", ft_strlen("Command Error\n"));
			return (1);
		}
		return (0);
	}




}
