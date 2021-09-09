/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:07:23 by pablo             #+#    #+#             */
/*   Updated: 2021/09/09 16:07:06 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	_init_vars(int *i, int *n, int *fd)
{
	*fd = 1;
	*i = 1;
	*n = 0;
}

void	execute_echo(t_cmds *cmd)
{
	int	i;
	int	n;
	int	fd;

	_init_vars(&i, &n, &fd);
	if (cmd->otput_fd)
		fd = cmd->otput_fd;
	while (cmd->options[i])
	{
		if (ft_str_equal("-n", cmd->options[i]) && i == 1)
			n = 1;
		else
		{
			ft_putstr_fd(cmd->options[i], fd);
			if (cmd->options[i + 1])
				ft_putchar_fd(' ', fd);
		}
		i++;
	}
	if (!n)
		ft_putchar_fd('\n', fd);
	if (cmd->otput_fd)
		close(fd);
	exit(0);
}
