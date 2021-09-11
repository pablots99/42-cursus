/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal__handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:18:19 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/11 19:42:57 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_sigint2(int sig)
{
	sig = 0;
	status = 130;
}

void	handle_sigint3(int sig)
{
	sig = 0;
	printf("\n");
	exit(10);
}

void	handle_sigint(int sig)
{
	sig = 0;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_sigquit(int sig)
{
	sig = 0;
	rl_on_new_line();
	rl_redisplay();
}
