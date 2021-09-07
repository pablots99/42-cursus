/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:41:03 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/06 13:04:21 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_cmd_path(char *cmd, char **paths)
{
	int i;
	char *aux;
	int fd;
	char *cmd2;

	fd = 0;
	i = 0;
	cmd2 = ft_strjoin("/", cmd);
	while (paths[i])
	{
		aux = ft_strjoin(paths[i], cmd2);
		fd = open(aux, O_RDONLY);
		if (!(fd < 0))
		{
			close(fd);
			free(cmd2);
			free(cmd);
			return (aux);
		}
		free(aux);
		i++;
	}
	free(cmd2);
	return (cmd);
}

//ver si hay variables
char *find_vars(char *str, t_data *d)
{
	char *var_value;

	if (str[0] == '?'  && !str[1])
		var_value = ft_itoa(d->status);
	else
		var_value = get_session_env(d, str);
	if (!var_value)
		var_value = get_env_ms(d, str);
	if (!var_value)
		return NULL;
	return var_value;
}

t_cmds *new_cmd()
{
	t_cmds *new;
	new = malloc(sizeof(t_cmds));
	new->apppend = NULL;
	new->options = NULL;
	new->childs = NULL;
	new->cmd = NULL;
	new->err = 0;
	new->otput_fd = 0;
	new->input_fd = 0;
	new->var_asign = 0;
	return new;
}

void add_child(t_cmds **cmds, t_cmds *cmd)
{
	t_cmds *child;

	if (!cmds || !cmd)
		return;
	child = *cmds;
	if (*cmds == NULL)
		*cmds = cmd;
	else
	{
		while (child->childs)
		{
			child = child->childs;
		}
		child->childs = cmd;
	}
}

void print_command(t_data *a)
{
	t_data *d;

	d = a;
	while (d->cmds != NULL)
	{
		printf("CMD:\n%s\n\n", d->cmds->cmd);
		printf("OPTIONS:\n");
		ft_bstrprint(d->cmds->options);
		printf("OUTPUTS:\n");
		printf("--------------\n");
		d->cmds = d->cmds->childs;
	}
}

t_parse init_parse()
{
	t_parse res;

	res.d_quote = 0;
	res.s_quote = 0;
	res.i = 0;
	res.n_pipe = 0;
	res.space = 0;
	res.do_redir = 0;
	res.so_redir = 0;
	res.si_redir = 0;
	res.di_redir = 0;
	res.var = 0;
	res.var_name = NULL;
	res.var_end = 0;
	return (res);
}

void find_tokens(char *str, t_parse *p, t_cmds *cmd)
{
	p->skip = 0;
	p->space = 0;

	if(str[p->i] == '	')
		str[p->i] = ' ';
	//quotes
	if (str[p->i] == '\'' && !p->d_quote)
	{
		p->var = 0;
		if (p->s_quote)
			p->s_quote = 0;
		else
			p->s_quote = 1;
		p->skip = 1;
	}
	if (str[p->i] == '"' && !p->s_quote)
	{
		if (p->d_quote)
			p->d_quote = 0, p->space = 1;
		else
			p->d_quote = 1;
		p->skip = 1;
	}
	if (p->var && (str[p->i] == ' ' || str[p->i] == '"' || str[p->i] == '\'' ))
		p->var_end = 1;
	//redirecciones out
	if (str[p->i] == '>' && !p->d_quote && !p->s_quote)
	{
		if (str[p->i + 1] != '>' && str[p->i - 1] != '>')
		{
			p->so_redir = 1;
			p->space = 1;
			cmd->apppend = ft_append_char(cmd->apppend, '0');
		}
		else
		{
			p->do_redir++;
			p->space = 1;
			p->so_redir = 0;
			cmd->apppend = ft_append_char(cmd->apppend, '1');
		}
	}
	else if (str[p->i] == '<' && !p->d_quote && !p->s_quote)
	{
		if (str[p->i + 1] != '<' && str[p->i - 1] != '<')
		{
			p->si_redir = 1;
			p->space = 1;
		}
		else
		{
			p->si_redir = 0;
			p->di_redir++;
			p->space = 1;
		}
	}
	else if (str[p->i] == '$' && !p->s_quote && str[p->i + 1] && str[p->i + 1] != ' ')
		p->var = 1, p->skip = 1, p->i++;
	else if ((str[p->i] == ' ' && !p->d_quote && !p->s_quote))
		p->space = 1;
	//pipes
	if (str[p->i] && str[p->i] == '|' && !p->d_quote && !p->s_quote)
		p->n_pipe = 1, p->space = 1;
}

int parse_comands(t_data *d)
{
	t_cmds *cmd;
	t_parse p;
	char *str;
	int aux;
	char *var;

	p = init_parse();
	cmd = new_cmd();
	str = NULL;
	var = NULL;
	if (!is_quote_closed(d->raw_cmd))
	{
		ft_putstr_fd("minishell: Sintax error\n", 2);
		cmd->cmd = ft_strdup(d->raw_cmd);
		d->cmds = cmd;
		return 1;
	}
	while (d->raw_cmd[p.i])
	{
		find_tokens(d->raw_cmd, &p, cmd);
		if (p.var && p.var_end)
		{
			var = find_vars(p.var_name, d);
			str = ft_append_str(str, var);
			free(var);
			p.var = 0;
			free(p.var_name);
			p.var_name = NULL;
			p.var_end = 0;
		}
		if (p.space && (str != NULL))
		{

			if ((p.do_redir || p.so_redir) && d->raw_cmd[p.i] != '>')
			{
				create_output(cmd, str, p.do_redir, p.so_redir);
				p.so_redir = 0;
				p.do_redir = 0;
			}
			else if ((p.di_redir) && d->raw_cmd[p.i] != '<')
				save_double_redir(str, cmd, p.di_redir), p.di_redir = 0;
			else if ((p.si_redir) && d->raw_cmd[p.i] != '<')
			{
				read_inputs(cmd, str);
				p.si_redir = 0;
			}
			else if (!cmd->cmd)
			{
				cmd->cmd = get_cmd_path(str, d->paths);
				cmd->options = ft_append_string(cmd->options, str);
			}
			else
			{
				cmd->options = ft_append_string(cmd->options, str);
				if (str != NULL && str[0] != 0)
					free(str);
			}
			str = NULL;
		}

		if (!p.space && !p.skip && !p.var)
			str = ft_append_char(str, d->raw_cmd[p.i]);
		else if (p.var && !p.var_end)
			p.var_name = ft_append_char(p.var_name, d->raw_cmd[p.i]);
		if (p.n_pipe)
		{
			if (cmd->cmd && is_asign(cmd->cmd))
				cmd->var_asign = 1;
			else
				cmd->var_asign = 0;
			add_child(&d->cmds, cmd);
			cmd = new_cmd();
			aux = p.i;
			p = init_parse();
			p.i = aux;
		}
		p.i++;
	}
	//if no space at the end
	if (p.var && p.var_name)
	{
		var = find_vars(p.var_name, d);
		str = ft_append_str(str, var);
		free(var);
		free(p.var_name);
		p.var = 0;
		p.var_name = NULL;
	}
	if ((p.do_redir || p.so_redir) && str != NULL)
		create_output(cmd, str, p.do_redir, p.so_redir);
	else if ((p.si_redir) && d->raw_cmd[p.i] != '<')
	{
		read_inputs(cmd, str);
		p.si_redir = 0;
	}
	else if ((p.di_redir) && d->raw_cmd[p.i] != '<')
		save_double_redir(str, cmd, p.di_redir), p.di_redir = 0;
	else if (!cmd->cmd)
	{
		cmd->cmd = get_cmd_path(str, d->paths);
		cmd->options = ft_append_string(cmd->options, str);
	}
	else if (str)
	{
		cmd->options = ft_append_string(cmd->options, str);
		if (str != NULL && str[0] != 0)
			free(str);
	}
	// else
	// 	printf("unexpected token\n");
	if (cmd->cmd && is_asign(cmd->cmd))
		cmd->var_asign = 1;
	add_child(&d->cmds, cmd);
	return 1;
}
