/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:35:04 by pablo             #+#    #+#             */
/*   Updated: 2021/07/07 20:37:55 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include "../libft/libft.h"
# include <sys/types.h>//fork ,
# include <readline/readline.h>
# include<readline/history.h>
# include <fcntl.h>
# define ENVIROMENT_PATH "~/.mini_bashrc"






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
		if(input[i] == '"' || input[i] == '\'' && cond == 0)
		{
			quote = input[i];
			cond = 1;
		}
		if(cond == 1 && input[i] == quote)
			cond = 0;
		i++;
	}
	if(cond)
		return (0);
	return (1);
}
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if(!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
int ft_str_equal(char *s1, char *s2)
{
	int i;
	int len1;
	int len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	printf("len1:%d,len2:%d\n",len1,len2);
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


int main(int argc,char **ergv, char **env)
{
		printf("res; %d\n",ft_str_equal("LESS","hola"));
}
