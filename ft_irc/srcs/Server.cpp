#include "Server.hpp"

Server::Server(std::string password, std::string port) : _password(password), _port(port)
{
	_buffer = "";
	_totalClients = 0;
}

Server::~Server()
{
	close(_sockfd);
	/*for (int i = 0; i < _totalClients; i++)
		close(_client[i]._sockfd);*/
}

std::string	&Server::getPort(void)
{
	return (_port);
}

std::string	&Server::getPassword(void)
{
	return (_password);
}

int Server::getTotalClients(void)
{
	return (_totalClients);
}

std::vector<struct pollfd>  &Server::getFds(void)
{
	return (_fds);
}

void	Server::setSocket(void)
{
	_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	std::cout << "Server socket: " << _sockfd << std::endl;
}

int	Server::setServ(void)
{
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(strtoint(_port));
	serv_addr.sin_family = AF_INET;
	if (bind(_sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
		return (-1);
	std::cout << "IP address: " << serv_addr.sin_addr.s_addr << std::endl;
	struct pollfd fd;
	_fds.push_back(fd);
	_fds[0].fd = _sockfd;
	_fds[0].events = POLLIN;
	_fds[0].revents = 0;
	if (listen(_sockfd, 3) == -1)
		return (-1);
	return (0);
}

int		Server::waitClients(void)
{
	int				socket_client;

	std::cout << "Events of server: " << _fds[0].revents << std::endl;
	socklen_t addrlen = sizeof(serv_addr);
	socket_client = accept(_sockfd, (struct sockaddr *)&serv_addr, &addrlen);
	struct pollfd fd;
	_fds.push_back(fd);
	_fds[_totalClients + 1].fd = socket_client;
	_fds[_totalClients + 1].events = POLLIN;
	_fds[_totalClients + 1].revents = 0;
	_totalClients++;
	return (socket_client);
}

std::string		Server::receiveMsgs(int sockfd)
{
	std::string buffer;
	char buf[10];

	for (ssize_t i = 1; ; )
	{
		i = recv(sockfd, &buf, sizeof(buf) - 1, MSG_DONTWAIT);
		if (i == -1)
			return (buffer);
		buf[i] = '\0';
		buffer += buf;
	}
	return ("");
}

int		Server::sendMsgs(void)
{
	return (0);
}
