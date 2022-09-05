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

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long int	nbr;

	nbr = n;
	if (fd == -1)
		return ;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-', fd);
	}
	if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + 48, fd);
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		nbr = nbr % 10;
		ft_putchar(nbr + 48, fd);
	}
}
