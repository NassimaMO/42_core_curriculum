/*pa (push a): Take the first element at the top of b and put it at the top of a.Do nothing if b is empty.*/
#include "../push_swap.h"

void	pab(int *ab, int *ba)
{
	int	i;

	i = 0;
	while (ab && ab[i])
		i++;
	ab[i + 1] = '\0';
	i--;
	while (ab && ab[i])
	{
		ab[i + 1] = ab[i];
		i--;
	}
	ab[0] = ba[0];
	i = 1;
	while (ba && ba[i])
	{
		ba[i - 1] = ba[i];
		i++;
	}
	ba[i - 1] = '\0';
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
	pab(a, b);
	printf("%d\n", a[0]);
	printf("%d\n", a[1]);
	printf("%d\n", a[2]);
	printf("%d\n", a[3]);
	printf("%d\n", a[4]);
	printf("%d\n", a[5]);
	printf("\n");
	printf("%d\n", b[0]);
	printf("%d\n", b[1]);
	printf("%d\n", b[2]);
	free(a);
	free(b);
}*/