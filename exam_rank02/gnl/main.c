/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 21:11:36 by pablo             #+#    #+#             */
/*   Updated: 2020/12/13 21:52:29 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "get_next_line.h"

int
	main(void)
{
	int		r;
	char	*line;

	line = NULL;
	while ((r = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
    /*
	printf("%s", line);
	free(line);
    */
	line = NULL;
}