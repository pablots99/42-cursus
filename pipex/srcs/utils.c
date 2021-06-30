/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:14:26 by pablo             #+#    #+#             */
/*   Updated: 2021/06/30 20:12:12 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"


size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
	char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	ptr = (char *)malloc((ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (*s1 == '\0' || *s2 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (0);
}
int ft_bi_strlen(char **arr)
{
	int i;

	i = 0;
	while(arr[i])
		i++;
	return i;
}
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc((ft_strlen((char *)s1) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char **ft_sstr_dup(char **sstr)
{
	char **res;
	int i;

	i = 0;
	res = malloc(ft_bi_strlen(sstr) +1  * sizeof(char*));
	while(sstr[i])
	{
		res[i] = ft_strdup(sstr[i]);
		i++;
	}
	res[i] = NULL;
	return res;
}
void ft_bi_free(char **arr)
{
	int len;
	int	i;

	len = ft_bi_strlen(arr);
	i = 0;
	while (len != 1 && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}