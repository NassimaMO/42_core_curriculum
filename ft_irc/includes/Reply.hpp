#ifndef REPLY_HPP
# define REPLY_HPP
# include "ft_irc.hpp"

void sendRPL001(std::string nick, int sockfd);
void sendRPL002(std::string nick, int sockfd);
void sendRPL003(std::string nick, int sockfd);

#endif
