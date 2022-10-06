/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:25:04 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/06 15:25:04 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_printf_putstr_fd(char *s, int fd, int *count)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_printf_putstr_fd("(null)", 1, count);
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

static void	ft_printf_putchar(char c, int fd, int *i)
{
	write(fd, &c, 1);
	(*i)++;
}

void	ft_printf_putnbr_fd(long long int n, int fd, int *i)
{
	long long int	nbr;

	nbr = n;
	if (fd == -1)
		return ;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_printf_putchar('-', fd, i);
	}
	if (nbr >= 0 && nbr <= 9)
		ft_printf_putchar(nbr + 48, fd, i);
	if (nbr > 9)
	{
		ft_printf_putnbr_fd(nbr / 10, fd, i);
		nbr = nbr % 10;
		ft_printf_putchar(nbr + 48, fd, i);
	}
}
