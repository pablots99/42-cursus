/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal__handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:18:19 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/13 15:59:45 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_sigint2(int sig)
{
	sig = 0;
}

void	handle_sigint3(int sig)
{
	sig = 0;
	printf("\n");
	g_status = -1;
	exit(1);
}

void	handle_sigint(int sig)
{
	if (g_status)
	{
		g_status = 130;
		return ;
	}
	sig = 0;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_sigquit(int sig)
{
	if (sig == 0)
	{
		return ;
	}
	g_status = 0;
	rl_on_new_line();
	rl_redisplay();
}

void	handle_sigquit2(int sig)
{
	sig = 0;
	if (g_status == 2)
		return ;
	if (g_status == 1)
	{
		g_status = 130;
		printf("^\\Quit: 3\n");
		return ;
	}
	rl_on_new_line();
	rl_redisplay();
}
