#include "Clients.hpp"
#include "ft_irc.hpp"

Clients::Clients(int socket_client) : _sockfd(socket_client)
{
	_update = 0;
	_password = "";
	_nick = "";
	_answerMsgs = 0;
}

Clients::~Clients()
{

}

void	Clients::setBuffer(std::string buf)
{
	_buffer += buf;
	return;
}

int	Clients::getSock(void)
{
	return (_sockfd);
}

void	Clients::setUpdate(bool bin)
{
	_update = bin;
}

bool	Clients::getUpdate(void)
{
	return(_update);
}

std::string	Clients::getPassword(void)
{
	return (_password);
}
std::string	Clients::getNick(void)
{
	return (_nick);
}

bool	Clients::getPing(void)
{
	return (_ping);
}

void	Clients::setPing(bool i)
{
	_ping = i;
}

void	Clients::parse(std::string command, std::string &src)
{
	std::string bufferPart(_buffer.begin(), _buffer.begin() + command.length());

	if (bufferPart == command)
	{
		ssize_t it = command.length();
		while (_buffer[it] != '\0' && (_buffer[it] != '\r' || _buffer[it + 1] != '\n'))
			it++;
		if (_buffer[it] == '\r' && _buffer[it + 1] == '\n')
		{
			if (command != "CAP LS")
				src = _buffer.substr(command.length() + 1, it - 5);
			if (command == "NICK")
				_answerMsgs = 1;
			if (command == "PING")
				_ping = 1;
			_buffer.erase(0, it + 2);
		}
	}
}

void	Clients::parseMsgs()
{
	std::cout << _buffer << std::endl;
	std::string command[] = {"CAP LS", "PASS", "NICK", "USER", "PING"};
	std::string	*src[] = {NULL, &_password, &_nick, &_name, NULL};

	for (int i = 0; i < 4; i++)
		parse(command[i], *src[i]);
	_update = 0;
}

void	Clients::sendMsgs(void)
{
	return;
}

int		Clients::getAnswerMsgs()
{
	return (_answerMsgs);
}

void		Clients::setAnswerMsgs(int answerMsgs)
{
	_answerMsgs = answerMsgs;
	return;
}
