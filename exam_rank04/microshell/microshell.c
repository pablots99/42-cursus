
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
{
	int i = 0;
	while(str && str[i])
		i++;
	return (i);
}

int ft_b_strlen(char **str)
{
	int i = 0;
	while(str && str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	char *res;
	int i = 0;
	res = malloc((ft_strlen(str) + 1) * sizeof(char));
	while(str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

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
	char **new = malloc(len * sizeof(char *));
	while(i < len - 2)
	{
		new[i] = ft_strdup(cmd->args[i]);
		i++;
	}
	new[i] = ft_strdup(arg);
	new[i + 1] = NULL;
	if(cmd->args)
		free(cmd->args);
	cmd->args = new;
}



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
	
	fd[0] = 0;
	fd[1] = 1;
	while(cmds)
	{
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
	return (0);
}
