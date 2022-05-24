/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:07:13 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/07 14:12:31 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr_fd(char *s, int fd, int *count)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr_fd("(null)", 1, count);
		return (i);
	}
	while (s[i])
	{
		write(fd, &s[i], 1);
		(*count)++;
		i++;
	}
	return (i);
}
