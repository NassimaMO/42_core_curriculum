#include <iostream>

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	ch;

	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	i = 1;
	for (; i < argc; i++)
	{
		j = -1;
		while (argv[i][++j])
		{
			ch = toupper(argv[i][j]);
			std::cout << ch;
		}
	}
	std::cout << std::endl;
	return (0);
}