/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 03:21:03 by pablo             #+#    #+#             */
/*   Updated: 2021/07/15 17:20:11 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	while (i < len1)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char *ft_append_char(char *str, char c)
{
	int len;
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
	int len;
	char **res;
	int i;

	res = malloc((ft_bi_strlen(str) + 2) * sizeof(char *));
	i = 0;
	while (str && str[i])
	{
		res[i] = ft_strdup(str[i]);
		i++;
	}
	if(s)
		res[i] = ft_strdup(s);
	else
		res[i] = NULL;
	i++;
	res[i] = NULL;
	ft_bi_free(str);
	return (res);
}

void create_outputs(t_cmds *cmd)
{
	int i;
	int fd;

	i = 0;
	if(!cmd->outputs )
		return ;
	while (cmd->outputs[i])
	{
		printf("ap: %c,name: %s\n",cmd->apppend[i],cmd->outputs[i]);
		if(cmd->apppend[i] == '0')
			fd = open(cmd->outputs[i],O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			fd = open(cmd->outputs[i],O_WRONLY | O_CREAT  | O_APPEND, 0644);
		if(cmd->outputs[i+1])
			close(fd);
		else
			cmd->otput_fd = fd;
		i++;
	}
}

void free_command(t_data *d)
{
	t_cmds *aux;

	while (d->cmds != NULL)
	{
		free(d->cmds->cmd);
		if (d->cmds->outputs)
			ft_bi_free(d->cmds->outputs);
		ft_bi_free(d->cmds->options);
		if (d->cmds->apppend)
			free(d->cmds->apppend);
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
		s1 = ft_append_char(s1,s2[i]);
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
		if((input[i] == '"' || input[i] == '\'') && cond == 0)
		{
			quote = input[i];
			cond = 1;
		}
		else if(cond == 1 && input[i] == quote)
			cond = 0;
		i++;
	}
	if(cond)
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
		if(input[i] == '|')
			cond = 0;
		else if(!cond && input[i] != ' ')
			cond = 1;
		i++;
	}
	return (cond);
}
