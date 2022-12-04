/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:09:58 by nmouslim          #+#    #+#             */
/*   Updated: 2022/12/04 13:10:00 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_num_param(char **argv, int argc)
{
	char	**tab_tmp;
	int		i;
	int		w;
	int		count;

	i = 0;
	count = 0;
	while (++i < argc)
	{
		tab_tmp = ft_split(argv[i], ' ');
		w = -1;
		while (tab_tmp[++w])
			count++;
		free_tab(tab_tmp);
	}
	return (count);
}

int	*put_int_tab(char **argv, int argc)
{
	int		*a;
	int		i;
	int		j;
	int		w;
	char	**tab_tmp;

	i = 0;
	j = -1;
	a = malloc(sizeof(int) * get_num_param(argv, argc));
	if (!a)
		exit(1);
	while (++i < argc)
	{
		tab_tmp = ft_split(argv[i], ' ');
		w = -1;
		while (tab_tmp[++w])
			a[++j] = ft_atoi(tab_tmp[w]);
		free_tab(tab_tmp);
	}
	return (a);
}

void	free_tab(char **tab_tmp)
{
	int	i;

	i = 0;
	while (tab_tmp[i])
		free(tab_tmp[i++]);
	free(tab_tmp);
}
