#include "Server.hpp"

void	Server::deleteClient(ssize_t it)
{
	close(_client[it].getSock());
	_client.erase(_client.begin() + it);
	_totalClients--;
}

int Server::verif(ssize_t it)
{
	if (_password != _client[it].getPassword())
		return (_client[it].sendErrPass(), this->deleteClient(it), 1);
	for (int i = 0; i < _totalClients; i++)
	{
		if (i != it && _client[i].getNick() == _client[it].getNick())
			return (_client[it].sendErrNickCollision(), this->deleteClient(it), 1);
	}
	return (0);
}
