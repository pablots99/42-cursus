/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:02:38 by pablo             #+#    #+#             */
/*   Updated: 2021/07/06 17:47:44 by pablo            ###   ########.fr       */
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
void free_command(t_data *d)
{
	t_cmds *aux;
	while (d->cmds)
	{
		while (d->cmds->childs)
		{
			free(d->cmds->childs->cmd);
			ft_bi_free(d->cmds->childs->options);
			aux = 	d->cmds->childs;
			d->cmds->childs = d->cmds->childs->childs;
			free(aux);
		}
		free(d->cmds->cmd);
		ft_bi_free(d->cmds->options);
		aux = d->cmds;
		d->cmds = d->cmds->next;
		free(aux);

	}

}

int main(int argc,char **argv,char **env)
{
	char *route;
	t_data data;
	char *aux;

	data.raw_cmd = "";
	data.env = env;
	data.first_env = 1;
	data.paths =  ft_split(getenv("PATH"),':');
	data.session_env =NULL;
	//write_cwd(data);
	while (1)
	{
		data.cmds =  NULL;
		route = ft_strjoin(getcwd(data.path, sizeof(data.path)), ">> ");
		data.raw_cmd = readline(route);
		//save history
		add_history(data.raw_cmd);
		//check open quotes
		while (!is_quote_closed(data.raw_cmd))
		{
			aux = data.raw_cmd;
			data.raw_cmd = ft_strjoin(aux, readline(">"));
			free(aux);
		}
		//parse_comands
		if(ft_strlen(data.raw_cmd))
		{
			if(parse_comands(&data))
				execute_commands(&data);
				// printf("xD\n");

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
