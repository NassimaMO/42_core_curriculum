#include "Server.hpp"

Server::Server(std::string password, std::string port) : _password(password), _port(port)
{
	_totalClients = 0;
	_ext = 0;
	_ext += this->initSocket();
	_ext += this->initServ();
}

Server::~Server()
{
	close(_sockfd);
	/*for (int i = 0; i < _totalClients; i++)
		close(_client[i]._sockfd);*/
}

int	Server::initSocket(void)
{
	_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	std::cout << "Server socket: " << _sockfd << std::endl;
	return (0);
}

int	Server::initServ(void)
{
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(strtoint(_port));
	serv_addr.sin_family = AF_INET;
	if (bind(_sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
		return (-1);
	std::cout << "IP address: " << serv_addr.sin_addr.s_addr << std::endl;
	struct pollfd fd;
	_fds.push_back(fd); // ??
	_fds[0].fd = _sockfd;
	_fds[0].events = POLLIN;
	_fds[0].revents = 0;
	if (listen(_sockfd, 3) == -1)
		return (-1);
	return (0);
}

void		Server::waitClients(void)
{
	int socket_client;

	std::cout << "Events of server: " << _fds[0].revents << std::endl;
	socklen_t addrlen = sizeof(serv_addr);
	socket_client = accept(_sockfd, (struct sockaddr *)&serv_addr, &addrlen);
	struct pollfd fd;
	_fds.push_back(fd);
	_fds[_totalClients + 1].fd = socket_client;
	_fds[_totalClients + 1].events = POLLIN;
	_fds[_totalClients + 1].revents = 0;
	_client.push_back(Clients(socket_client));
	_totalClients++;
	return;
}

void		Server::receiveMsgs()
{
	std::string buffer;
	char buf[100];
	ssize_t i = 1;

	for (ssize_t it = 0; it < _totalClients ; it++)
	{
		i = recv(_client[it].getSock(), &buf, sizeof(buf) - 1, MSG_DONTWAIT);
		if (i > 0 )
		{
			buf[i] = '\0';
			_client[it].setBuffer(buf);
			_client[it].setUpdate(1);
		}
	}
	return;
}

int		Server::sendMsgs(void)
{
	for (ssize_t it = 0; it < _totalClients ; it++)
	{
		if (_client[it].getAnswerMsgs() != 0)
		{
			if (_client[it].getPing() == 1)
				this->replyPong(it), _client[it].setPing(0);
			else if (this->RPLSwitch(it))
				return (1);
		}
	}
	return (0);
}

void	Server::parseMsgs()
{
	for (ssize_t it = 0; it < _totalClients ; it++)
	{
		if (_client[it].getUpdate() == 1)
			_client[it].parseMsgs();
	}
}
