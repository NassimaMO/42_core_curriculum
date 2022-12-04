/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:10:29 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/04 13:10:32 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_pos(t_list **lst)
{
	t_list	*tmp;
	int		i;

	tmp = *lst;
	i = 0;
	while (tmp)
	{
		tmp->content->pos = i++;
		tmp = tmp->next;
	}
}

static int	verif_double(char **argv, int argc, int i, int x)
{
	int		n;
	char	**tab_tmp;
	int		num;
	int		w;

	n = 0;
	tab_tmp = ft_split(argv[i], ' ');
	num = ft_atoi(tab_tmp[x]);
	free_tab(tab_tmp);
	while (++n < argc)
	{
		tab_tmp = ft_split(argv[n], ' ');
		w = -1;
		while (tab_tmp[++w])
		{
			if (n != i && x != w && ft_atoi(tab_tmp[w]) == num)
				return (free_tab(tab_tmp), 1);
		}
		free_tab(tab_tmp);
	}
	return (0);
}

int	number_checker(char **argv, int argc)
{
	int				i;
	int				j;
	int				x;
	long long int	nbr;
	char			**tab_tmp;

	i = 0;
	while (++i < argc)
	{
		x = 0;
		j = 0;
		if (!argv[i][j])
			return (0);
		tab_tmp = ft_split(argv[i], ' ');
		while (tab_tmp[x] && tab_tmp[x][j])
		{
			if (!(tab_tmp[x][j] >= '0' && tab_tmp[x][j] <= '9') && \
				!(tab_tmp[x][j] == '-' && j == 0 && tab_tmp[x][j + 1]) && \
				!(tab_tmp[x][j] == '+' && j == 0 && tab_tmp[x][j + 1]))
				return (free_tab(tab_tmp), 0);
			j++;
			if (!tab_tmp[x][j])
			{
				nbr = ft_atoi(tab_tmp[x]);
				if (nbr > INT_MAX || nbr < INT_MIN || \
					verif_double(argv, argc, i, x))
					return (free_tab(tab_tmp), 0);
				x++;
				j = 0;
			}
		}
		free_tab(tab_tmp);
	}
	if (argc <= 2)
		return (0);
	return (1);
}
