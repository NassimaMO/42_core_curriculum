#include "push_swap.h"

int main(int argc, char **argv)
{
	static int *a;
	static int *b;
	int len_a;
	int len_b;

	if (!number_checker(argv, argc))
		return (ft_printf("Error"), 0);
	a = put_int_tab(argv, argc);
	if (!a)
		return (1);
	b = malloc(sizeof(int) * argc);
	if (!b)
		return (1);
	len_a = argc - 1;
	len_b = 0;
	while (1)
	{
		if (nums_in_order(a, len_b))
			break;
		algo_op(a, b, &len_a, &len_b);
	}
	free(a);
	free(b);
	return (0);
}
