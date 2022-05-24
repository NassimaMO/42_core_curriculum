/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:12:49 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/07 14:13:54 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar(char c, int *i, int *j, int p)
{
	if (p)
	{
		write(1, &c, 1);
		(*i)++;
	}
	(*j)++;
}

void	ft_ft(long long int n, int *i, int *c, int p)
{
	long long int	nbr;
	nbr = n;

	if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + 48, i, c, p);
	if (nbr > 9)
	{
		ft_ft(nbr / 10, i, c, p);
		nbr = nbr % 10;
		ft_putchar(nbr + 48, i, c, p);
	}
}

int	ft_putnbr_fd(long long int n, int *i, int p, int m)
{
	long long int	nbr;
	int c;

	c = 0;
	nbr = n;
	ft_ft(nbr, i, &c, p);
	return (c);
}
