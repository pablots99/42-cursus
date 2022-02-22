/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:22:28 by pablo             #+#    #+#             */
/*   Updated: 2021/05/13 23:51:59 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t		ft_strlen(char *a);
char * ft_strcpy(char * dst, const char * src);
int ft_strcmp(const char *s1, const char *s2);
char * ft_strdup(const char *s1);

int main()
{
	char *a = "holaquetal";
	printf("FT_STRLEN!!!!\n");
	printf("	test1:\n");
	printf("		mine: %lu\n",ft_strlen(a));
	printf("		original: %lu\n",strlen(a));
	a = "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
	printf("	test2:\n");
	printf("		mine: %lu\n",ft_strlen(a));
	printf("		original: %lu\n",strlen(a));
	a = "";
	printf("	test3:\n");
	printf("		mine: %lu\n",ft_strlen(a));
	printf("		original: %lu\n",strlen(a));
	printf("FT_STRCPY!!!!\n");
	char *src = "hola";
	char *dest = malloc(100);
	printf("	mine:	 \n		ret:%s	dst:%s\n",ft_strcpy(dest,src),dest);
	printf("	original:\n		ret:%s	dst:%s\n",strcpy(dest,src),dest);
	printf("FT_STRCMP!!!!\n");
	printf("	mine:	 \n		ret:%d\n",ft_strcmp("aaalll","ajjj"));
	printf("	original:\n		ret:%d\n",strcmp("aaalll","ajjj"));
	printf("FT_STRCPY!!!!\n");
	printf("	mine:	 \n		ret:%s\n",ft_strdup("aaalll"));
}
