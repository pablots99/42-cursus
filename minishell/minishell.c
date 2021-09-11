/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:02:38 by pablo             #+#    #+#             */
/*   Updated: 2021/09/11 22:28:08 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minishell.h"



void __init_vars(t_data *data,char **env)
{
	int pid;
	char *tty[2];

	tty[0] = "/bin/stty";
	tty[1] = "-echoctl";
	data->raw_cmd = "";
	data->status = 0;
	data->env = env;
	data->exportables = save_exportables(env);
	data->first_env = 1;
	data->session_env = NULL;
	getcwd(data->path,2000);
	pid = fork();
	if(pid == 0)
	{
		if(execve(tty[0],tty,env) == -1)
		{
			perror("minishell: ");
			exit(127);
		}
	}
	else
		wait(NULL);

}


int main(int argc, char **argv, char **env)
{
	char *route;
	t_data data;
	char *path_aux;

	argc = 0;
	argv = NULL;
	__init_vars(&data,env);
	path_aux = get_env_ms(&data, "PATH");
	data.paths = ft_split(path_aux, ':');
	while (1)
	{
		signal(SIGQUIT, handle_sigquit);
		signal(SIGINT, handle_sigint);
		data.cmds = NULL;
		route = "minishell$ ";
		data.raw_cmd = readline(route);
		if (!data.raw_cmd)
		{
			printf("");
			exit(0);
		}
		add_history(data.raw_cmd);
		if (ft_strlen(data.raw_cmd) > 0)
		{
			if (parse_comands(&data))
				execute_commands(&data);
			ft_bi_free(data.paths);
			free(path_aux);
			path_aux = get_env_ms(&data, "PATH");
			data.paths = ft_split(path_aux, ':');
		}
		free_command(&data);
		free(data.raw_cmd);
	}
	return 0;
}
