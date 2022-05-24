/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:43:14 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/04 15:14:03 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	long unsigned int	i;
	long int			d;

	i = 0;
	while (i < n)
	{
		if (((char *)s1)[i] < ((char *)s2)[i])
		{
			d = ((char *)s1)[i] - ((char *)s2)[i];
			if (d < 0)
				d = d * (-1);
			return (d);
		}
		else if (((char *)s1)[i] > ((char *)s2)[i])
		{
			d = ((char *)s1)[i] - ((char *)s2)[i];
			if (d > 0)
				d = d * (-1);
			return (d);
		}
		i++;
	}
	return (0);
}
