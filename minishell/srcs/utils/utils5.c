/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:42:58 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/13 15:57:17 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_in_str(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		if (s1[i] == '=' && s2[i] == '=')
			return (1);
		i++;
	}
	if ((s2[i] == 0 || s2[i] == '=') && s1[i] == 0)
		return (1);
	return (0);
}

int	ft_is_stralphanum(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]))
		return (0);
	while (str[i] && str[i] == '_')
		i++;
	while (str[i])
	{	
		if (!ft_isalnum(str[i]) || str[i] == '_')
		{
			if (str[i] != '=')
				return (0);
			else
				return (1);
		}
		i++;
	}
	return (1);
}

int	exists_env(t_data *d, char *var)
{
	int	i;

	i = 0;
	while (d->env[i])
	{
		if (_exists(var, d->env[i]))
			return (1);
		i++;
	}
	return (0);
}

void	init_status(t_cmds *cmd)
{
	int	i;

	i = 0;
	while (cmd->input_type && cmd->input_type[i])
	{
		if (cmd->input_type[i] == '1')
		{
			g_status = 2;
			return ;
		}
		i++;
	}
	g_status = 1;
}

char	**split_asign(char *str)
{
	char	**res;
	int		len;
	int		i;

	i = 2;
	res = ft_split(str, '=');
	if (!res)
		return (0);
	len = ft_bi_strlen(res);
	if (len > 2)
	{
		while (res[i])
		{
			res[1] = ft_append_char(res[1], '=');
			res[1] = ft_append_str(res[1], res[i]);
			free(res[i]);
			res[i] = NULL;
			i++;
		}
	}
	return (res);
}
