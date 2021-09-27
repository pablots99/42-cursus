/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:37:40 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/27 14:40:39 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**dup_bi_string(char **str)
{
	int		i;
	char	**res;

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

int	ft_str_equal(char *s1, char *s2)
{
	int	i;
	int	len1;
	int	len2;

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

char	*ft_append_char(char *str, char c)
{
	char	*res;
	int		i;

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

char	**ft_append_string(char **str, char *s)
{
	char	**res;
	int		i;

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

void	create_output(t_cmds *cmd, char *str, int s, int d)
{
	int	fd;

	fd = 0;
	if (cmd->otput_fd != 0)
		close_fd(cmd->otput_fd);
	if (d)
		fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (s)
		fd = open(str, O_WRONLY | O_CREAT | O_APPEND, 0644);
	cmd->otput_fd = fd;
	if (str && str[0] != 0)
		free(str);
}
