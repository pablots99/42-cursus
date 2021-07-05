/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:15:18 by pablo             #+#    #+#             */
/*   Updated: 2021/07/05 12:00:51 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex {
	int		infile;
	int		outfile;
	char	***cmds;
	char	**paths;
	int		argc;
}	t_pipex;

size_t	ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_sstr_dup(char **sstr);
char	*ft_strdup(const char *s1);
void	ft_bi_free(char **arr);
int		saveCmds(char **args, t_pipex *p);
char	*get_cmd(t_pipex *p, char *cmd);
int		ft_bi_strlen(char **arr);
char	**get_paths(char **env);
int		free_struct(t_pipex *p);
void	close_fd(int i, int *fd[2], int argc);

#endif
