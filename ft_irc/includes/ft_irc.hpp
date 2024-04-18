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
<<<<<<< HEAD
# include <map>
# include <algorithm>
# include <csignal>

# include "Clients.hpp"
# include "Server.hpp"
# include "Channels.hpp"

int	strtoint(std::string src);
std::string	inttostr(int src);
=======

# include "Clients.hpp"
# include "Server.hpp"
# include "Reply.hpp"

int	strtoint(std::string src);
>>>>>>> d716035d2eb73105aa66ebd283be720780c86a21
int validArgs( std::string port, std::string password );


#endif
