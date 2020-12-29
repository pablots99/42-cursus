/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:46:21 by ptorres           #+#    #+#             */
/*   Updated: 2020/12/27 19:43:00 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define  BUFFER_SIZE  1

# include <stdlib.h>
# include <unistd.h>

size_t	fft_strlen(const char *s);

int		get_next_line(int fd, char **line);

char	*fft_strjoin(char const *s1, char const *s2);

size_t	fft_strcpy(char *dst, const char *src, size_t dstsize);

#endif
