/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recive_comands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:08:35 by ptorres           #+#    #+#             */
/*   Updated: 2021/07/06 00:44:52 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void write_cwd(t_data d)
{
	getcwd(d.path, sizeof(d.path));
	ft_putstr_fd(d.path,1);

}


