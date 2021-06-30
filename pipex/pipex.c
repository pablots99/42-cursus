/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:09:47 by pablo             #+#    #+#             */
/*   Updated: 2021/06/30 20:55:51 by ptorres          ###   ########.fr       */
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
	char *aux1;
	j = 0;
	i = 0;
	p->cmds = malloc(p->argc + 2 * sizeof(char **));

	while (i < p->argc)
	{
		splited = ft_split(args[i + 2], ' ');
		aux = ft_strjoin("/",*splited);
		free(*splited);
		splited[0] = get_cmd(p,aux);
		p->cmds[i] = ft_sstr_dup(splited);
		free(aux);
		ft_bi_free(splited);
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

void free_struct(t_pipex *p)
{
	int i;
	int j;
	i = 0;
	while(p->cmds[i])
	{
		ft_bi_free(p->cmds[i]);
		i++;
	}
	free(p->cmds);

	ft_bi_free(p->paths);
}

int executeCommands(char **cmds, int argc,char **env)
{
	t_pipex pipex;
	int pid;
	int i;
	int fd[argc - 4][2];
	int fd1;


	i = 0;
	pipex.paths = get_paths(env);
	if(!pipex.paths)
		return (1);
	pipex.infile = open(cmds[1], O_RDONLY);
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
			if(i == 0)
			{
				close(fd[i][0]);
				if(fd1)
				{
					dup2(fd1,0);
					close(fd1);
				}
				dup2(fd[i][1],1);
				close(fd[i][1]);
			}
			else if(i == pipex.argc -1)
			{
				dup2(fd[i-1][0],0);
				close(fd[i-1][0]);
				// fd1 = open(pipex.outfile,  O_WRONLY | O_CREAT | O_TRUNC, 0644);
				// dup2(fd1,1);
				// close(fd1);
			}
			else{
				dup2(fd[i][1],1);
				close(fd[i][1]);
				dup2(fd[i][0],0);
				close(fd[i][0]);
			}
			if (execve(pipex.cmds[i][0],pipex.cmds[i], NULL) == -1)
				printf("Error Executing command or invalid command\n");
		}
		else
		{
			if(i > 0)
				close(fd[i][1]);
			if(i < pipex.argc -1)
				close(fd[i][1]);
		}
		i++;
	}
	i = 0;
	while(i < pipex.argc -1)
	{
		wait(NULL);
		i++;
	}

	free_struct(&pipex);
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
	
	}
	system("leaks pipex");
	return (0);
}
