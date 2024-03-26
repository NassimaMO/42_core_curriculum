#ifndef FT_IRC_HPP
# define FT_IRC_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <unistd.h>
# include <fstream>

#include <poll.h>
#include <sys/socket.h>
#include <netinet/in.h>

int validArgs(char **argv);

#endif
