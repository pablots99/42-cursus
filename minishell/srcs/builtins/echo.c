/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:07:23 by pablo             #+#    #+#             */
/*   Updated: 2021/07/12 13:53:01 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void execute_echo(t_cmds *cmd,int fd[2])
{

	int i;
	int n;

	i = 1;
	n = 0;
	if(!fd[1])
		fd[1] = 1;
	while (cmd->options[i])
	{
		if (ft_str_equal("-n",cmd->options[i]) && i == 1)
			n = 1;
		else
			ft_putstr_fd(cmd->options[i],fd[1]);
		i++;
		if(cmd->options[i] && !(n && i == 2))
			ft_putchar_fd(' ',fd[1]);
	}
	if(!n)
		ft_putchar_fd('\n',fd[1]);
}
