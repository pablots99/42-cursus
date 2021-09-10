/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 03:21:03 by pablo             #+#    #+#             */
/*   Updated: 2021/09/10 16:50:15 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char **dup_bi_string(char **str)
{
	int i;
	char **res;

	i = 0;
	res = malloc((ft_bi_strlen(str) + 1) * sizeof(char *));
	while (str[i])
	{
		res[i] = ft_strdup(str[i]);
		i++;
	}
	res[i] = NULL;
	return (str);
}

int ft_str_equal(char *s1, char *s2)
{
	int i;
	int len1;
	int len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	if (len1 != len2)
		return (0);
	while (i < len1 && i < len2)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char *ft_append_char(char *str, char c)
{
	char *res;
	int i;

	res = malloc((ft_strlen(str) + 2) * sizeof(char));
	i = 0;
	while (str && str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	i++;
	res[i] = 0;
	if (str)
		free(str);
	return (res);
}

char **ft_append_string(char **str, char *s)
{
	char **res;
	int i;

	res = malloc((ft_bi_strlen(str) + 2) * sizeof(char *));
	i = 0;
	while (str && str[i])
	{
		res[i] = ft_strdup(str[i]);
		i++;
	}
	if (s)
		res[i] = ft_strdup(s);
	else
		res[i] = NULL;
	i++;
	res[i] = NULL;
	ft_bi_free(str);
	return (res);
}

void create_output(t_cmds *cmd, char *str, int s, int d)
{
	int fd;

	fd = 0;
	if (cmd->otput_fd != 0)
		close(cmd->otput_fd);
	if (d)
		fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (s)
		fd = open(str, O_WRONLY | O_CREAT | O_APPEND, 0644);
	cmd->otput_fd = fd;
	if (str && str[0] != 0)
		free(str);
}

void read_inputs(t_cmds *cmd, char *str)
{

	int fd;

	fd = 0;
	if (cmd->input_fd != 0)
		close(cmd->input_fd);
	fd = open(str, O_RDWR);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(str);
		cmd->err = 1;
		exit(1);
	}
	else
		cmd->input_fd = fd;
	if (str && str[0] != 0)
		free(str);
}

void free_command(t_data *d)
{
	t_cmds *aux;

	while (d->cmds != NULL)
	{
		free(d->cmds->cmd);
		ft_bi_free(d->cmds->options);
		if (d->cmds->apppend)
			free(d->cmds->apppend);
		if (d->cmds->input_type)
			free(d->cmds->input_type);
		if (d->cmds->input_fds)
			ft_bi_free(d->cmds->input_fds);
		aux = d->cmds;

		d->cmds = d->cmds->childs;

		free(aux);
	}
}

char *ft_append_str(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2 && s2[i])
	{
		s1 = ft_append_char(s1, s2[i]);
		i++;
	}
	return s1;
}

int is_quote_closed(char *input)
{

	int i;
	int cond;
	char quote;

	cond = 0;
	i = 0;
	quote = 0;
	while (input[i])
	{
		if ((input[i] == '"' || input[i] == '\'') && cond == 0)
		{
			quote = input[i];
			cond = 1;
		}
		else if (cond == 1 && input[i] == quote)
			cond = 0;
		i++;
	}
	if (cond)
		return (0);
	return (1);
}

int is_pipe_closed(char *input)
{
	int i;
	int cond;

	i = 0;
	cond = 1;
	while (input[i])
	{
		if (input[i] == '|')
			cond = 0;
		else if (!cond && input[i] != ' ')
			cond = 1;
		i++;
	}
	return (cond);
}

int save_double_redir(char *str, t_cmds *cmd)
{
	char *aux;
	int fd;

	if (cmd->input_fd)
		close(cmd->input_fd);
	fd = open("/tmp/minishelltmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	aux = readline("> ");
	while (!ft_str_equal(aux, str) || aux[ft_strlen(aux)] == '\04')
	{
		if(aux == 0)
			exit(0);
		write(fd, aux, ft_strlen(aux));
		write(fd, "\n", 1);
		free(aux);
		aux = readline("> ");
	}
	close(fd);
	fd = open("/tmp/minishelltmp", O_RDONLY);
	unlink("/tmp/minishelltmp");
	cmd->input_fd = fd;
	free(aux);
	return fd;
	free(str);
	str = NULL;
	return 0;
}

int is_asign(char *var)
{
	int i;

	i = 0;

	while (var[i])
	{
		if (var[i] == '=' && i != 0)
			return (1);
		i++;
	}
	return (0);
}

void add_fd_in(char *str, t_cmds *cmd, char d, int c)
{
	if (!(c < 3))
	{
		free(str);
		return;
	}
	cmd->input_fds = ft_append_string(cmd->input_fds, str);
	cmd->input_type = ft_append_char(cmd->input_type, d);
	free(str);
}

void fd_inputs(t_cmds *cmd)
{
	int i;

	i = 0;
	while (cmd->input_type && cmd->input_type[i])
	{
		if (cmd->input_type[i] == '1')
		{
			cmd->exit_cond = 1;
			signal(SIGINT, handle_sigint3);
			cmd->input_fd = save_double_redir(cmd->input_fds[i], cmd);
		}
		else
			read_inputs(cmd, cmd->input_fds[i]);
		i++;
	}
}

int	is_exportable(t_data *d, char *asignation)
{
	int		i;
	char	**var_name;
	char	*aux;

	var_name = ft_split(asignation, '=');
	i = 0;
	if (var_name)
		aux = ft_strjoin("declare -x ", var_name[0]);
	else
		aux = ft_strjoin("declare -x ", asignation);
	while (d->exportables[i])
	{
		if (!ft_strncmp(d->exportables[i], aux, ft_strlen(aux)))
		{
			free(d->exportables[i]);
			free(aux);
			d->exportables[i] = ft_strjoin("declare -x ", asignation);
			ft_bi_free(var_name);
			return (1);
		}
		i++;
	}
	free(aux), ft_bi_free(var_name);
	return (0);
}
