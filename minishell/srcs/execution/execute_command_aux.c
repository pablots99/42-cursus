/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_aux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:52:48 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/12 18:40:07 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_vars(t_data *d, t_cmds **first)
{
	*first = d->cmds;
	d->fd[1] = 1;
	d->fd[0] = 0;
	d->fd_in = 0;
}

void	close_fd(int fd)
{
	if (fd != -1)
		close(fd);
}
