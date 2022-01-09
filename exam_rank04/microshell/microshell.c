<<<<<<< HEAD
	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:52:58 by pablo             #+#    #+#             */
/*   Updated: 2021/12/30 00:04:07 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct s_cmd {
	char **args;
	int last;
	struct s_cmd *next;
}				t_cmd;


int ft_b_strlen(char **str)
=======

/*
 * made by ptorres
 * microshell
 *
 * */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_cmd { 
	char **args;
	int is_last;
	struct s_cmd *next; 
}	t_cmd;


int ft_strlen(char *str)
>>>>>>> 6d87d6dc50f8fb37c412f8562e6252d5bbba0202
{
	int i = 0;
	while(str && str[i])
		i++;
	return (i);
}

<<<<<<< HEAD
int ft_strlen(char *str)
=======
int ft_b_strlen(char **str)
>>>>>>> 6d87d6dc50f8fb37c412f8562e6252d5bbba0202
{
	int i = 0;
	while(str && str[i])
		i++;
	return (i);
}

<<<<<<< HEAD
void add_cmd(t_cmd **cmd, t_cmd *new)
{
	t_cmd *aux = *cmd;
	if(*cmd == NULL)
		*cmd = new;
	else {
		while(aux->next != NULL)
			aux = aux->next;
		aux->next = new;
	}
}

char * ft_strdup(char *str)
{
	char *res;
	int len =  ft_strlen(str);
	int i = 0;
	res = malloc((len + 1) * sizeof(char));
	while(i < len)
=======
char *ft_strdup(char *str)
{
	char *res;
	int i = 0;
	res = malloc((ft_strlen(str) + 1) * sizeof(char));
	while(str[i])
>>>>>>> 6d87d6dc50f8fb37c412f8562e6252d5bbba0202
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

<<<<<<< HEAD
void add_arg(t_cmd *cmd, char *arg)
{
	int i = 0;
	int len = ft_b_strlen(cmd->args) + 2;
=======
void add_cmd(t_cmd **cmd, t_cmd *new)
{
	t_cmd *aux;
	aux = *cmd;
	if(*cmd == NULL)
		*cmd = new;
	else {
		while(aux->next != NULL)
			aux = aux->next;
		aux->next = new;
	}
}

void add_arg(t_cmd *cmd, char *arg)
{
	int len = ft_b_strlen(cmd->args) + 2;
	int i = 0;
>>>>>>> 6d87d6dc50f8fb37c412f8562e6252d5bbba0202
	char **new = malloc(len * sizeof(char *));
	while(i < len - 2)
	{
		new[i] = ft_strdup(cmd->args[i]);
		i++;
	}
<<<<<<< HEAD
	new[i] = arg;
=======
	new[i] = ft_strdup(arg);
>>>>>>> 6d87d6dc50f8fb37c412f8562e6252d5bbba0202
	new[i + 1] = NULL;
	if(cmd->args)
		free(cmd->args);
	cmd->args = new;
}

<<<<<<< HEAD
t_cmd *save_cmds(char **argv)
{
	t_cmd *res;
	t_cmd *aux;
	int i = 0;
	res = NULL;
	aux = malloc(1 * sizeof(t_cmd));
	aux->args = NULL;
	aux->next = NULL;
	while(argv[i])
	{
		if(!argv[i] || strcmp(argv[i], ";") == 0)
			aux->last = 1;
		else
			aux->last = 0;
		if(strcmp(argv[i], ";") == 0 || strcmp(argv[i], "|") == 0)
		{
			add_cmd(&res, aux);
			aux = NULL;
			aux = malloc(1 * sizeof(t_cmd));
			aux->args = NULL;
			aux->next = NULL;
		}
		else
			add_arg(aux,argv[i]);
		i++;
	}
	aux->last = 1;
	add_cmd(&res, aux);
	return res;
}

void print_err(char *err, char *var)
{
	write(1,err,ft_strlen(err));
	write(1,var,ft_strlen(var));
	write(1,"\n",1);
}

int execute_cd(t_cmd *cmd)
{
	if(strcmp(cmd->args[0],"cd") == 0)
	{
		if(!cmd->args[1])
		{
			write(1,"error: cd: bad arguments\n",ft_strlen("error: cd: bad arguments\n"));
		}
		else
			chdir(cmd->args[1]);
		return (1);
	}
	return 0;
}

void execute_commands(t_cmd * cmds,char **env)
{
	int status = 0;
	int pid;
	int err;
	int fd_in;
	int fd[2];
	int i = 0;

	fd_in = 0;
=======


t_cmd * save_cmd(char **argv)
{
	t_cmd *res;
	t_cmd *new;
	int i = 0;
	res = NULL;
 	new = malloc(sizeof(t_cmd));
	new->args = NULL;
	new->next = NULL;
	while(argv[i])
	{
		if(strcmp(argv[i],";") == 0)
			new->is_last = 1;
		else
			new->is_last = 0;
		if((strcmp(argv[i],";") == 0) || strcmp(argv[i],"|") == 0)
		{
			add_cmd(&res,new);
			new = malloc(sizeof(t_cmd));
			new->args = NULL;
			new->next = NULL;
		}
		else 
			add_arg(new,argv[i]);
		i++;
	}
	new->is_last = 1;
	add_cmd(&res,new);
	return res;
}

int execute_commands(t_cmd *cmds, char **env)
{
	int i = 0;
	int fd_in = 0;
	int fd[2];
	int err = 0;
	int pid = 0;
	
>>>>>>> 6d87d6dc50f8fb37c412f8562e6252d5bbba0202
	fd[0] = 0;
	fd[1] = 1;
	while(cmds)
	{
<<<<<<< HEAD
		if(cmds->args && !execute_cd(cmds))
		{
			if(!cmds->last)
				pipe(fd);
			pid = fork();
			if(pid == 0)
			{
				dup2(fd_in,0);
				if(!cmds->last)
					dup2(fd[1],1);
				if((err = execve(cmds->args[0],cmds->args,env)) == -1)
				{
					print_err("error: cannot execute ",cmds->args[0]);
					exit(err);
				}
			}
			else
			{
				if(fd_in)
					close(fd[0]);
				if(fd[1] != 1)
					close(fd[1]);
				fd_in = fd[0];
			}
			i++;
		}
		cmds = cmds->next;
	}
	while(i--)
		wait(&status);
}


int main(int argc, char **argv, char **env)
{
	if(argc <= 1)
		return (0);
	t_cmd *cmds = save_cmds(argv + 1);
	execute_commands(cmds, env);
=======
		if(cmds->is_last == 0)
			pipe(fd);
		pid = fork();
		if(pid == 0)
		{
			dup2(fd_in,0);
			if(cmds->is_last == 0)
				dup2(fd[1],1);
			if((err = execve(cmds->args[0],cmds->args,env)) == -1)
			{
				write(1,"error: ",7);
				write(1, cmds->args[0],ft_strlen(cmds->args[0]));
				write(1,"\n",1);
				exit(err);
			}

		}
		else {
			if(fd_in)
				close(fd_in);
			if(fd[1] != 1)
				close(fd[1]);
			fd_in = fd[0];
		}
		i++;
		cmds = cmds->next;
	}
	waitpid(pid,NULL,WUNTRACED);
	return 0;
}

int main(int argc, char **argv, char **env)
{
	t_cmd *cmds;

	if(argc <= 1)
		return (0);
	cmds = save_cmd(argv+ 1);
	execute_commands(cmds,env);
>>>>>>> 6d87d6dc50f8fb37c412f8562e6252d5bbba0202
	return (0);
}
