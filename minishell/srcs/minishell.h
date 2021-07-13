/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:03:32 by pablo             #+#    #+#             */
/*   Updated: 2021/07/12 14:11:28 by pablo            ###   ########.fr       */
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
# include<readline/history.h>

# include <fcntl.h>
# include<signal.h>

# define ENVIROMENT_PATH "~/.mini_bashrc"

typedef struct s_session_v
{
	char				*name;
	char				*value;
	int					exp;
	struct s_session_v	*next;
}	t_session_v;

typedef struct s_cmds
{
	char			*cmd;
	char			**options;
	int				var_asign;
	char			*inputs;
	char			**outputs;
	int 			otput_fd;
	int				apppend;
	struct s_cmds	*childs;
	struct s_cmds	*next;
}	t_cmds;


typedef struct s_data
{
	char			path[20000];
	char			*raw_cmd;
	char			**paths;
	char			**env;
	int				first_env;
	int				exit_code;
	t_cmds			*cmds;
	t_session_v		*session_env;
	int				status;
}	t_data;


int recive_comands(char **cmd);
void write_cwd(t_data d);
int parse_comands(t_data *d);
void execute_commands(t_data *d);
void ft_bstrprint(char **bstr);
void set_env_ms(t_data *d,char *var,int env);
int ft_str_equal(char *s1, char *s2);
int is_asign(char *var);
void print_session_env(t_session_v *s);
char *get_session_env(t_data *d, char *name);
void add_session_env(t_data *d, char *cmd,int exp);
int is_quote_closed(char *input);
char **ft_split_ms(char *s,char c);
char *ft_append_char(char *str, char c);
char *get_env_ms(t_data *d,char* name);
void ft_bi_free_debug(char **arr);
void create_outputs(t_cmds *cmd);
void execute_pwd(t_data *d,int fd_out);
void execute_echo(t_cmds *cmd,int fd[2]);
void execute_cd(t_cmds *cmd, int fd[2]);
void unset_env(t_data *d,char *var_name);
void print_env(t_data *d,int  fd[2]);
void free_command(t_data *d);
void handle_sigint(int sig);
