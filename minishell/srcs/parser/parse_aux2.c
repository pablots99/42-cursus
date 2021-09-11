/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_aux2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:25:36 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/12 00:58:51 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	save_first_cmd(t_data *d, char **str, t_cmds **cmd)
{
	(*cmd)->cmd = get_cmd_path(*str, d->paths);
	(*cmd)->options = ft_append_string((*cmd)->options, *str);
}

void	save_pipe(t_data *d, t_cmds **cmd, t_parse *p)
{
	int	aux;

	(*cmd)->var_asign = 0;
	if ((*cmd)->cmd && is_asign((*cmd)->cmd) && ft_is_stralphanum((*cmd)->cmd))
		(*cmd)->var_asign = 1;
	add_child(&d->cmds, *cmd), *cmd = new_cmd();
	aux = p->i;
	*p = init_parse();
	p->i = aux;
}

void	add_child(t_cmds **cmds, t_cmds *cmd)
{
	t_cmds	*child;

	if (!cmds || !cmd)
		return ;
	child = *cmds;
	if (*cmds == NULL)
		*cmds = cmd;
	else
	{
		while (child->childs)
		{
			child = child->childs;
		}
		child->childs = cmd;
	}
}
