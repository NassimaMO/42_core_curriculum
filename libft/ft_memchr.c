/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:56:12 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/04 15:13:49 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	long unsigned int	i;

	i = 0;
	while (i != n)
	{
		if (((char *)s)[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
