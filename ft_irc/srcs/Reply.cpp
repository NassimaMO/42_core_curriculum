#include "ft_irc.hpp"

# define RPL_W "001"

sendRPL001(Server server)
{
	char RPL_buf[77] = ":127.0.0.1 001 tbae Welcome to the Internet Relay Network tbae!tbae@tbae\r\n";
	send(socket_client, RPL_buf, sizeof(RPL_buf), MSG_DONTWAIT);
}
