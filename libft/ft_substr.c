/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:29:09 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/04 13:35:05 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	ft_size(long unsigned int i, unsigned int start, size_t len)
{
	long unsigned int	size;

	if (len < i || start == len)
		size = len;
	else
		size = i - (long unsigned int)start;
	return (size);
}

char	*ft_error(void)
{
	char				*temp;

	temp = malloc(1);
	if (!temp)
		return (NULL);
	temp[0] = '\0';
	return (temp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*temp;
	long unsigned int	i;
	long unsigned int	j;

	i = 0;
	while (s[i])
		i++;
	if (start > i || len == 0)
		return (ft_error());
	temp = malloc(sizeof(char) * (ft_size(i, start, len) + 1));
	if (!temp)
		return (NULL);
	i = 0;
	j = start;
	while (j < (len + start) && s[j])
	{
		temp[i] = ((char *)s)[j];
		j++;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*temp;
	long unsigned int	i;
	long unsigned int	j;
	long unsigned int	size;

	i = 0;
	while (s[i])
		i++;
	if (start > i || len < start || len == 0)
	{
		temp = malloc(1);
		temp[0] = '\0';
		return (temp);
	}
	if (len < i || start == len)
		size = len;
	else
		size = i - (long unsigned int)start;
	temp = malloc(sizeof(char) * (size + 1));
	if (!temp)
		return (NULL);
	i = 0;
	j = start;
	while (j < (len + start) && s[j])
	{
		temp[i] = ((char *)s)[j];
		j++;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}*/