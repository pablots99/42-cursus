/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:46:21 by ptorres           #+#    #+#             */
/*   Updated: 2020/10/21 18:23:09 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);

int		get_next_line(int fd, char **line);

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strcpy(char *dst, const char *src, size_t dstsize);

#endif
