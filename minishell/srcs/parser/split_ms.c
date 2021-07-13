/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_ms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:35:31 by pablo             #+#    #+#             */
/*   Updated: 2021/07/13 16:18:37 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


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

int parts_ms(char *str,char c)
{
	int i;
	int cond;
	char quote;
	int parts;


	i = 0;
	parts = 0;
	cond = 0;
	while (str[i])
	{
		if((str[i] == '"' || str[i] == '\'') && cond == 0)
		{
			quote = str[i];
			cond = 1;
		}
		else if(cond == 1 && str[i] == quote)
			cond = 0;
		if(!cond && str[i] == c)
		{
			parts++;
			while (str[i] && str[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (!cond && str[i - 1] != c)
		parts++;
	return (parts);
}

int	len_part2_ms(char *s, int i, char c)
{
	int	j;
	int cond;
	char quote;

	j = 0;
	cond = 0;
	while ((s[i] && s[i] != c && !cond) || (cond && s[i]))
	{
		if((s[i] == '"' || s[i] == '\'') && cond == 0)
		{
			quote = s[i];
			cond = 1;

		}
		// else if(cond == 1 && s[i] == quote)
		// 	cond = 0;
		i++;
		j++;
	}
	return (j);
}

char **ft_split_ms(char *s,char c)
{

	char	**res;
	int		len_parts;
	int		var[3];

	var[1] = -1;
	var[0] = 0;
	if (!s)
		return (NULL);
	len_parts = parts_ms(s, c);
	res = malloc((len_parts + 1) * sizeof(char *));
	while (var[1]++ < len_parts)
	{
		while (s[var[0]] && s[var[0]] == c)
			var[0]++;
		if (var[0] == (int)ft_strlen((char *)s))
			break ;
		var[2] = len_part2_ms((char *)s, var[0], c);
		res[var[1]] = malloc(var[2] * sizeof(char *));
		ft_strlcpy(res[var[1]], &s[var[0]], var[2] + 1);
		var[0] += var[2];
	}
	res[var[1]] = NULL;
	return (res);

}
