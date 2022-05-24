/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:54:32 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/03 15:09:23 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_dest;
	unsigned int	len_src;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	len_dest = i;
	while (src[j])
		j++;
	len_src = j;
	if ((unsigned int)size < len_dest || (unsigned int)size == 0)
		return (len_src + (unsigned int)size);
	j = 0;
	while (src[j] != '\0' && i < (unsigned int)size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_dest + len_src);
}
