/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:41:03 by ptorres           #+#    #+#             */
/*   Updated: 2021/06/02 11:50:33 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

///plantearse el hacerlo con arrays y no con listas!!!!!!!!!!!1
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
char *parse_cmd(char *cmd, int *assign)
{
	char **splited;
	int len;
	char *ret;
	int i;

	splited = ft_set_split(cmd, " 	");
	len = ft_bi_strlen(splited);
	if (len >= 2 && splited[1] == '=')
		*assign = 1;
	else
		*assign = 0;
	if (len > 0)
		ret = ft_strdup(splited[0]);
	else
		ret = NULL;
	ft_bi_free(splited);
	return ret;
}
char **parse_options(char *cmd)
{
	char **splited;
	int i;
	int len;
	char **res;

	len = 0;
	i = 0;
	splited = ft_set_split(cmd, " 	");
	while (splited[i])
	{
		if (splited[i][0] == '-')
			len++;
		i++;
	}
	res = malloc((len +1) * sizeof(char *));
	if (!res)
		return NULL;
	i = 0;
	len = 0;
	while (splited[i])
	{
		if (splited[i][0] == '-')
		{
			res[len] = ft_strdup(splited[i]);
			len++;
		}
		i++;
	}
	res[len] = NULL;
	ft_bi_free(splited);
	return res;
}
char **parse_input(char *cmd)
{
}
t_cmds *new_cmd(char *cmd)
{
	t_cmds *new;

	new = malloc(sizeof(t_cmds));
	new->cmd = parse_cmd(cmd, &new->var_asign);
	new->options = parse_options(cmd);
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

	i = 0;
	printf("cmds:\n------------\n");
	while (cmds)
	{
		printf("	cmd:%s\n", cmds->cmd);
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
	splited = ft_split(d->raw_cmd, ';');
	while (splited[i])
	{
		childs = ft_split(splited[i], '|');				  //separe comands all besides the first are childs
		add_cmd(&d->cmds, new_cmd(ft_strdup(childs[0]))); //add to the main list the command the null are the args
		if (i == 0)
			first = d->cmds;
		else
			d->cmds = d->cmds->next;
		j = 1;
		while (childs && childs[j]) //fill the same way the childs with the rest recursivity??????
		{
			add_child(&d->cmds->childs, new_cmd(ft_strdup(childs[j])));
			j++;
		}
		i++;
	}
	d->cmds = first;
	print_cmds(d->cmds);
	return 0;
}
