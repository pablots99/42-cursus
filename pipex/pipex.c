/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:09:47 by pablo             #+#    #+#             */
/*   Updated: 2021/07/05 16:56:52 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/pipex.h"

void	dups_aux(int i, int *fd[2])
{
	dup2(fd[i][1], 1);
	close(fd[i][1]);
	dup2(fd[i][0], 0);
	close(fd[i][0]);
}

int	dups(int i, t_pipex pipex, int *fd[2])
{
	if (i == 0)
	{
		close(fd[i][0]);
		if (pipex.infile)
		{
			dup2(pipex.infile, 0);
			close(pipex.infile);
		}
		dup2(fd[i][1], 1);
		close(fd[i][1]);
	}
	else if (i == pipex.argc - 1 && pipex.cmds[i])
	{
		dup2(fd[i - 1][0], 0);
		close(fd[i - 1][0]);
		dup2(pipex.outfile, 1);
		close(pipex.outfile);
	}
	else
		dups_aux(i, fd);
	if (execve(pipex.cmds[i][0], pipex.cmds[i], NULL) == -1)
		printf("Error Executing %s\n", pipex.cmds[i][0]);
	return (0);
}

int	init_vars(int *i, t_pipex *pipex, int argc, char **cmds)
{
	int	err;

	err = 0;
	*i = 0;
	if (!pipex->paths)
		err++;
	pipex->infile = open(cmds[1], O_RDONLY);
	pipex->outfile = open(cmds[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipex->argc = argc - 3;
	err = saveCmds(cmds, pipex);
	return (err);
}

int	executeCommands(char **cmds, int argc, char **env)
{
	t_pipex	pipex;
	int		pid;
	int		i;
	int		*fd[2];
	int		err;

	pipex.paths = get_paths(env);
	err = init_vars(&i, &pipex, argc, cmds);
	while (i < pipex.argc && !err)
	{
		if (i != pipex.argc - 1)
			pipe(fd[i]);
		pid = fork();
		if (pid == 0)
			dups(i, pipex, fd);
		else
			close_fd(i, fd, pipex.argc);
		i++;
	}
	free_struct(&pipex);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	if (argc < 5)
	{
		write(1, "Arguments Error\n", ft_strlen("Arguments Error\n"));
		return (1);
	}
	else
	{
		if (executeCommands(argv, argc, env))
		{
			write(1, "Command Error\n", ft_strlen("Command Error\n"));
			return (1);
		}
	}
	// system("leaks pipex");
	return (0);
}
