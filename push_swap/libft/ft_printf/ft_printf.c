/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:53:44 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/19 13:43:32 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

static int	ft_percent(const char *str)
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

static void	ft_conditions(char c, int *count, va_list args)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*count)++;
	}
	else if (c == 's')
		ft_printf_putstr_fd(va_arg(args, char *), 1, count);
	else if (c == 'p')
		ft_printf_putnbr_base(va_arg(args, long int), "0123456789abcdefg", 1, \
		count);
	else if (c == 'd')
		ft_printf_putnbr_fd(va_arg(args, int), 1, count);
	else if (c == 'i')
		ft_printf_putnbr_fd(va_arg(args, int), 1, count);
	else if (c == 'u')
		ft_printf_putnbr_fd(va_arg(args, unsigned int), 1, count);
	else if (c == 'x')
		ft_printf_putnbr_base(va_arg(args, unsigned int), \
		"0123456789abcdefg", 0, count);
	else if (c == 'X')
		ft_printf_putnbr_base(va_arg(args, unsigned int), \
		"0123456789ABCDEFG", 0, count);
}

static void	ft_print_str(char *str, int *j, int *count)
{
	while (str[*j] != '%')
	{
		ft_putchar_fd(str[*j], 1);
		(*count)++;
		(*j)++;
	}
}

static int	ft_loop(va_list args, char *str, int *no, int *count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ft_percent(str))
	{
		ft_print_str(str, &j, count);
		j++;
		ft_conditions(str[j], count, args);
		if (str[j] == '%')
		{
			ft_putchar_fd('%', 1);
			(*count)++;
			if (str[j + 1] == '%')
				(*no)++;
		}
		j++;
		i++;
	}
	return (j);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		no;
	int		j;
	int		count;

	no = 0;
	count = 0;
	j = 0;
	va_start(args, str);
	j = ft_loop(args, (char *)str, &no, &count);
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
