#include <iostream>

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	ch;

	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	for (i = 1; i < argc; i++)
	{
		j = 0;
		while (argv[i][j])
		{
			ch = toupper(argv[i][j]);
			std::cout << ch;
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
