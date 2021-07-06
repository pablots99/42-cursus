/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:35:04 by pablo             #+#    #+#             */
/*   Updated: 2021/07/06 16:52:16 by pablo            ###   ########.fr       */
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


int main(int argc,char **ergv, char **env)
{
		char *str = "holasdkn ' '";
		printf("res: %d\n",is_quote_closed(str));
}
