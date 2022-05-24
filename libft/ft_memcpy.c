/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:30:45 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/04 15:03:20 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	long unsigned int	j;

	j = 0;
	while (j != n)
	{
		((char *)dest)[j] = ((char *)src)[j];
		j++;
	}
	return (dest);
}
