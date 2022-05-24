/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:16:40 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/04 14:29:43 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

int	ft_nbr_tab(int n)
{
	int				j;
	long long int	nbr;

	j = 0;
	nbr = n;
	if (nbr < 0)
		j++;
	if (nbr == 0)
		j++;
	else
	{
		while (nbr)
		{
			nbr = nbr / 10;
			j++;
		}
	}
	return (j);
}

void	ft_neg(long long int *nbr, char *temp, long long int *i)
{
	(*nbr) = (*nbr) * -1;
	temp[*i] = '-';
	(*i)++;
}

char	*ft_itoa(int n)
{
	long long int	i;
	long long int	j;
	long long int	nbr;
	char			*temp;

	i = 0;
	j = ft_nbr_tab(n);
	temp = malloc(sizeof(char) * (j + 1));
	if (!temp)
		return (NULL);
	nbr = n;
	if (nbr < 0)
		ft_neg(&nbr, temp, &i);
	temp[j] = '\0';
	j--;
	while (i <= j)
	{
		temp[j] = (nbr % 10) + 48;
		nbr = nbr / 10;
		j--;
	}
	return (temp);
}

/*char	*ft_itoa(int n)
{
	long long int	i;
	long long int	j;
	long long int	nbr;
	char			*temp;

	j = 0;
	nbr = n;
	i = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		j++;
	}
	if (nbr == 0)
		j++;
	else
	{
		while (nbr)
		{
			nbr = nbr / 10;
			j++;
		}
	}
	temp = malloc(sizeof(char) * (j + 1));
	if (!temp)
		return (NULL);
	nbr = n;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		temp[i] = '-';
		i++;
	}
	temp[j] = '\0';
	j--;
	while (i <= j)
	{
		temp[j] = (nbr % 10) + 48;
		nbr = nbr / 10;
		j--;
	}
	return (temp);
}
*/
