/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:05:05 by nmouslim          #+#    #+#             */
/*   Updated: 2022/07/04 19:05:08 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*rra (reverse rotate a): Shift down all elements of stack a by 1. The last
	element becomes the first one.*/
/*rrb (reverse rotate b): Shift down all elements of stack b by 1. The last
	element becomes the first one.*/
#include "../push_swap.h"

void rrab(int *ab, int len_ab)
{
	int tmp;
	int i;

	i = len_ab;
	tmp = ab[--i];
	while (ab && i != 0)
	{
		ab[i] = ab[i - 1];
		i--;
	}
	ab[0] = tmp;
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
	rrab(ab, 4);
	printf("%d\n", ab[0]);
	printf("%d\n", ab[1]);
	printf("%d\n", ab[2]);
	printf("%d\n", ab[3]);
	printf("%d\n", ab[4]);
	free(ab);
}*/
