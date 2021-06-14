/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recive_comands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:08:35 by ptorres           #+#    #+#             */
/*   Updated: 2021/06/09 18:50:36 by pablo            ###   ########.fr       */
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
	int bytes;
	get_next_line(0,cmd);
	return 1;
}



