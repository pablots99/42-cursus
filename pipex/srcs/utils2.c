/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:25:41 by pablo             #+#    #+#             */
/*   Updated: 2021/07/05 11:57:05 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd(t_pipex *p, char *cmd)
{
	int		i;
	char	*aux;
	int		fd;

	fd = 0;
	i = 0;
	while (p->paths[i])
	{
		aux = ft_strjoin(p->paths[i], cmd);
		fd = open(aux, O_RDONLY);
		if (!(fd < 0))
		{
			close(fd);
			return (aux);
		}
		free(aux);
		i++;
	}
	return (NULL);
}

int	saveCmds(char **args, t_pipex *p)
{
	int		i;
	char	**splited;
	char	*aux;

	i = 0;
	p->cmds = malloc(p->argc + 2 * sizeof(char **));
	while (i < p->argc)
	{
		splited = ft_split(args[i + 2], ' ');
		aux = ft_strjoin("/", *splited);
		free(splited[0]);
		splited[0] = get_cmd(p, aux);
		if (splited[0] == NULL)
		{
			printf("Command '%s' not found\n", aux + 1);
			free(aux), ft_bi_free(splited);
			return (1);
		}
		p->cmds[i] = ft_sstr_dup(splited);
		free(aux);
		ft_bi_free(splited);
		i++;
	}
	p->cmds[i] = NULL;
	return (0);
}

char	**get_paths(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH", env[i], 4))
		{
			paths = ft_split(env[i], ':');
			return (paths);
		}
		i++;
	}
	paths = NULL;
	return (paths);
}

int	free_struct(t_pipex *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->cmds[i])
	{
		ft_bi_free(p->cmds[i]);
		i++;
	}
	free(p->cmds);
	ft_bi_free(p->paths);
	return (1);
}

void	close_fd(int i, int *fd[2], int argc)
{
	if (i > 0)
		close(fd[i][1]);
	if (i < argc - 1)
		close(fd[i][1]);
}
