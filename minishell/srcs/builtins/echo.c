/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:07:23 by pablo             #+#    #+#             */
/*   Updated: 2021/09/27 12:05:09 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	_init_vars(int *i, int *n, int *fd)
{
	*fd = 1;
	*i = 1;
	*n = 0;
}

int	is_flag(char *opt)
{
	int	i;

	if (!opt || (opt[0] != '-'))
		return (0);
	i = 1;
	while (opt[i] == 'n')
		i++;
	if (!opt[i])
		return (1);
	return (0);
}

void	execute_echo(t_cmds *cmd)
{
	int	i;
	int	n;
	int	fd;
	int	aux;

	_init_vars(&i, &n, &fd), n = 0, aux = 1;
	if (cmd->otput_fd)
		fd = cmd->otput_fd;
	while (cmd->options[i])
	{
		if (is_flag(cmd->options[i]) && aux)
			n = 1;
		else
		{
			ft_putstr_fd(cmd->options[i], fd), aux = 0;
			if (cmd->options[i + 1])
				ft_putchar_fd(' ', fd);
		}
		i++;
	}
	if (!n)
		ft_putchar_fd('\n', fd);
	if (cmd->otput_fd)
		close_fd(fd);
	exit(0);
}
