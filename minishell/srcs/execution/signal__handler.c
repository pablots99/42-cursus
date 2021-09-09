/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal__handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:18:19 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/09 21:30:50 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_sigint2(int sig)
{
	sig = 0;
	write(1, "\b\b", 2);
}

void handle_sigint(int sig)
{
	sig = 0;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
void handle_sigquit(int sig)
{
	sig = 0;
	rl_on_new_line();
	return;
}