/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:54:25 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/10 16:30:06 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void exit_ms(t_data *d,t_cmds *cmd)
{
	int exit_code;
	int i;

	i = 0;
	exit_code = 1;
	ft_putstr_fd("exit\n",1);
	if(cmd->options[1])
	{
		while (cmd->options[1][i])
		{
			if(!ft_isdigit(cmd->options[1][i]))
			{
				ft_putstr_fd("minishell: exit: asd: numeric argument required\n",1);
				exit(255);
			}
			i++;
		}
		exit_code = ft_atoi(cmd->options[1]);
	}
	if(ft_bi_strlen(cmd->options) > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n",1);
		d->status = 1;
		return ;
	}
	free_command(d);
	exit(exit_code);
}

