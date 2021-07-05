/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:25:59 by pablo             #+#    #+#             */
/*   Updated: 2021/07/05 11:36:21 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_sstr_dup(char **sstr)
{
	char	**res;
	int		i;

	i = 0;
	res = malloc(ft_bi_strlen(sstr) + 1 * sizeof(char *));
	while (sstr[i])
	{
		res[i] = ft_strdup(sstr[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	ft_bi_free(char **arr)
{
	int	len;
	int	i;

	len = ft_bi_strlen(arr);
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
