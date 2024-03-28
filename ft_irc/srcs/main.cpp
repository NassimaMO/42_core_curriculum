#include "ft_irc.hpp"

int	strtoint(std::string src)
{
	std::stringstream	ss;
	int				dst;

	ss << src;
	ss >> dst;
	return (dst);
}

int main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	std::string port = argv[1];
	std::string password = argv[2];
	if (validArgs(port, password))
		return (1);
	Server server(password, port);
	server.setSocket();
	server.setServ();
	int socket_client;
	while (1)
	{
		if (poll(server.getFds().data(), server.getTotalClients() + 1, 1000) < 0)
			return (-1);
		if (server.getFds()[0].revents > 0)
		{
			socket_client = server.waitClients();
			if (socket_client < 0)
				return (std::cout << "Error" << std::endl, 1);
			std::string msg = server.receiveMsgs(socket_client);
			std::cout << "msg: " << msg << std::endl;
			break;
		}
	}
	sleep(1);
	close(socket_client);
	return (0);
}


// socket
// sockaddr_in --> inet_addr, htons
// bind
// listen
// accept
// connect
// recv
// send
