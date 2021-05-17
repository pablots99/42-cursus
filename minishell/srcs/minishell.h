/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:03:32 by pablo             #+#    #+#             */
/*   Updated: 2021/05/17 16:58:53 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
# include "../libft/libft.h"
#include <sys/types.h>//fork , 


typedef struct s_cmds 
{ 
	char *cmd;
	char **args;
	struct s_cmds *childs;
	struct s_cmds *next;
}	t_cmds; 


typedef struct s_data
{
	char path[20000];
	char *cmd;
	t_cmds *cmds;
}	t_data;


int recive_comands(char **cmd);
void write_cwd(t_data d);
int parse_comands(t_data *d);
