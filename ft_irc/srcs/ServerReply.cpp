#include "ft_irc.hpp"

# define RPL_W "001"

int Server::replyVoid(ssize_t it)
{
	(void)it;
	return (0);
}


int	Server::replyWelcome(ssize_t it)
{
	if (_password != "")
	{
		if (verif(it) > 0)
			return (1);
		_client[it].sendRPL001();
		_client[it].sendRPL002();
		_client[it].sendRPL003();
		_client[it].sendRPL004();
		_client[it].setAnswerMsgs(0);
		return (0);
	}
	return (0);
}

int Server::replyJoin(ssize_t it)
{
	(void)it;
	return (0);
}

void	Server::replyPong(ssize_t it)
{
	_client[it].sendPong();
}

int Server::RPLSwitch(ssize_t it)
{
	int		(Server::*reply[3])(ssize_t) = { &Server::replyVoid, &Server::replyWelcome, &Server::replyJoin };

	if ((this->*reply[_client[it].getAnswerMsgs()])(it))
		return (1);
	return (0);
}
