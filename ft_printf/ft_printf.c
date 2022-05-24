/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:53:44 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/17 14:53:46 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_percent(const char *str)
{
	int	i;
	int	percent;

	i = 0;
	percent = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			percent++;
			if (str[i + 1] == '%')
				i++;
		}
		i++;
	}
	return (percent);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int	i;
	int	j;
	int count;
	int	no;

	i = 0;
	j = 0;
	count = 0;
	no = 0;
	va_start(args, str);
	while (i < ft_percent(str))
	{
		while (str[j] != '%')
        {
            ft_putchar_fd(str[j], 1);
			count++;
            j++;
        }
		j++;
		//%c
		if (str[j] == 'c')
		{
			ft_putchar_fd(va_arg(args, int), 1);
			count++;
		}
		//%s
		else if (str[j] == 's') //SIGSEGV NULL SAME FOR PRINTF
			ft_putstr_fd(va_arg(args, char *), 1, &count);
		//%p
		else if (str[j] == 'p') //ULONG_MAX, LONG MIN
			ft_putnbr_base(va_arg(args, long int), "0123456789abcdefg", 1, &count); //HUHHH
		//%d
		else if (str[j] == 'd') //NOTHING WRONG??
			ft_putnbr_fd(va_arg(args, int), 1, &count); //HHHUH
		//%i
		else if (str[j] == 'i')
			ft_putnbr_fd(va_arg(args, int), 1, &count);
		//%u
		else if (str[j] == 'u')
			ft_putnbr_fd(va_arg(args, unsigned int), 1, &count);
		//%x
		else if (str[j] == 'x')
			ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdefg", 0, &count);
		//%X
		else if (str[j] == 'X')
			ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEFG", 0, &count);
		//%%
		else if (str[j] == '%')
		{
			ft_putchar_fd('%', 1);
			count++;
			if (str[j + 1] == '%')
				no++;
		}
		j++;
		i++;
	}
	while (str[j])
	 {
            ft_putchar_fd(str[j], 1);
			count++;
            j++;
    }
	if (no % 2 == 1 && no != 1)
		return (-1);
	return (count);
}
