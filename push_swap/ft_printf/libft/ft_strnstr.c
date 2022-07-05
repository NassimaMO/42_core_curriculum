/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:01:23 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/04 15:14:21 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static int	ft_ftt(const char *big, const char *little, size_t len, \
									long unsigned int *i)
{
	long unsigned int	j;
	long unsigned int	temp;

	j = 0;
	temp = *i;
	while (little[j])
	{
		if (little[j] != big[(*i)] || (*i) >= len)
		{
			(*i) = temp;
			return (j);
		}
		j++;
		(*i)++;
	}
	return (j);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	long unsigned int	i;
	long unsigned int	temp;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i] && i <= len)
	{
		if (big[i] == little[0])
		{
			temp = i;
			if (ft_ftt(big, little, len, &i) == \
				ft_strlen(little) && ft_strlen(big) == ft_strlen(little))
				return (((char *)big) + temp);
		}
		i++;
	}
	return (NULL);
}
