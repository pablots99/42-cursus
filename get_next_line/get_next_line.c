/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:06:21 by pablo             #+#    #+#             */
/*   Updated: 2021/04/09 17:32:55 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_line(char *buffer)
{
	int i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	return (buffer[i] == '\n') ? 1 : 0;
}

char	*fill_line(char *excess, char **line)
{
	int		i;
	char	*res;

	i = 0;
	if (!excess)
		return (0);
	while (excess[i] && excess[i] != '\n')
		i++;
	if (!(*line = malloc(sizeof(char) * (i + 1))))
		return (0);
	gn_ft_strcpy(*line, excess, i);
	if (excess[i] == 0)
	{
		free(excess);
		return (0);
	}
	if (!(res = malloc(sizeof(char) * ((gn_ft_strlen(excess) - i) + 1))))
		return (0);
	gn_ft_strcpy(res, &excess[i + 1], gn_ft_strlen(&excess[i + 1]));
	free(excess);
	return (res);
}

int		get_next_line(int fd, char **line)
{
	static char	*excess;
	int			bytes;
	char		*buffer;

	bytes = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!is_line(excess) && bytes != 0 &&
			(bytes = read(fd, buffer, BUFFER_SIZE)) != -1)
	{
		buffer[bytes] = '\0';
		excess = gn_ft_strjoin(excess, buffer);
	}
	free(buffer);
	excess = fill_line(excess, line);
	if (bytes == -1)
		return (-1);
	return ((bytes == 0) ? 0 : 1);
}
