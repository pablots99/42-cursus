/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_qs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 20:38:29 by pablo             #+#    #+#             */
/*   Updated: 2021/05/03 21:13:02 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_b(t_qs *info, int len, int cond)
{
	int	i;
	int	moved;
	int	median;

	i = 0;
	moved = 0;
	median = stk_l_median(*(info)->a, len);
	if (len <= 1)
		return ;
	while (i++ < len)
	{
		if ((*(info)->a)->n < median)
			pb_n(info->a, info->b, &info->res);
		else
		{
			ra_n(info->a, &info->res);
			moved++;
		}
	}
	i = 0;
	while (i++ < moved && cond != 1)
		rra_n(info->a, &info->res);
	push_to_b(info, len / 2 + len % 2, cond);
	push_to_aa(info, len / 2);
}

int	clean_aux_aux(char **sp, char **res, int i)
{
	if ((ft_strncmp(sp[i], "ra", 2) == 0
			&& ft_strncmp(sp[i + 1], "rb", 2) == 0)
		|| (ft_strncmp(sp[i], "rb", 2) == 0
			&& ft_strncmp(sp[i + 1], "ra", 2) == 0))
	{
		*res = gn_ft_strjoin(*res, "rr\n");
		return (1);
	}
	if ((ft_strncmp(sp[i], "rrb", 3) == 0
			&& ft_strncmp(sp[i + 1], "rra", 3) == 0)
		|| (ft_strncmp(sp[i], "rra", 3) == 0
			&& ft_strncmp(sp[i + 1], "rrb", 3) == 0))
	{
		*res = gn_ft_strjoin(*res, "rrr\n");
		return (1);
	}
	return (0);
}

int	clean_aux(char **sp, char **res, int i)
{
	if ((ft_strncmp(sp[i], "ra", 2) == 0
			&& ft_strncmp(sp[i + 1], "rra", 3) == 0)
		|| (ft_strncmp(sp[i], "rb", 2) == 0
			&& ft_strncmp(sp[i + 1], "rrb", 3) == 0)
		|| (ft_strncmp(sp[i], "pa", 2) == 0
			&& ft_strncmp(sp[i + 1], "pb", 2) == 0)
		|| (ft_strncmp(sp[i], "rra", 3) == 0
			&& ft_strncmp(sp[i + 1], "ra", 2) == 0)
		|| (ft_strncmp(sp[i], "rrb", 3) == 0
			&& ft_strncmp(sp[i + 1], "rb", 2) == 0)
		|| (ft_strncmp(sp[i], "pb", 2) == 0
			&& ft_strncmp(sp[i + 1], "pa", 2) == 0))
		return (1);
	if (clean_aux_aux(sp, res, i))
		return (1);
	return (0);
}

char	*clean_qs(char **splited)
{
	int		i;
	char	*res;

	res = malloc(1);
	res[0] = 0;
	i = 0;
	while (splited[i + 1])
	{
		if (clean_aux(splited, &res, i))
		{
			i += 2;
			continue ;
		}
		res = gn_ft_strjoin(res, splited[i]);
		res = gn_ft_strjoin(res, "\n");
		i++;
	}
	res = gn_ft_strjoin(res, splited[i]);
	res = gn_ft_strjoin(res, "\n");
	return (res);
}

void	algorithm_3(t_stack a, t_stack b)
{
	t_qs	info;
	char	**splited;
	int		i;

	i = 0;
	info.a = &a;
	info.b = &b;
	info.res = malloc(1 * sizeof(char));
	info.res[0] = 0;
	push_to_b(&info, stk_len(a), 1);
	i = 0;
	while (i < 5)
	{
		splited = ft_split(info.res, '\n');
		info.res = clean_qs(splited);
		i++;
	}
	ft_putstr_fd(info.res, 1);
	free(info.res);
	stk_free(&a);
}
