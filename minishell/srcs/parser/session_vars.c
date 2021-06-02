/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   session_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 09:54:36 by pablo             #+#    #+#             */
/*   Updated: 2021/06/02 10:53:20 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


t_session_v *new_session_var(char *name,char*value)
{
	t_session_v *res;

	res = malloc(sizeof(t_session_v));
	res->name = name;
	res->value = value;
	res->next = NULL;
}

void add_session_var(t_session_v *svars)
{
	int i;

	i = 0;
}


void get_session_var()
{

}

/*free*/
void clean_session_var()
{

}

