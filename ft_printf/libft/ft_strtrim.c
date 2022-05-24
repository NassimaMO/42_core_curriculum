/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:44:37 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/04 14:05:27 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_try(char s, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s == set[i] || s == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	ft_fill2(char const *s1, char const *set, char *temp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (!ft_try(s1[i], set))
		{
			temp[j] = s1[i];
			j++;
		}
		i++;
	}
	temp[j] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		if (!ft_try(s1[j], set))
			i++;
		j++;
	}
	temp = malloc(sizeof(char) * i + 1);
	if (!temp)
		return (NULL);
	ft_fill2(s1, set, temp);
	return (temp);
}
/*
int	ft_try(char s, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s == set[i] || s == ' ')
			return (1);
		i++;
	}
	return (0);
}
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		if (!ft_try(s1[j], set))
			i++;
		j++;
	}
	temp = malloc(sizeof(char) * i + 1);
	if (!temp)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (!ft_try(s1[i], set))
		{
			temp[j] = s1[i];
			j++;
		}
		i++;
	}
	temp[j] = '\0';
	return (temp);
}*/