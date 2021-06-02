/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:02:38 by pablo             #+#    #+#             */
/*   Updated: 2021/06/02 10:11:13 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minishell.h"


void ft_bstrprint(char **bstr,char *name)
{
	int i;
	printf("%s: ",name);
	while(bstr[i])
	{
		printf("%s,",bstr[i]);
		i++;
	}
	printf("\n");
}


int main(int argc,char **argv)
{
	t_data data;
	data.raw_cmd = "";
	//write_cwd(data);
	while (1)
	{
		data.cmds =  NULL;
		write_cwd(data);
		recive_comands(&data.raw_cmd);
		//save history

		//parse_comands
		parse_comands(&data);
		//execute comands
		free(data.raw_cmd);
	}

	free(data.raw_cmd);
	return 0;
}
