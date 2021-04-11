/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:46:21 by ptorres           #+#    #+#             */
/*   Updated: 2021/04/09 17:33:21 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t	gn_ft_strlen(const char *s);

int		get_next_line(int fd, char **line);

char	*gn_ft_strjoin(char const *s1, char const *s2);

size_t	gn_ft_strcpy(char *dst, const char *src, size_t dstsize);

#endif
