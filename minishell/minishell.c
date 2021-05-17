/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:02:38 by pablo             #+#    #+#             */
/*   Updated: 2021/05/17 17:22:48 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minishell.h"

int main(int argc,char **argv)
{
	t_data data;


	data.cmd = "";
	//write_cwd(data);
	while (1)
	{
		data.cmds =  NULL;
		write_cwd(data);
		recive_comands(&data.cmd);
		//parse_comands
		printf("> cmd: %s\n", data.cmd);
		parse_comands(&data);
		free(data.cmd);
	}
	
	free(data.cmd);
	return 0;
}