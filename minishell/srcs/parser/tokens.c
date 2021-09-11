/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:30:19 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/11 14:47:22 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	find_quotes(char *str, t_parse *p,t_cmds *cmd)
{
	if (str[p->i] == '"' && !p->s_quote)
	{
		if (p->d_quote)
		{
			p->d_quote = 0;
			p->space = 1;
			cmd->comillas = 1;
		}
		else
			p->d_quote = 1;
		p->skip = 1;
	}
	if (p->var && (str[p->i] == ' ' || str[p->i] == '"' || str[p->i] == '\''))
		p->var_end = 1;
}

int	find_redir_out(char *str, t_parse *p, t_cmds *cmd)
{
	int	cond;

	cond = 0;
	if (str[p->i] == '>' && !p->d_quote && !p->s_quote)
	{
		if (str[p->i + 1] != '>' && str[p->i - 1] != '>')
		{
			p->so_redir = 1;
			p->space = 1;
			cmd->apppend = ft_append_char(cmd->apppend, '0');
		}
		else
		{
			p->do_redir++;
			p->space = 1;
			p->so_redir = 0;
			cmd->apppend = ft_append_char(cmd->apppend, '1');
		}
		cond = 1;
	}
	return (cond);
}

int	find_redir_in(char *str, t_parse *p)
{
	int	cond;

	cond = 0;
	if (str[p->i] == '<' && !p->d_quote && !p->s_quote)
	{
		if (str[p->i + 1] != '<' && str[p->i - 1] != '<')
			p->si_redir = 1;
		else
		{
			p->si_redir = 0;
			p->di_redir++;
		}
		p->space = 1;
		cond = 1;
	}
	return (cond);
}

int	find_parse_vars(char *str, t_parse *p)
{
	int	cond;

	cond = 0;
	if (str[p->i] == '$' && !p->s_quote
		&& str[p->i + 1] && str[p->i + 1] != ' ')
	{
		p->var = 1;
		p->skip = 1;
		p->i++;
		cond = 1;
	}
	else if ((str[p->i] == ' ' && !p->d_quote && !p->s_quote))
	{
		p->space = 1;
		cond = 1;
	}
	return (cond);
}

char	*find_vars(char *str, t_data *d)
{
	char	*var_value;

	if (str[0] == '?')
	{
		var_value = ft_itoa(d->status);
		if(str[1])
			var_value = ft_append_str(var_value,&str[1]);
	}
	else
		var_value = get_session_env(d, str);
	if (!var_value)
		var_value = get_env_ms(d, str);
	if (!var_value)
		return (NULL);
	return (var_value);
}
