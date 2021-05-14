/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:03:32 by pablo             #+#    #+#             */
/*   Updated: 2021/05/14 13:55:33 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
# include "../libft/libft.h"
#include <sys/types.h>//fork , 




typedef struct s_data{
	char path[20000];
	char *cmd;
	t_list *cmds;
}	t_data;

typedef struct s_comands { 
	char *cmd;
	char **flags; // flgs y argumentos 
	char *output;
	t_list *childs; //childs are comands
}	t_commands; 

int recive_comands(char **cmd);
void write_cwd(t_data d);
int save_comands(t_data *d);
