/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:07:16 by pablo             #+#    #+#             */
/*   Updated: 2021/09/06 16:20:18 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void execute_pwd(t_data *d, int fd_out)
{
	ft_putstr_fd(d->path, 1);
	ft_putchar_fd('\n', 1);
	exit(0);
}

void execute_cd(t_cmds *cmd, int fd[2])
{
	int err;
	char *old_pwd;

	err = 0;
	old_pwd = getenv("PWD");
	if (cmd->options[1])
	{
		err = chdir(cmd->options[1]);
		
	}
	if (err)
	{
		ft_putstr_fd("minishel: cd: ",1);
		ft_putstr_fd(cmd->options[1],1);
		ft_putstr_fd(": ",1);;
		ft_putstr_fd(strerror(errno),1);
		ft_putchar_fd('\n',1);
		exit(1);
	}
	else
	{	
		//set new pwd on env and save the oldpwd 
	}

	exit(0);
}
