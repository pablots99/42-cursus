/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:41:03 by ptorres           #+#    #+#             */
/*   Updated: 2021/07/06 17:46:03 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_cmd_path(char *cmd,char **paths)
{
	int		i;
	char	*aux;
	int		fd;

	fd = 0;
	i = 0;
	while (paths[i])
	{
		aux = ft_strjoin(paths[i], cmd);
		fd = open(aux, O_RDONLY);
		if (!(fd < 0))
		{
			close(fd);
			free(cmd);
			return (aux);
		}
		free(aux);
		i++;
	}
	return (cmd);
}

char **parse_cmd(char *cmd, int *assign,char **new,char **paths)
{
	char **splited;
	int len;
	char *ret;
	int i;

	splited = ft_split_ms(cmd, ' ');
	len = ft_bi_strlen(splited);
	if(is_asign(splited[0]))
		*assign = 1;
	else
		*assign = 0;
	if (len > 0)
		ret = get_cmd_path(ft_strjoin("/",splited[0]),paths);
	else
		ret = NULL;
	*new = ret;
	free(cmd);
	return splited;
}

t_cmds *new_cmd(char *cmd,t_data data)
{
	t_cmds *new;
	new = malloc(sizeof(t_cmds));
	new->options = parse_cmd(cmd, &new->var_asign,&new->cmd,data.paths);
	new->inputs = NULL;
	new->output = NULL;
	new->childs = NULL;
	new->next = NULL;
	return new;
}

void add_cmd(t_cmds **cmds, t_cmds *cmd)
{
	t_cmds *aux;

	aux = *cmds;
	if (*cmds == NULL)
		*cmds = cmd;
	else
	{
		while (aux->next)
		{
			aux = aux->next;
		}
		aux->next = cmd;
	}
}
void add_child(t_cmds **cmds, t_cmds *cmd)
{
	t_cmds *child;

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
void print_cmds(t_cmds *cmds)
{
	int i;
	int spaces;
	int spaces_aux;
	int options;
	int j;

	i = 0;
	j = 0;
	printf("cmds:\n------------\n");
	while (cmds)
	{
		printf("	cmd%d:%s\n",j, cmds->cmd);
		options = 0;
		while (cmds->options[options])
		{
			printf("	opt(%d):%s\n", options, cmds->options[options]);
			options++;
		}
		spaces = 0;
		while (cmds->childs)
		{
			spaces_aux = 0;
			options = 0;
			while (spaces_aux < spaces)
			{
				printf("			");
				spaces_aux++;
			}
			printf("			child:%s\n", cmds->childs->cmd);
			while (cmds->childs->options[options])
			{
				printf("			opt(%d):%s\n", options, cmds->childs->options[options]);
				options++;
			}
			cmds->childs = cmds->childs->childs;
			spaces++;
		}
		cmds = cmds->next;
		j++;
	}
}

int parse_comands(t_data *d)
{
	char **splited;
	char **childs;
	int i;
	int j;

	t_cmds *first;
	d->cmds = NULL;
	i = 0;
	splited = ft_split_ms(d->raw_cmd, ';');
	while (splited[i])
	{
		childs = ft_split_ms(splited[i], '|');
		add_cmd(&d->cmds, new_cmd(ft_strdup(childs[0]),*d));
		if (i == 0)
			first = d->cmds;
		else
			d->cmds = d->cmds->next;
		j = 1;
		while (childs && childs[j])
		{
			add_child(&d->cmds->childs, new_cmd(ft_strdup(childs[j]),*d));
			j++;
		}
		ft_bi_free(childs);
		i++;
	}
	ft_bi_free(splited);
	d->cmds = first;
	//print_cmds(d->cmds);
	return 1;
}
