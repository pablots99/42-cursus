/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:07:16 by pablo             #+#    #+#             */
/*   Updated: 2021/07/09 19:12:30 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void execute_pwd(t_data *d, int fd_out)
{
	if (!fd_out)
		fd_out = 1;
	ft_putstr_fd(d->path, fd_out);
	ft_putchar_fd('\n', fd_out);
}

void execute_cd(t_cmds *cmd, int fd[2])
{
	int err;

	if(!fd[1])
		fd[1] = 1;
	err = 0;
	if (cmd->options[1])
		err = chdir(cmd->options[1]);
	if (err)
	{
		ft_putstr_fd(strerror(errno),fd[1]);
		ft_putchar_fd('\n',fd[1]);
	}
}
