/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:41:03 by ptorres           #+#    #+#             */
/*   Updated: 2021/05/17 19:35:29 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


///plantearse el hacerlo con arrays y no con listas!!!!!!!!!!!1
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

t_cmds *new_cmd(char *cmd,char **args)
{
	t_cmds *new;
	new = malloc(sizeof(t_cmds));
	new->cmd = cmd;
	new->args = args;
	new->childs = NULL;
	new->next = NULL;
	return new;
}
void add_cmd(t_cmds **cmds,t_cmds *cmd)
{
	t_cmds *aux;

	aux = *cmds;
	if(*cmds == NULL)
		*cmds = cmd;
	else{
		while(aux->next)
		{
			aux = aux->next;
		}
		aux->next = cmd;
	}
}
void add_child(t_cmds **cmds,t_cmds *cmd)
{
	t_cmds *child;

	child = *cmds;
	if(*cmds == NULL)
		*cmds = cmd;
	else{
		while(child->childs)
		{
			child = child->childs;
		}
		child->childs = cmd;
	}
}


void print_cmds(t_cmds *cmds)
{
	int i;

	i = 0;
	printf("cmds:\n------------\n");
	while (cmds)
	{
		printf("	cmd:%s\n",cmds->cmd);
		while(cmds->childs)
		{
			printf ("			child:%s\n",cmds->childs->cmd);
			cmds->childs = cmds->childs->childs;
		}
		cmds = cmds->next;
	}
}


int parse_comands(t_data *d)
{
	char **splited;
	char **args;
	char **args_aux;
	char **childs;
	int i;
	int j;
	
	d->cmds = NULL;
	i = 0;
	splited = ft_split(d->cmd,';');
	while (splited[i])
	{
		childs = ft_split(splited[i],'|');//separe comands all besides the first are childs 
		args = ft_split(childs[i],' ');// separe the arguments of the commands more comple function needed
		add_cmd(&d->cmds, new_cmd(ft_strdup(*args),NULL)); //add to the main list the command the null are the args
		while (childs[j])	//fill the same way the childs with the rest recursivity??????
		{
			add_child(&d->cmds->childs, new_cmd(ft_strdup(childs[j]),NULL));
			j++;
		}
		
		ft_bi_free(args);
		i++;
	}
	
	print_cmds(d->cmds);
	return 0;
}