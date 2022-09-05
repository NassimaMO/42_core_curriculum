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
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dest)
		return (len_src + size);
	j = 0;
	while (src[j] && len_dest + j < size - 1)
	{
		dst[len_dest + j] = src[j];
		j++;
	}
	dst[len_dest + j] = '\0';
	return (len_dest + len_src);
}
