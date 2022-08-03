/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:05:16 by nmouslim          #+#    #+#             */
/*   Updated: 2022/07/04 19:05:19 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*rrr : rra and rrb at the same time.*/
#include "../push_swap.h"

void rrr(int *a, int *b, int len_a, int len_b)
{
	rrab(a, len_a);
	rrab(b, len_b);
}

/*int main(void)
{
	static int *a;
	static int *b;

	a = malloc(sizeof(int) * 8);
	b = malloc(sizeof(int) * 8);
	a[0] = 5;
	a[1] = 8;
	a[2] = 9;
	a[3] = 4;
	a[4] = '\0';
	b[0] = 4;
	b[1] = 3;
	b[2] = 2;
	b[3] = '\0';
	rrr(a, b);
	printf("%d\n", a[0]);
	printf("%d\n", a[1]);
	printf("%d\n", a[2]);
	printf("%d\n", a[3]);
	printf("%d\n", a[4]);
	printf("\n");
	printf("%d\n", b[0]);
	printf("%d\n", b[1]);
	printf("%d\n", b[2]);
	printf("%d\n", b[3]);
	free(a);
	free(b);
}*/
