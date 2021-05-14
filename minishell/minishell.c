/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:02:38 by pablo             #+#    #+#             */
/*   Updated: 2021/05/14 13:55:56 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minishell.h"

int main(int argc,char **argv)
{
	t_data data;


	data.cmd = "";
	//write_cwd(data);
	while (ft_strncmp(data.cmd, "exit", 4))
	{
		write_cwd(data);
		recive_comands(&data.cmd);
		//parse_comands
		printf("%s> cmd: %s\n",data.path, data.cmd);
		save_comands(&data);
		free(data.cmd);
	}
	return 0;
}