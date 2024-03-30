# include "ft_irc.hpp"

//RPL: successful registration
void Clients::sendRPL001(void) //WELCOME
{
	std::string	RPL001 = ":127.0.0.1 001 " + _nick + " Welcome to the Internet Relay Network, " + _nick + "\r\n";
	send(_sockfd, RPL001.c_str(), RPL001.length(), MSG_DONTWAIT);
}

void Clients::sendRPL002(void) //YOURHOST
{
	std::string	RPL002 = ":127.0.0.1 002 " + _nick + " Your host is nahima, running version 1.0\r\n";
	send(_sockfd, RPL002.c_str(), RPL002.length(), MSG_DONTWAIT);
}

void Clients::sendRPL003(void) //CREATED
{
	std::string	RPL003 = ":127.0.0.1 003 " + _nick + " This server was created today\r\n";
	send(_sockfd, RPL003.c_str(), RPL003.length(), MSG_DONTWAIT);
}

void Clients::sendRPL004(void) //MYINFO
{
	std::string	RPL004 = ":127.0.0.1 004 " + _nick + " nahima version 1.0 " + _name + " +i\r\n";
	send(_sockfd, RPL004.c_str(), RPL004.length(), MSG_DONTWAIT);
}

void Clients::sendPong(void) //PONG: NEED TO FIND OUT HOW TO WRITE IT
{
	std::string	RPLPong = ":127.0.0.1 PONG 127.0.0.1\r\n";
	send(_sockfd, RPLPong.c_str(), RPLPong.length(), MSG_DONTWAIT);
}

//RPL: CHANNEL
/*void sendRPL331(void) //NO TOPIC
{
	std::string	RPL331 = ":127.0.0.1 331 " + "<channel> No topic is set\r\n";
	send(_sockfd, RPL331.c_str(), RPL331.length(), MSG_DONTWAIT);
}

void sendRPL332(void) //TOPIC
{
	std::string	RPL332 = ":127.0.0.1 332 " + "<channel> <topic>\r\n";
	send(_sockfd, RPL332.c_str(), RPL332.length(), MSG_DONTWAIT);
}

void Clients::sendRPL341(void) // INVITE (The invite has been sent)
{
	std::string	RPL341 = ":127.0.0.1 341 " + _nick + "<channel> " + _nick + "\r\n";
	send(_sockfd, RPL341.c_str(), RPL341.length(), MSG_DONTWAIT);
}*/

//ERRORS

void	Clients::sendErrPass(void)
{
	std::string	Err464 = ":127.0.0.1 464 " + _nick + " Password incorrect\r\n";
	send(_sockfd, Err464.c_str(), Err464.length(), MSG_DONTWAIT);
}

void	Clients::sendErrNickCollision(void)
{
	std::string	Err436 = ":127.0.0.1 436 " + _nick + " Nickname collision KILL from " + _name + "@nahima\r\n";
	send(_sockfd, Err436.c_str(), Err436.length(), MSG_DONTWAIT);
}
