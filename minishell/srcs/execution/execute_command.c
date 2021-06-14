/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:48:22 by pablo             #+#    #+#             */
/*   Updated: 2021/06/09 19:19:37 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"





void execute_commands(t_data *d)
{
	int i;
	char *argv[]={"ls",NULL};·
	printf("aaa\n");

	execve("/bin/ls",NULL,NULL);


}
