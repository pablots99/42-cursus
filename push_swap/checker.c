/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:47:40 by ptorres           #+#    #+#             */
/*   Updated: 2021/03/15 13:54:28 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int main(int argc, char**argv)
{
	int len_list;
	int i;
	
	i  = 0;
	if (argc > 1)
	{
		len_list = argc - 1;
		int nums[len_list];
		while (i < len_list)
		{
			nums[i] = ft_atoi(argv[i + 1]);
			printf("num:%d\n", nums[i]);
			i++;
		}
		
		printf("atgc:%d",argc);
	}
	else
	{
		write(1,"bad value of arguments",ft_strlen("bad value of arguments"));
		exit(1);
	}
	return 0;
}