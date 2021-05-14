/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:41:03 by ptorres           #+#    #+#             */
/*   Updated: 2021/05/14 14:03:54 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


///plantearse el hacerlo con arrays y no con listas!!!!!!!!!!!1
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int save_comands(t_data *d)
{
	char **spl;
	char **childs;
	int i;
	int j;
	t_commands cmd;
	t_commands child_cmd;

	i = 0;
	
	spl = ft_split(d->cmd,';');
	while(spl[i])
	{
		childs = ft_split(d->cmd,'|');
		cmd.cmd = childs[0];
		cmd.flags = NULL;
		cmd.output  = NULL;
		j = 0;
		while(childs[j])//puede dar segfault
		{
			child_cmd.cmd = childs[j];
			child_cmd.flags = NULL;
			child_cmd.output  = NULL;
			ft_lstadd_back(&cmd.childs,ft_lstnew((void *)&child_cmd));
			j++;
		}
		ft_lstadd_back(&d->cmds,ft_lstnew((void *)&cmd));
		i++;
	}
	ft_bi_free(spl);
	return 0;
}