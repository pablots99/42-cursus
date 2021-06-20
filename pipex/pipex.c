/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:09:47 by pablo             #+#    #+#             */
/*   Updated: 2021/06/18 15:26:42 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./srcs/pipex.h"

int saveCmds(char **args, t_pipex *p)
{

}


int executeCommands(char **args)
{
	t_pipex pipex;
	if(saveCmds(args,&pipex))
		return (1);
	return (1);
}


int main(int argc , char **argv)
{
	if(argc != 5)
	{
		write(1,"Arguments Error\n",ft_strlen("Arguments Error\n"));
		return (1);
	}
	else {
		if(executeCommands(argv))
		{
			write(1,"Command Error\n",ft_strlen("Command Error\n"));
			return (1);
		}
		return (0);
	}


}
