/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:35:08 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/03 16:44:34 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void				*temp;
	long unsigned int	i;

	i = 0;
	if (!nmemb || !size || (size == SIZE_MAX && nmemb == SIZE_MAX))
		return (NULL);
	temp = malloc(nmemb * size);
	if (!temp)
		return (NULL);
	while (i != nmemb * size)
	{
		((char *)temp)[i] = 0;
		i++;
	}
	return (temp);
}
