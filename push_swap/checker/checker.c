#include "checker.h"

int	main(int argc, char **argv)
{
	int			i;
	static int	*a;
	static int	*b;
    char **tab;

	i = 0;
	if (!number_checker(argv, argc))
		return (ft_printf("Error\n"), 0);
	if (argc <= 2)
		return (0);
	a = put_int_tab(argv, argc);
	if (!a)
		return (1);
	b = malloc(sizeof(int) * argc);
	if (!b)
	{
		free(a);
		return (1);
	}
	while (i < argc)
		b[i++] = '\0';
    tab = str_to_tab();
	execute_instruct(tab, a, b);
	free(a);
	free(b);
	return (0);
}