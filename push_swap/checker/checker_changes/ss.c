/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:05:32 by nmouslim          #+#    #+#             */
/*   Updated: 2022/10/19 13:53:09 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ss : sa and sb at the same time.*/
#include "../checker.h"

void	ss(int *a, int *b)
{
	sab(a);
	sab(b);
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
	ss(a, b);
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
