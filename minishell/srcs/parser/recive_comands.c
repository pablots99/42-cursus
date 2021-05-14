/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recive_comands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:08:35 by ptorres           #+#    #+#             */
/*   Updated: 2021/05/14 13:14:52 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void write_cwd(t_data d)
{
	getcwd(d.path, sizeof(d.path));
	ft_putstr_fd(d.path,1);
	write(1," >> ",4);
}

int recive_comands(char **cmd)
{
	get_next_line(0,cmd);
	return 1;
}