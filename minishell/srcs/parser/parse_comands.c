/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:41:03 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/11 14:49:41 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_cmd_path(char *cmd, char **paths)
{
	int		i;
	char	*aux;
	int		fd;
	char	*cmd2;

	fd = 0;
	i = 0;
	if(!paths || is_builtin(cmd))
		return cmd;
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

void	find_tokens(char *str, t_parse *p, t_cmds *cmd)
{
	p->skip = 0;
	p->space = 0;
	if (str[p->i] == '	')
		str[p->i] = ' ';
	if (str[p->i] == '\'' && !p->d_quote)
	{
		p->var = 0;
		if (p->s_quote)
			p->s_quote = 0;
		else
			p->s_quote = 1;
		p->skip = 1;
	}
	if (str[p->i] == '\\' && !p->d_quote && !p->s_quote && str[p->i - 1] != '\\')
		p->skip = 1;
	find_quotes(str, p,cmd);
	if (!find_redir_out(str, p, cmd))
		if (!find_redir_in(str, p))
			find_parse_vars(str, p);
	if (str[p->i] && str[p->i] == '|' && !p->d_quote && !p->s_quote)
	{
		p->n_pipe = 1;
		p->space = 1;
	}
}

void	save_parsed_str(t_data *d, t_parse *p, t_cmds **cmd, char **str)
{
	char	*var;

	var = NULL;
	if (p->var && p->var_end)
	{
		var = find_vars(p->var_name, d);
		*str = ft_append_str(*str, var);
		free(var), p->var = 0;
		free(p->var_name), p->var_name = NULL;
		p->var_end = 0;
	}
	if (p->space && (*str != NULL))
		save_data(d, p, *cmd, str), *str = NULL;
	if (!p->space && !p->skip && !p->var)
		*str = ft_append_char(*str, d->raw_cmd[p->i]);
	else if (p->var && !p->var_end)
		p->var_name = ft_append_char(p->var_name, d->raw_cmd[p->i]);
	if (p->n_pipe)
		save_pipe(d, cmd, p);
}

void	save_no_space(t_data *d, t_parse p, t_cmds *cmd, char **str)
{
	char	*var;

	var = NULL;
	if (p.var && p.var_name)
	{
		var = find_vars(p.var_name, d);
		*str = ft_append_str(*str, var), free(var);
		free(p.var_name), p.var = 0;
		p.var_name = NULL;
	}
	if ((p.do_redir || p.so_redir) && *str != NULL)
		add_outpput(cmd, *str, p.do_redir, p.so_redir);
	else if ((p.si_redir) && d->raw_cmd[p.i] != '<')
		add_fd_in(*str,cmd,'0',1), p.si_redir = 0;//read_inputs(cmd, *str)
	else if ((p.di_redir) && d->raw_cmd[p.i] != '<')
		add_fd_in(*str,cmd,'1',p.di_redir);// ,cmd->input_fd = save_double_redir(*str, cmd, p.di_redir);
	else if (!cmd->cmd)
		save_first_cmd(d, str, &cmd);
	else if (*str)
	{
		cmd->options = ft_append_string(cmd->options, *str);
		if (*str != NULL && *str[0] != 0)
			free(*str);
	}
}

int	parse_comands(t_data *d)
{
	t_cmds	*cmd;
	t_parse	p;
	char	*str;
	char	*var;

	p = init_parse();
	cmd = new_cmd();
	str = NULL;
	var = NULL;
	if (is_sintax_error(d, cmd))
	{
		d->status = 258;
		return  (0);
	}
	while (d->raw_cmd[p.i])
	{
		find_tokens(d->raw_cmd, &p, cmd);
		save_parsed_str(d, &p, &cmd, &str);
		p.i++;
	}
	save_no_space(d, p, cmd, &str);
	if (cmd->cmd && is_asign(cmd->cmd))
		cmd->var_asign = 1;
	add_child(&d->cmds, cmd);
	return (1);
}
