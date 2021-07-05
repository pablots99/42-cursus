/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:03:32 by pablo             #+#    #+#             */
/*   Updated: 2021/07/06 01:42:34 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
# include "../libft/libft.h"
#include <sys/types.h>//fork ,
#include <readline/readline.h>
#include<readline/history.h>
 #include <fcntl.h>
#define ENVIROMENT_PATH "~/.mini_bashrc"

typedef struct s_session_v
{
	char *name;
	char *value;
	struct s_session_v *next;
}	t_session_v;

typedef struct s_cmds
{
	char *cmd;
	char **options;
	int var_asign;
	char *inputs;
	char *output;
	struct s_cmds *childs;
	struct s_cmds *next;
}	t_cmds;


typedef struct s_data
{
	char path[20000];
	char *raw_cmd;
	char **paths;
	int exit_code;
	t_cmds *cmds;
	t_session_v *session_v;
}	t_data;


int recive_comands(char **cmd);
void write_cwd(t_data d);
int parse_comands(t_data *d);
void execute_commands(t_data *d);
