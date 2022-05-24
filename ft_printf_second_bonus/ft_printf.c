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

char	ft_space(const char *str, int *j, va_list copy, int *count)
{
	long long int i;
	int	k;

	k = (*j);
	if (str[k] == ' ' && (str[k + 1] == 'd' || str[k + 1] == 'i'))
	{
		printf("la");
		if (va_arg(copy, int) > 0)
		{
			ft_putstr_fd(" ", 1, count);
			(*j)++;
		}
		return (str[*j]);
	}
	i = 0;
	k++;
	while (str[k] >= '0' && str[k] <= '9')
	{
		i += str[k] - 48;
		if (str[k + 1] >= '0' && str[k + 1] <= '9')
			i *= 10;
		k++;
	}
	//printf("\\\\%lld//", i);
	while (i)
	{
		ft_putstr_fd(" ", 1, count);
		i--;
	}
	(*j) = k;
	return (str[*j]);
}
void	ft_sharp(char c, va_list copy, va_list args, int *count)
{
	unsigned int i;

	i = va_arg(copy, unsigned int);
	if (c == 'x')
	{
		if (i > 0)
		{
			ft_putstr_fd("0x", 1, count);
			ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdefg", 0, count);
		}
		else
			ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdefg", 2, count);
	}
	else
	{
		if (i > 0)
		{
			ft_putstr_fd("0X", 1, count);
			ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEFG", 0, count);
		}
		else
			ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEFG", 2, count);
	}
}

int ft_printf(const char *str, ...)
{
	va_list args;
	va_list copy;
	int	i;
	int	j;
	int count;
	int	no;

	i = 0;
	j = 0;
	count = 0;
	no = 0;
	va_start(args, str);
	va_copy(copy, args);
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
		else if (str[j] == 's' || (str[j] == ' ' && ft_space(str, &j, copy, &count)))
			ft_putstr_fd(va_arg(args, char *), 1, &count);
		//%p
		else if (str[j] == 'p')
			ft_putnbr_base(va_arg(args, long int), "0123456789abcdefg", 1, &count);
		//%d
		else if (str[j] == 'd' || (str[j] == ' ' && ft_space(str, &j, copy, &count) == 'd'))
			ft_putnbr_fd(va_arg(args, int), 1, &count);
		//%i
		else if (str[j] == 'i' || (str[j] == ' ' && ft_space(str, &j, copy, &count) == 'i'))
			ft_putnbr_fd(va_arg(args, int), 1, &count);
		//%u
		else if (str[j] == 'u' || (str[j] == ' ' && str[j + 1] == 'u'))
			ft_putnbr_fd(va_arg(args, unsigned int), 1, &count);
		//%x
		else if (str[j] == 'x' || (str[j] == '#' && str[j + 1] == 'x'))
		{
			if (str[j] == '#')
			{
				ft_sharp(str[j + 1], copy, args, &count);
				j++;
			}
			else
				ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdefg", 0, &count);
		}
		//%X
		else if (str[j] == 'X' || (str[j] == '#' && str[j + 1] == 'X'))
		{
			if (str[j] == '#')
			{
				ft_sharp(str[j + 1], copy, args, &count);
				j++;
			}
			else
				ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdefg", 0, &count);
		}
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
#include <limits.h>
int main()
{
/*	printf("%d\n", ft_printf("% s", ""));
	printf("%d\n", ft_printf(" % 3s", ""));
	printf("%d\n", ft_printf("% 3s ", ""));
	printf("%d\n", ft_printf(" % s ", ""));
	printf("%d\n", ft_printf(" % s ", "-"));
	printf("%d\n", ft_printf(" % s % s ", "", "-"));
	printf("%d\n", ft_printf(" % s % s ", " - ", ""));
	printf("%d\n", ft_printf(" % s % s % s % s ", " - ", "", "4", ""));
	printf("%d\n", ft_printf(" % s % s % s % s % s ", " - ", "", "4", "", "2 "));

	printf("%d\n", printf("% s", ""));
	printf("%d\n", printf(" % 3s", ""));
	printf("%d\n", printf("% 3s ", ""));
	printf("%d\n", printf(" % s ", ""));
	printf("%d\n", printf(" % s ", "-"));
	printf("%d\n", printf(" % s % s ", "", "-"));
	printf("%d\n", printf(" % s % s ", " - ", ""));
	printf("%d\n", printf(" % s % s % s % s ", " - ", "", "4", ""));
	printf("%d\n", printf(" % s % s % s % s % s ", " - ", "", "4", "", "2 "));*/

	printf("%d\n", ft_printf(" % d ", 0));
	printf("%d\n", ft_printf(" % d ", -1));
	printf("%d\n", ft_printf(" % d ", 1));
	printf("%d\n", ft_printf(" % d ", 9));
	printf("%d\n", ft_printf(" % d ", 10));
	printf("%d\n", ft_printf(" % d ", 11));
	printf("%d\n", ft_printf(" % d ", 15));
	printf("%d\n", ft_printf(" % d ", 16));
	printf("%d\n", ft_printf(" % d ", 17));
	printf("%d\n", ft_printf(" % d ", 99));
	printf("%d\n", ft_printf(" % d ", 100));
	printf("%d\n", ft_printf(" % d ", 101));
	printf("%d\n", ft_printf(" % d ", -9));
	printf("%d\n", ft_printf(" % d ", -10));
	printf("%d\n", ft_printf(" % d ", -11));
	printf("%d\n", ft_printf(" % d ", -14));
	printf("%d\n", ft_printf(" % d ", -15));
	printf("%d\n", ft_printf(" % d ", -16));
	printf("%d\n", ft_printf(" % d ", -99));
	printf("%d\n", ft_printf(" % d ", -100));
	printf("%d\n", ft_printf(" % d ", -101));
	printf("%d\n", ft_printf(" % d ", INT_MAX));
	printf("%d\n", ft_printf(" % d ", INT_MIN));
	printf("%d\n", ft_printf(" % d ", LONG_MAX));
	printf("%d\n", ft_printf(" % d ", LONG_MIN));
	printf("%d\n", ft_printf(" % d ", UINT_MAX));
	printf("%d\n", ft_printf(" % d ", ULONG_MAX));
	printf("%d\n", ft_printf(" % d ", 9223372036854775807LL));
	printf("%d\n", ft_printf(" % d % d % d % d % d % d % d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));

	printf("%d\n", printf(" % d ", 0));
	printf("%d\n", printf(" % d ", -1));
	printf("%d\n", printf(" % d ", 1));
	printf("%d\n", printf(" % d ", 9));
	printf("%d\n", printf(" % d ", 10));
	printf("%d\n", printf(" % d ", 11));
	printf("%d\n", printf(" % d ", 15));
	printf("%d\n", printf(" % d ", 16));
	printf("%d\n", printf(" % d ", 17));
	printf("%d\n", printf(" % d ", 99));
	printf("%d\n", printf(" % d ", 100));
	printf("%d\n", printf(" % d ", 101));
	printf("%d\n", printf(" % d ", -9));
	printf("%d\n", printf(" % d ", -10));
	printf("%d\n", printf(" % d ", -11));
	printf("%d\n", printf(" % d ", -14));
	printf("%d\n", printf(" % d ", -15));
	printf("%d\n", printf(" % d ", -16));
	printf("%d\n", printf(" % d ", -99));
	printf("%d\n", printf(" % d ", -100));
	printf("%d\n", printf(" % d ", -101));
	printf("%d\n", printf(" % d ", INT_MAX));
	printf("%d\n", printf(" % d ", INT_MIN));
	printf("%d\n", printf(" % d ", LONG_MAX));
	printf("%d\n", printf(" % d ", LONG_MIN));
	printf("%d\n", printf(" % d ", UINT_MAX));
	printf("%d\n", printf(" % d ", ULONG_MAX));
	printf("%d\n", printf(" % d ", 9223372036854775807LL));
	printf("%d\n", printf(" % d % d % d % d % d % d % d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
}