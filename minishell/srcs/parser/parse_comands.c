/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:41:03 by ptorres           #+#    #+#             */
/*   Updated: 2021/07/13 16:41:17 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_cmd_path(char *cmd, char **paths)
{
	int i;
	char *aux;
	int fd;

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

//ver si hay variables
char *find_vars(char *str, int c, t_data *d)

{
	char *new;
	char *var_value;
	int i;
	char *var_name;

	if (c)
		return (str);
	new = malloc(1*sizeof(char));
	new[0]=0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			var_name = malloc(1*sizeof(char));
			var_name[0]=0;
			i++;
			while (str[i] && (str[i] != ' ' && str[i] != '"' && str[i] != '\''))
			{
				var_name = ft_append_char(var_name,str[i]);
				i++;
			}
			if(str[i-1] == '?' && str[i-2] == '$')
					var_value = ft_itoa(d->status);
			else
				var_value = get_session_env(d,var_name);
			if(!var_value)
				var_value = get_env_ms(d,var_name);
			if(var_value)
			{
				ft_append(&new,var_value);
				free(var_value);
			}
			free(var_name);
			if(!(str[i]))
				break ;
		}
		new = ft_append_char(new,str[i]);
		i++;
	}
	new = ft_append_char(new,0);
	free(str);
	return new;
}


char **clean_splited(char **splited, t_data *d)
{
	char **res;
	int i;
	int no_vars;

	no_vars = 0;
	res = malloc((ft_bi_strlen(splited) + 1) * sizeof(char *));
	i = 0;
	while (splited[i])
	{
		if (splited[i][0] == '\'')
			no_vars = 1;
		res[i] = ft_clean_chars(splited[i],"\"\'");
		res[i] = find_vars(res[i], no_vars, d);
		i++;
	}
	res[i] = NULL;
	ft_bi_free(splited);
	return res;
}

char **parse_cmd(char *cmd,t_cmds *new, char **paths, t_data *d)
{
	char **splited;
	int len;
	char *ret;
	int i;

	splited = ft_split_ms(cmd, ' ');
	splited = clean_splited(splited, d);
	splited = redirections_out(d,new,splited);
	//splited = joined_redirections_out(d,new,splited); //joined redirections
	//splited = redirections_in(d,new,splited);
	//splited = joined_redirections_in
	len = ft_bi_strlen(splited);
	if (splited[0] && is_asign(splited[0]))
		new->var_asign = 1;
	else
		new->var_asign = 0;
	if (len > 0)
		ret = get_cmd_path(ft_strjoin("/", splited[0]), paths);
	else
		ret = NULL;
	new->cmd = ret;
	free(cmd);
	return splited;
}

t_cmds *new_cmd(char *cmd, t_data data)
{
	t_cmds *new;
	new = malloc(sizeof(t_cmds));
	new->apppend = -1;
	new->options = parse_cmd(cmd,new, data.paths, &data);
	new->inputs = NULL;
	new->childs = NULL;
	new->next = NULL;
	new->otput_fd = 0;
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
		printf("	cmd%d:%s\n", j, cmds->cmd);
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
		add_cmd(&d->cmds, new_cmd(ft_strdup(childs[0]), *d));
		if (i == 0)
			first = d->cmds;
		else
			d->cmds = d->cmds->next;
		j = 1;
		while (childs && childs[j])
		{
			add_child(&d->cmds->childs, new_cmd(ft_strdup(childs[j]), *d));
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
