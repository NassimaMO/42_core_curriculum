#include "ft_irc.hpp"

static int	validPort(int port)
{
	if (port < 0 || port > 65535)
		return (1);
	return (0);
}

static int validPassword(std::string password)
{
	return (0);
}

int validArgs(char **argv)
{
	std::string password = argv[2];

	if (validPort(atoi(argv[1])) || validPassword(password))
		return (1);
	return (0);
}
