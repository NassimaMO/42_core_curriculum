/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:43:01 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/30 14:43:04 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "libft/libft.h"

static void	ft_nb_neg(long long *nb, int n, int *i)
{
	if (*nb < 0)
	{
		*nb = -(*nb);
		if (n)
		{
			ft_putchar_fd('-', 1);
			(*i)++;
		}
		else
			ft_putstr_fd("ffffffff", 1, i);
	}
}

static void	ft_recursive(long int nbr, char *base, int *i, int n)
{
	long long	nb;

	nb = nbr;
	ft_nb_neg(&nb, n, i);
	if (nb >= 0 && nb <= 15)
	{
		nb = nb % 16;
		ft_putchar_fd(base[nb], 1);
		(*i)++;
	}
	if (nb > 15)
	{
		ft_recursive(nb / 16, base, i, n);
		nb = nb % 16;
		ft_putchar_fd(base[nb], 1);
		(*i)++;
	}
}

int	ft_putnbr_base(long int nbr, char *base, int n, int *i)
{
	if (nbr && n)
		ft_putstr_fd("0x", 1, i);
	else if (n && !nbr)
	{
		ft_putstr_fd("(nil)", 1, i);
		return (1);
	}
	if (nbr == LONG_MIN)
		ft_putstr_fd("8000000000000000", 1, i);
	else if ((long unsigned int)nbr == ULONG_MAX && n)
		ft_putstr_fd("ffffffffffffffff", 1, i);
	else
		ft_recursive(nbr, base, i, n);
	return (0);
}
