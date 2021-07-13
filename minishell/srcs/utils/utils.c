/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 03:21:03 by pablo             #+#    #+#             */
/*   Updated: 2021/07/09 20:34:32 by pablo            ###   ########.fr       */
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
	if(len1 != len2)
		return (0);
	while(i < len1)
	{
		if(s1[i] != s2[i])
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

	res = malloc(ft_strlen(str)+2 *sizeof(char));
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	i++;
	res[i] = 0;
	free(str);
	return (res);

}

void create_outputs(t_cmds *cmd)
{
	int i;
	int fd;
	i = 0;
	if(!cmd->outputs)
		return ;
	while (cmd->outputs[i])
	{

		if(cmd->apppend)
			fd = open(cmd->outputs[i],O_WRONLY | O_CREAT  | O_APPEND, 0644);
		else
			fd = open(cmd->outputs[i],O_WRONLY | O_CREAT | O_TRUNC, 0644);
		printf("open:%s, fd:%d\n",cmd->outputs[i],fd);
		if(cmd->outputs[i+1])
		{
			printf("closed:%s\n",cmd->outputs[i]);
			close(fd);
		}
		i++;
	}
	cmd->otput_fd = fd;
}

void free_command(t_data *d)
{
	t_cmds *aux;
	int i;

	i = 0;
	while (d->cmds)
	{
		while (d->cmds->childs)
		{
			free(d->cmds->childs->cmd);
			if(d->cmds->childs->outputs)
				ft_bi_free(d->cmds->childs->outputs);
			ft_bi_free(d->cmds->childs->options);
			aux = 	d->cmds->childs;
			d->cmds->childs = d->cmds->childs->childs;
			free(aux);
		}
		if(d->cmds->outputs)
			ft_bi_free(d->cmds->outputs);
		ft_bi_free(d->cmds->options);
		free(d->cmds->cmd);
		aux = d->cmds;
		d->cmds = d->cmds->next;
		free(aux);
		i++;
	}

}
