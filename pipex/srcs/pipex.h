/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:15:18 by pablo             #+#    #+#             */
/*   Updated: 2021/06/18 15:20:11 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



typedef struct s_pipex {
	char *infile;
	char *outfile;
	char *r_cmd1;
	char *r_cmd2;
	char **cmd1;
	char **cmd2;
}	t_pipex;


size_t	ft_strlen(char *str);
