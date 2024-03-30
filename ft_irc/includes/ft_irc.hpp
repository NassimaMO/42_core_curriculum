#ifndef FT_IRC_HPP
# define FT_IRC_HPP
# include <string>
# include <sstream>
# include <arpa/inet.h>
# include <functional>
# include <sys/socket.h>
# include <iostream>
# include <unistd.h>
# include <errno.h>
# include <poll.h>
# include <cstdlib>
# include <vector>

# include "Clients.hpp"
# include "Server.hpp"
# include "Reply.hpp"

int	strtoint(std::string src);
int validArgs( std::string port, std::string password );


#endif
