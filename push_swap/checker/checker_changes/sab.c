/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:05:25 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/19 13:53:22 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*sa(swap a) : Swap the first 2 elements at the top of stack a. Do nothing if
	there is only one or no elements.*/
/*sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if
	there is only one or no elements.*/
#include "../checker.h"

void	sab(int *ab)
{
	int	tmp;

	tmp = ab[0];
	ab[0] = ab[1];
	ab[1] = tmp;
}

/*int main(void)
{
	static int *ab;

	ab = malloc(sizeof(int) * 5);
	ab[0] = 5;
	ab[1] = 8;
	ab[2] = 9;
	ab[3] = 4;
	ab[4] = '\0';
	sab(ab);
	printf("%d\n", ab[0]);
	printf("%d\n", ab[1]);
	printf("%d\n", ab[2]);
	printf("%d\n", ab[3]);
	printf("%d\n", ab[4]);
	free(ab);
}*/
