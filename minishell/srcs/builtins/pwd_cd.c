/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:07:16 by pablo             #+#    #+#             */
/*   Updated: 2021/09/12 20:06:53 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_pwd(t_data *d)
{
	ft_putstr_fd(d->path, 1);
	ft_putchar_fd('\n', 1);
	exit(0);
}

int	is_err(t_cmds *cmd, int *err)
{
	if (cmd->options[1])
		*err = chdir(cmd->options[1]);
	if (*err)
	{
		ft_putstr_fd("minishel: cd: ", 2);
		ft_putstr_fd(cmd->options[1], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
		return (1);
	}
	return (0);
}

void	aux_cd(char **new_pwd, char **old_pwd, t_data *d)
{
	*new_pwd = ft_strjoin("PWD=", getcwd(d->path, sizeof(d->path)));
	set_env_ms(d, *new_pwd, 0);
	set_env_ms(d, *old_pwd, 0);
	free(*old_pwd);
	free(*new_pwd);
	d->status = 0;
}

void	execute_cd(t_cmds *cmd, t_data *d, int x)
{
	int		err;
	char	*old_pwd;
	char	*new_pwd;
	char	*aux;

	err = 0;
	old_pwd = ft_strjoin("OLDPWD=", getcwd(d->path, sizeof(d->path)));
	if (!cmd->options[1] || ft_str_equal(cmd->options[1], "~"))
	{	
		aux = get_env_ms(d, "HOME");
		printf("aux:%s\n", aux);
		err = chdir(aux), free(aux);
	}
	else if (is_err(cmd, &err))
	{
		d->status = 1;
		if (x)
			exit(1);
		free(old_pwd);
	}
	else
		aux_cd(&new_pwd, &old_pwd, d);
	if (x)
		exit(0);
}
