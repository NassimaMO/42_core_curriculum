/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:15:11 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/09 18:08:27 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_atoi(const char *nptr)
{
	long long int	result;
	int				minus;
	int				i;

	i = 0;
	result = 0;
	minus = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			minus = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result += nptr[i] - 48;
		if (nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
			result *= 10;
		i++;
	}
	return (result * minus);
}
