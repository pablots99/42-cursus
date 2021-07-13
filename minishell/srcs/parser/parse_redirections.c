/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:26:44 by ptorres           #+#    #+#             */
/*   Updated: 2021/07/13 15:53:26 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int count_redirections(char **s, t_cmds *cmd)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((ft_str_equal(s[i], ">") && s[i + 1]))
			cmd->apppend = 0, count += 2;
		else if ((ft_str_equal(s[i], ">>") && s[i + 1]))
			cmd->apppend = 1, count += 2;
		i++;
	}
	return (count);
}

char **redirections_out(t_data *d, t_cmds *cmd, char **s)
{
	int i;
	int j;
	int k;
	int red;
	char **res;

	i = 0;
	j = 0;
	k = 0;
	red = count_redirections(s, cmd);
	if (red)
		cmd->outputs = malloc(((red / 2 + red % 2) + 1) * sizeof(char *));
	res = malloc(((ft_bi_strlen(s) - (red)) + 1) * sizeof(char *));
	while (s[i])
	{
		if (ft_str_equal(s[i], ">") && s[i + 1])
			cmd->outputs[j] = ft_strdup(s[i + 1]), j++, i++;
		else if (ft_str_equal(s[i], ">>") && s[i + 1])
			cmd->outputs[j] = ft_strdup(s[i + 1]), j++, i++;
		else
			res[k] = ft_strdup(s[i]), k++;
		i++;
	}
	if (!red)
		cmd->outputs = NULL;
	else
		cmd->outputs[j] = NULL;
	res[k] = NULL;
	ft_bi_free(s);
	return (res);
}

int has_redirections(char *s)
{
	int i;

	i = 0;
	if(!s || !*s)
		return (0);
	while (s[i] && (s[i] != '>' ||  (( s[i] && s[i + 1]) && (s[i] != '>' && s[i + 1] != '>'))))
	{
		if(!s[i+1])
			break ;
		i++;
	}
	return (i);
}

int count_joined(char **s, t_cmds *cmd)
{
	int i;
	int count;
	int v;

	count = 0;
	i = 0;

	while (s[i])
	{
		v = has_redirections(s[i]);
		if (v && s[i][v + 1] && s[i][v + 1] == '>')
		{
			cmd->apppend = 1;
			count++;
		}
		else if (s[i][v] && s[i][v] == '>')
		{
			cmd->apppend = 0;
			count++;
		}
		i++;
	}
	return (count);
}

char **joined_redirections_out(t_data *d, t_cmds *cmd, char **s)
{
	int i;
	char **res;
	int r;
	int j;

	r = count_joined(s, cmd);
	if (!r)
		return (s);
	cmd->outputs = malloc((r + 1) * sizeof(char *));
	i = 0;
	j  = 0;
	res = malloc((ft_bi_strlen(s) + r + 1) * sizeof(char *));
	while (s[i])
	{
		r = has_redirections(s[i]);
		if (s[i][r + 1] && s[i][r + 1] == '>')
		{
			if (s[i][r + 2])
			{
				res[i] = ft_substr(s[i], 0, r);
				cmd->outputs[j] = ft_substr(s[i], r + 2, ft_strlen(s[i]));
				j++;
			}
			i++;
		}
		else if (r)
		{
			if (s[i][r + 1] != 0)
			{
				printf("c:%c\n",s[i][r + 1]);
				printf("substr: %s,j:%d\n",ft_substr(s[i], r + 1, ft_strlen(s[i])),j);
				res[i] = ft_substr(s[i], 0, r);
				cmd->outputs[j] = ft_substr(s[i], r + 1, ft_strlen(s[i]));
				j++;
			}
			i++;
		}
		else if (s[i])
		{
			res[i] = ft_strdup(s[i]);
		}
		i++;
	}
	return (res);
}
