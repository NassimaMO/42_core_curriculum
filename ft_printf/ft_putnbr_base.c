/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:02:11 by nmouslim          #+#    #+#             */
/*   Updated: 2022/02/20 11:18:36 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "libft/libft.h"
void	ft_recursive(long int nbr, char *base, int *i, int n)
{
	long long	nb;

	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		if (n)
		{
			ft_putchar_fd('-', 1);
			(*i)++;
		}
		else
			ft_putstr_fd("ffffffff", 1, i);
	}
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
/*#include <stdio.h>
int		main(void)
{
	write(1, "42:", 3);
	ft_putnbr_base(42, "0123456789");
	write(1, "\n2a:", 4);
	ft_putnbr_base(42, "abcdefghijklmnop");
	write(1, "\n-2a:", 5);
	ft_putnbr_base(-42, "0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "0");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "+-0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "\t0123456789abcdef");
}*/
