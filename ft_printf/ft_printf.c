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

int	ft_zero(const char *str, int *j, char num, int n)
{
	int	c;
	int	i;

	c = 0;
	i = *j;
	if (str[i] == '0')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			c += str[i] - 48;
			if (str[i + 1] >= '0' && str[i + 1] <= '9')
				c *= 10;
			i++;
		}
		if (str[i] != num)
			return (0);
	}
	if (n)
		*j = i;
	return (c);
}

int	ft_putzero(va_list copy, int *count, const char *str, int *j)
{
	long long int	i_copy;
	int	minus;
	int	tmp;

	minus = 0;
	tmp = 0;
	if (ft_zero(str, j, 'u', 0) || str[*j] == 'u')
		i_copy = va_arg(copy, unsigned int);
	else if (ft_zero(str, j, 'd', 0) || str[*j] == 'd' || \
			ft_zero(str, j, 'i', 0) || str[*j] == 'i')
		i_copy = va_arg(copy, int);
	if (i_copy < 0)
	{
		ft_putchar_fd('-', 1);
		i_copy *= -1;
	}
	i_copy = ft_putnbr_fd(i_copy, count, 0, minus);
	if ((ft_zero(str, j, 'd', 0) && ft_zero(str, j, 'd', 0) > i_copy) || \
		(ft_zero(str, j, 'i', 0) && ft_zero(str, j, 'i', 0) > i_copy) || \
		(ft_zero(str, j, 'u', 0) && ft_zero(str, j, 'u', 0) > i_copy))
	{
		if (ft_zero(str, j, 'd', 0) > i_copy)
			minus = ft_zero(str, j, 'd', 1);
		else if (ft_zero(str, j, 'i', 0) > i_copy)
			minus = ft_zero(str, j, 'i', 1);
		else if (ft_zero(str, j, 'u', 0) > i_copy)
			minus = ft_zero(str, j, 'u', 1);
		tmp = minus;
		while (minus - 1 >= i_copy)
		{
			ft_putchar_fd('0', 1);
			minus--;
		}
		if (tmp >= i_copy)
			(*count) += tmp - (i_copy - 1);
		if (!tmp)
			return (1);
	}
//	printf("\\\\\\%d///", minus);
	return (tmp);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	va_list copy;
	int	i;
	int	j;
//	int	i_copy;
	int count;
	int	no;
	int	minus;
	int	count_bonus;
	int	tmp;

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
		minus = 0;
		//-
		if (str[j] == '-')
		{
			j++;
			while (str[j] >= '0' && str[j] <= '9')
			{
				minus += str[j] - 48;
				if (str[j + 1] >= '0' && str[j + 1] <= '9')
					minus *= 10;
				j++;
			}
		}
	/*	//.
		//#
		if (str[j] == '#' && (str[j + 1] == 'x' || str[j + 1] == 'X'))
			//0x ou 0X
		//' '
		//+
		count++;
		j++;
	*/
		count_bonus = count;
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
		else if (str[j] == 'd' || ft_zero(str, &j, 'd', 0))
			ft_putnbr_fd(va_arg(args, int), &count, 1, ft_putzero(copy, &count, str, &j)); //HHHUH
		//%i
		else if (str[j] == 'i' || ft_zero(str, &j, 'i', 0))
			ft_putnbr_fd(va_arg(args, int), &count, 1, ft_putzero(copy, &count, str, &j));
		//%u
		else if (str[j] == 'u' || ft_zero(str, &j, 'u', 0))
			ft_putnbr_fd(va_arg(args, unsigned int), &count, 1, ft_putzero(copy, &count, str, &j));
		//%x
		else if (str[j] == 'x' || ft_zero(str, &j, 'x', 0))
			ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdefg", 0, &count);
		//%X
		else if (str[j] == 'X' || ft_zero(str, &j, 'X', 0))
			ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEFG", 0, &count);
		//%%
		else if (str[j] == '%')
		{
			ft_putchar_fd('%', 1);
			count++;
			if (str[j + 1] == '%')
				no++;
		}
		tmp = minus;
		while (minus - 1 >= count - count_bonus)
		{
			ft_putchar_fd(' ', 1);
			minus--;
		}
		if (tmp - 1 >= count - count_bonus)
			count += tmp - (count - count_bonus);
		j++;
		i++;
	}
	va_end(args);
	while (str[j])
	 {
            ft_putchar_fd(str[j], 1);
			count++;
            j++;
    }
//		printf("%d\n", count);
	if (no % 2 == 1 && no != 1)
		return (-1);
	return (count);
}

#include <limits.h>
/*
	CHARACTERS
	printf("%d", ft_printf("%c\n", '0');
	printf("%d", ft_printf(" %c \n", '0');
	printf("%d", ft_printf(" %c\n", '0' - 256);
	printf("%d", ft_printf("%c \n", '0' + 256);
	printf("%d", ft_printf(" %c %c %c \n", '0', 0, '1');
	printf("%d", ft_printf(" %c %c %c \n", ' ', ' ', ' ');
	printf("%d", ft_printf(" %c %c %c \n", '1', '2', '3');
	printf("%d", ft_printf(" %c %c %c \n", '2', '1', 0);
	printf("%d", ft_printf(" %c %c %c \n\n", 0, '1', '2');

	printf("%d", printf("%d", printf("%c\n", '0');
	printf("%d", printf(" %c \n", '0');
	printf("%d", rintf(" %c\n", '0' - 256);
	printf("%d", printf("%c \n", '0' + 256);
	printf("%d", printf(" %c %c %c \n", '0', 0, '1');
	printf("%d", printf(" %c %c %c \n", ' ', ' ', ' ');
	printf("%d", printf(" %c %c %c \n", '1', '2', '3');
	printf("%d", printf(" %c %c %c \n", '2', '1', 0);
	printf("%d", printf(" %c %c %c \n", 0, '1', '2');
*/

	//STRINGSS
/*	char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	ft_printf("1.%s\n", "");
	ft_printf("2. %s\n", "");
	ft_printf("3.%s \n", "");
	ft_printf("4. %s \n", "");
	ft_printf("5. %s \n", "-");
	ft_printf("6. %s %s \n", "", "-");
	ft_printf("7. %s %s \n", " - ", "");
	ft_printf("8. %s %s %s %s %s\n", " - ", "", "4", "", s2);
	ft_printf("9. %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
	ft_printf("10. NULL %s NULL \n\n", NULL);  //SIGSEGV

	printf("%s\n", "");
	printf(" %s\n", "");
	printf("%s \n", "");
	printf(" %s \n", "");
	printf(" %s \n", "-");
	printf(" %s %s \n", "", "-");
	printf(" %s %s \n", " - ", "");
	printf(" %s %s %s %s %s\n", " - ", "", "4", "", s2);
	printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
	printf(" NULL %s NULL \n", NULL);  //SIGSEGV
*/

/*
	//POINTERS
	printf("%d\n", ft_printf(" %p \n", -1));
	printf("%d\n", ft_printf(" %p \n", 1));
	printf("%d\n", ft_printf(" %p \n", 15));
	printf("%d\n", ft_printf(" %p \n", 16));
	printf("%d\n", ft_printf(" %p \n", 17));
	printf("%d\n", ft_printf(" %p %p \n", LONG_MIN, LONG_MAX));
	printf("%d\n", ft_printf(" %p %p \n", INT_MIN, INT_MAX));
	printf("%d\n", ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX));
	printf("%d\n", ft_printf(" %p %p \n\n", 0, 0));

	printf("%d\n", printf(" %p \n", -1));
	printf("%d\n", printf(" %p \n", 1));
	printf("%d\n", printf(" %p \n", 15));
	printf("%d\n", printf(" %p \n", 16));
	printf("%d\n",printf(" %p \n", 17));
	printf("%d\n", printf(" %p %p \n", LONG_MIN, LONG_MAX));
	printf("%d\n", printf(" %p %p \n", INT_MIN, INT_MAX));
	printf("%d\n", printf(" %p %p \n", ULONG_MAX, -ULONG_MAX));
	printf("%d\n", printf(" %p %p \n", 0, 0));
*/

/*
	//DOUBLES
	printf("%d\n", ft_printf(" %d \n", 0));
	printf("%d\n", ft_printf(" %d \n", -1));
	printf("%d\n", ft_printf(" %d \n", 1));
	printf("%d\n", ft_printf(" %d \n", 9));
	printf("%d\n", ft_printf(" %d \n", 10));
	printf("%d\n", ft_printf(" %d \n", 11));
	printf("%d\n", ft_printf(" %d \n", 15));
	printf("%d\n", ft_printf(" %d \n", 16));
	printf("%d\n", ft_printf(" %d \n", 17));
	printf("%d\n", ft_printf(" %d \n", 99));
	printf("%d\n", ft_printf(" %d \n", 100));
	printf("%d\n", ft_printf(" %d \n", 101));
	printf("%d\n", ft_printf(" %d \n", -9));
	printf("%d\n", ft_printf(" %d \n", -10));
	printf("%d\n", ft_printf(" %d \n", -11));
	printf("%d\n", ft_printf(" %d \n", -14));
	printf("%d\n", ft_printf(" %d \n", -15));
	printf("%d\n", ft_printf(" %d \n", -16));
	printf("%d\n", ft_printf(" %d \n", -99));
	printf("%d\n", ft_printf(" %d \n", -100));
	printf("%d\n", ft_printf(" %d \n", -101));
	printf("%d\n", ft_printf(" %d \n", INT_MAX));
	printf("%d\n", ft_printf(" %d \n", INT_MIN));
	printf("%d\n", ft_printf(" %d \n", LONG_MAX));
	printf("%d\n", ft_printf(" %d \n", LONG_MIN));
	printf("%d\n", ft_printf(" %d \n", UINT_MAX));
	printf("%d\n", ft_printf(" %d \n", ULONG_MAX));
	printf("%d\n", ft_printf(" %d \n", 9223372036854775807LL));
	printf("%d\n", ft_printf(" %d %d %d %d %d %d %d\n\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));

	printf("%d\n", printf(" %d \n", 0));
	printf("%d", printf(" %d \n", -1));
	printf("%d", printf(" %d \n", 1));
	printf("%d", printf(" %d \n", 9));
	printf("%d", printf(" %d \n", 10));
	printf("%d", printf(" %d \n", 11));
	printf("%d", printf(" %d \n", 15));
	printf("%d", printf(" %d \n", 16));
	printf("%d", printf(" %d \n", 17));
	printf("%d", printf(" %d \n", 99));
	printf("%d", printf(" %d \n", 100));
	printf("%d", printf(" %d \n", 101));
	printf("%d", printf(" %d \n", -9));
	printf("%d", printf(" %d \n", -10));
	printf("%d", printf(" %d \n", -11));
	printf("%d", printf(" %d \n", -14));
	printf("%d", printf(" %d \n", -15));
	printf("%d", printf(" %d \n", -16));
	printf("%d", printf(" %d \n", -99));
	printf("%d", printf(" %d \n", -100));
	printf("%d", printf(" %d \n", -101));
	printf("%d", printf(" %d \n", INT_MAX));
	printf("%d", printf(" %d \n", INT_MIN));
	printf("%d", printf(" %d \n", LONG_MAX));
	printf("%d", printf(" %d \n", LONG_MIN));
	printf("%d", printf(" %d \n", UINT_MAX));
	printf("%d", printf(" %d \n", ULONG_MAX));
	printf("%d", printf(" %d \n", 9223372036854775807LL));
	printf("%d", printf(" %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
*/

/*
	//hexa
	printf("%d\n", ft_printf(" %x ", 0));
	printf("%d\n", ft_printf(" %x ", -1));
	printf("%d\n", ft_printf(" %x ", 1));
	printf("%d\n", ft_printf(" %x ", 9));
	printf("%d\n", ft_printf(" %x ", 10));
	printf("%d\n", ft_printf(" %x ", 11));
	printf("%d\n", ft_printf(" %x ", 15));
	printf("%d\n", ft_printf(" %x ", 16));
	printf("%d\n", ft_printf(" %x ", 17));
	printf("%d\n", ft_printf(" %x ", 99));
	printf("%d\n", ft_printf(" %x ", 100));
	printf("%d\n", ft_printf(" %x ", 101));
	printf("%d\n", ft_printf(" %x ", -9));
	printf("%d\n", ft_printf(" %x ", -10));
	printf("%d\n", ft_printf(" %x ", -11));
	printf("%d\n", ft_printf(" %x ", -14));
	printf("%d\n", ft_printf(" %x ", -15));
	printf("%d\n", ft_printf(" %x ", -16));
	printf("%d\n", ft_printf(" %x ", -99));
	printf("%d\n", ft_printf(" %x ", -100));
	printf("%d\n", ft_printf(" %x ", -101));
	printf("%d\n", ft_printf(" %x ", INT_MAX));
	printf("%d\n", ft_printf(" %x ", INT_MIN));
	printf("%d\n", ft_printf(" %x ", LONG_MAX));
	printf("%d\n", ft_printf(" %x ", LONG_MIN));
	printf("%d\n", ft_printf(" %x ", UINT_MAX));
	printf("%d\n", ft_printf(" %x ", ULONG_MAX));
	printf("%d\n", ft_printf(" %x ", 9223372036854775807LL));
	printf("%d\n", ft_printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("%d\n", ft_printf(" %x ", 42));
	printf("%d\n\n", ft_printf(" %x ", -42));

	printf("%d\n", printf(" %x ", 0));
	printf("%d\n", printf(" %x ", -1));
	printf("%d\n", printf(" %x ", 1));
	printf("%d\n", printf(" %x ", 9));
	printf("%d\n", printf(" %x ", 10));
	printf("%d\n", printf(" %x ", 11));
	printf("%d\n", printf(" %x ", 15));
	printf("%d\n", printf(" %x ", 16));
	printf("%d\n", printf(" %x ", 17));
	printf("%d\n", printf(" %x ", 99));
	printf("%d\n", printf(" %x ", 100));
	printf("%d\n", printf(" %x ", 101));
	printf("%d\n", printf(" %x ", -9));
	printf("%d\n", printf(" %x ", -10));
	printf("%d\n", printf(" %x ", -11));
	printf("%d\n", printf(" %x ", -14));
	printf("%d\n", printf(" %x ", -15));
	printf("%d\n", printf(" %x ", -16));
	printf("%d\n", printf(" %x ", -99));
	printf("%d\n", printf(" %x ", -100));
	printf("%d\n", printf(" %x ", -101));
	printf("%d\n", printf(" %x ", INT_MAX));
	printf("%d\n", printf(" %x ", INT_MIN));
	printf("%d\n", printf(" %x ", LONG_MAX));
	printf("%d\n", printf(" %x ", LONG_MIN));
	printf("%d\n", printf(" %x ", UINT_MAX));
	printf("%d\n", printf(" %x ", ULONG_MAX));
	printf("%d\n", printf(" %x ", 9223372036854775807LL));
	printf("%d\n", printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("%d\n", printf(" %x ", 42));
	printf("%d\n", printf(" %x ", -42));
*/
/*int	main()
{
	printf("%d\n", ft_printf(" %-2s %-3s %-4s %-5s ", " - ", "", "4", ""));
	printf("%d\n\n", printf(" %-2s %-3s %-4s %-5s ", " - ", "", "4", ""));
	printf("%d\n", ft_printf(" %04d ", -3));
	printf("%d\n\n", printf(" %04d ", -3));
	printf("%d\n", ft_printf(" %015d ", -3));
	printf("%d\n\n", printf(" %015d ", -3));
	printf("%d\n", ft_printf(" %04d %04i %04u %04x ", 0, 23, 23, 23));
	printf("%d\n\n", printf(" %04d %04i %04u %04x ", 0, 23, 23, 23));
	printf("%d\n", ft_printf("%d", -1));
	printf("%d\n", printf("%d", -1));
}*/
/*{
	printf("%d\n", ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
	printf("%d\n", printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
}*/
int main()
{
	printf("%d\n", ft_printf(" %01d ", 0));
	printf("%d\n", ft_printf(" %02d ", -1));
	printf("%d\n", ft_printf(" %04d ", 9));
	printf("%d\n", ft_printf(" %01d ", 10));
	printf("%d\n", ft_printf(" %02d ", 11));
	printf("%d\n", ft_printf(" %03d ", 15));
	printf("%d\n", ft_printf(" %04d ", 16));
	printf("%d\n", ft_printf(" %05d ", 17));
	printf("%d\n", ft_printf(" %01d ", 99));
	printf("%d\n", ft_printf(" %02d ", 100));
	printf("%d\n", ft_printf(" %03d ", 101));
	printf("%d\n", ft_printf(" %01d ", -9));
	printf("%d\n", ft_printf(" %02d ", -10));
	printf("%d\n", ft_printf(" %03d ", -11));
	printf("%d\n", ft_printf(" %04d ", -14));
	printf("%d\n", ft_printf(" %05d ", -15));
	printf("%d\n", ft_printf(" %06d ", -16));
	printf("%d\n", ft_printf(" %01d ", -99));
	printf("%d\n", ft_printf(" %02d ", -100));
	printf("%d\n", ft_printf(" %03d ", -101));
	printf("%d\n", ft_printf(" %09d ", INT_MAX));
	printf("%d\n", ft_printf(" %010d ", INT_MIN));
	printf("%d\n", ft_printf(" %011d ", LONG_MAX));
	printf("%d\n", ft_printf(" %012d ", LONG_MIN));
	printf("%d\n", ft_printf(" %013d ", UINT_MAX));
	printf("%d\n", ft_printf(" %014d ", ULONG_MAX));
	printf("%d\n\n", ft_printf(" %015d ", 9223372036854775807LL));

	printf("%d\n", printf(" %01d ", 0));
	printf("%d\n", printf(" %02d ", -1));
	printf("%d\n", printf(" %04d ", 9));
	printf("%d\n", printf(" %01d ", 10));
	printf("%d\n", printf(" %02d ", 11));
	printf("%d\n", printf(" %03d ", 15));
	printf("%d\n", printf(" %04d ", 16));
	printf("%d\n", printf(" %05d ", 17));
	printf("%d\n", printf(" %01d ", 99));
	printf("%d\n", printf(" %02d ", 100));
	printf("%d\n", printf(" %03d ", 101));
	printf("%d\n", printf(" %01d ", -9));
	printf("%d\n", printf(" %02d ", -10));
	printf("%d\n", printf(" %03d ", -11));
	printf("%d\n", printf(" %04d ", -14));
	printf("%d\n", printf(" %05d ", -15));
	printf("%d\n", printf(" %06d ", -16));
	printf("%d\n", printf(" %01d ", -99));
	printf("%d\n", printf(" %02d ", -100));
	printf("%d\n", printf(" %03d ", -101));
	printf("%d\n", printf(" %09d ", INT_MAX));
	printf("%d\n", printf(" %010d ", INT_MIN));
	printf("%d\n", printf(" %011d ", LONG_MAX));
	printf("%d\n", printf(" %012d ", LONG_MIN));
	printf("%d\n", printf(" %013d ", UINT_MAX));
	printf("%d\n", printf(" %014d ", ULONG_MAX));
	printf("%d\n", printf(" %015d ", 9223372036854775807LL));
}