/*
	EXAM RANK 04
	made by ptorres
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

typedef struct s_fd {
	int fd_in;
	int fd[2];
	int is_last;
	pid_t pid;
}    t_fd;


int ft_strlen(char *str){

	int i = 0;
	while(str &&str[i])
		i++;
	return (i);
}


void fd_putstr(int fd, char *str){
	write(fd,str,ft_strlen(str));
}

void error()
{
	printf("ERRNO: %d, %d\n",errno,errno == EBUSY);
	fd_putstr(2,"error: fatal\n");
	exit(1);
}

int execute_command(t_fd *fd, char **cmd, char **env,int cmd_count)
{
	int ret = 0;
	if(!*cmd)
		return 0;
	if(!fd->is_last){
		if(pipe(fd->fd) == -1)
			error();
	}
	fd->pid = fork();
	if(fd->pid < 0)
		error();
	if(fd->pid == 0)
	{
		if(!fd->is_last && dup2(fd->fd[1],1) ==  -1)
			error();
		if(dup2(fd->fd_in,0) == -1)
			error();
		if((ret = execve(cmd[0],cmd,env)) ==  -1)
		{
			fd_putstr(2,"error: cannot execute ");
			fd_putstr(2,cmd[0]);
			fd_putstr(2,"\n");
		}
		exit(ret);
	}
	else
	{
		waitpid(fd->pid,&ret,0);
		if(cmd_count != 0)
			close(fd->fd_in);
		if(!fd->is_last)
		{
			close(fd->fd[1]);
			fd->fd_in = fd->fd[0];
		}
	}
	return WEXITSTATUS(ret);
}

int execute_commands(t_fd *fd, char **argv,char **env){
	int i = 0;
	int ret  = 0;
	int start = 0;
	int cmd_count = 0;
	while(argv[i])
	{
		fd->is_last = 0;
		if(strcmp(argv[i],";") == 0)
			fd->is_last = 1;
		if(strcmp(argv[i],"|") == 0 || fd->is_last)
		{
			argv[i] = NULL;
			ret = execute_command(fd, argv + start,env,cmd_count);
			cmd_count++;
			start  = i + 1;
		}
		if(fd->is_last)
			cmd_count = 0;
		i++;
	}
	fd->is_last  = 1;
	ret = execute_command(fd, argv + start,env,cmd_count);
	return ret;
}


int main(int argc, char **argv,char **env)
{
	if(argc <= 1)
		return (0);
	t_fd fd;
	fd.fd[0] = 0;
	fd.fd[1] = 1;
	fd.fd_in = 0;
	return execute_commands(&fd,argv + 1, env);
}
