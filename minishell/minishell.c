/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:02:38 by pablo             #+#    #+#             */
/*   Updated: 2021/08/23 15:37:49 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minishell.h"

void ft_bstrprint(char **bstr)
{
	int i;

	i = 0;
	while (bstr && bstr[i])
	{
		printf("%s\n", bstr[i]);
		i++;
	}
}

void handle_sigint(int sig)
{
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
void handle_sigquit(int sig)
{
	rl_on_new_line();
	return ;
}


int main(int argc, char **argv, char **env)
{
	char *route;
	t_data data;
	char *aux;
	int _signal;

	data.raw_cmd = "";
	data.status = 0;
	data.env = env;
	//data.exportables = save_exportables(dup_bi_string(env));
	data.first_env = 1;
	in_read = 0;
	data.paths = ft_split(getenv("PATH"), ':');
	data.session_env = NULL;
	while (1)
	{
		signal(SIGQUIT,handle_sigquit);
		signal(SIGINT,handle_sigint);
		data.cmds = NULL;
		route = ft_strjoin(getcwd(data.path, sizeof(data.path)), ">> ");
		data.raw_cmd = readline(route);
		if (!data.raw_cmd)
		{
			printf("");
			exit(0);
		}
		while (!is_pipe_closed(data.raw_cmd))
		{
			aux = readline("> ");
			ft_append(&data.raw_cmd, aux);
			free(aux);
		}
		add_history(data.raw_cmd);
		if (ft_strlen(data.raw_cmd) > 0)
		{
			if (parse_comands(&data))
				execute_commands(&data);
		}
		free_command(&data);
		free(route);
		free(data.raw_cmd);
	}
	return 0;
}
