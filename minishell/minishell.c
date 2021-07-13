/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:02:38 by pablo             #+#    #+#             */
/*   Updated: 2021/07/13 16:37:01 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minishell.h"

void ft_bstrprint(char **bstr)
{
	int i;

	i = 0;
	while(bstr[i])
	{
		printf("%s\n",bstr[i]);
		i++;
	}
}

void handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

int main(int argc,char **argv,char **env)
{
	char *route;
	t_data data;
	char *aux;
	int _signal;

	data.raw_cmd = "";
	data.status = 0;
	data.env = env;
	data.first_env = 1;
	data.paths =  ft_split(getenv("PATH"),':');
	data.session_env =NULL;
	//write_cwd(data);
	while (1)
	{
		//
		data.cmds =  NULL;
		route = ft_strjoin(getcwd(data.path, sizeof(data.path)), ">> ");
		data.raw_cmd = readline(route);
		//save history
		//check open quotes
		if(!data.raw_cmd)
		{
			printf("");
			exit(0);
		}
		while (!is_quote_closed(data.raw_cmd))
		{
			aux =readline(">");
			ft_append(&data.raw_cmd,aux);
			free(aux);
		}
		add_history(data.raw_cmd);

		//parse_comands
		if(ft_strlen(data.raw_cmd))
		{
			if(parse_comands(&data))
				execute_commands(&data);
				// ;
			//

		}
		free_command(&data);
		free(route);
		free(data.raw_cmd);
	}
	return 0;
}
// if(!ft_strncmp(data.raw_cmd,"exit",4) && ft_strlen(data.raw_cmd) == 4)
		// {
		// 	free_command(&data);
		// 	ft_bi_free(data.paths);
		// 	free(route);
		// 	free(data.raw_cmd);
		// 	return 1;
		// }
