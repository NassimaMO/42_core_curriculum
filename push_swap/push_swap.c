#include "push_swap.h"

int	main(int argc, char **argv)
{
	static int	*a;
	static int	*b;

	if (!number_checker(argv, argc))
		return (ft_printf("Error\n"), 0);
	if (argc <= 2)
		return (0);
	a = put_int_tab(argv, argc);
	if (!a)
		return (1);
	b = malloc(sizeof(int) * argc);
	if (!b)
		return (1);
	algo_op(a, b, argc);
	free(a);
	free(b);
	return (0);
}
