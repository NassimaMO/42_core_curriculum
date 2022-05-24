/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:44:04 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/04 15:08:52 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	long unsigned int	i;
	long unsigned int	d;

	d = 0;
	while (src[d])
		d++;
	if (size <= 0)
		return (d);
	i = 0;
	while (src[i] && i != size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (d);
}
