/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:35:19 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/04 13:44:21 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static void	ft_fill(char const *s1, char const *s2, char *temp)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		temp[i] = s2[j];
		i++;
		j++;
	}
	temp[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s1 && s2))
	{
		temp = malloc(1);
		if (!temp)
			return (NULL);
		temp[0] = 0;
		return (temp);
	}
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	j += i;
	temp = malloc(sizeof(char) * j + 1);
	if (!temp)
		return (NULL);
	ft_fill(s1, s2, temp);
	return (temp);
}
