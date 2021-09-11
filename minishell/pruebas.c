/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:38:05 by ptorres           #+#    #+#             */
/*   Updated: 2021/09/11 22:10:07 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include <string.h>


int	is_in_str(char *s1,char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if ((s1[i] == 0  || s1[i] && "=") && s2[i] == 0)
		return (1);
	return (0);
}

int main(void)
{

	int res;

	res = 0;
	res = is_in_str("holaa qu tal=","holaa qu tal");
	printf("res:%d\n",res);
}