/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:37:58 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/12 00:43:45 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(char *cmd)
{
	if (ft_str_equal(cmd, "cd"))
		return (1);
	if (ft_str_equal(cmd, "exit"))
		return (1);
	if (ft_str_equal(cmd, "export"))
		return (1);
	if (ft_str_equal(cmd, "unset"))
		return (1);
	if (ft_str_equal(cmd, "echo"))
		return (1);
	if (ft_str_equal(cmd, "pwd"))
		return (1);
	if (ft_str_equal(cmd, "set"))
		return (1);
	if (ft_str_equal(cmd, "export"))
		return (1);
	return (0);
}

int	is_exportable(t_data *d, char *asignation)
{
	int		i;
	char	*aux;

	i = 0;
	aux = add_export_aux(asignation);
	while (d->exportables[i])
	{
		if (is_in_str(d->exportables[i],aux))
		{
			free(d->exportables[i]);
			d->exportables[i] = ft_strdup(aux);
			free(aux);
			return (1);
		}
		i++;
	}
	free(aux);
	return (0);
}

int	is_asign(char *var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (var[i] == '=' && i != 0)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_append_str(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2 && s2[i])
	{
		s1 = ft_append_char(s1, s2[i]);
		i++;
	}
	return (s1);
}

void	free_command(t_data *d)
{
	t_cmds	*aux;

	while (d->cmds != NULL)
	{
		free(d->cmds->cmd);
		ft_bi_free(d->cmds->options);
		if (d->cmds->apppend)
			free(d->cmds->apppend);
		if (d->cmds->input_type)
			free(d->cmds->input_type);
		if (d->cmds->input_fds)
			ft_bi_free(d->cmds->input_fds);
		aux = d->cmds;
		d->cmds = d->cmds->childs;
		free(aux);
	}
}
