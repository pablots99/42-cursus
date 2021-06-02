/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 00:20:43 by pablo             #+#    #+#             */
/*   Updated: 2021/06/02 00:59:57 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_strpush(char ***bstr, char *str)
{
	int i;
	int len;
	char **aux;

	if(!*bstr)
	{
		*bstr = malloc(1*sizeof(char*));
		*bstr[0] = ft_strdup(str);
		return ;
	}
	len = ft_bi_strlen(*bstr);
	i = 0;
	printf("len:%d",len);

	aux = malloc((len + 1)* sizeof(char*));
	while(*bstr[i])
	{
		aux[i]=*bstr[i];
		i++;
	}
	aux[i] = str;
	ft_bi_free(*bstr);
	*bstr = aux;
}
