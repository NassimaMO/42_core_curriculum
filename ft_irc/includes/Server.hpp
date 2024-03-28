#ifndef SERVER_HPP
# define SERVER_HPP

# include "ft_irc.hpp"

class Server
{
    private:

	//Clients					*_client;
    std::vector<struct pollfd>  _fds;
    std::string                 _password;
    std::string                 _port;
	std::string                 _buffer;
    int                         _sockfd;
	int                         _totalClients;
    struct  sockaddr_in         serv_addr;

    public:

	Server(std::string password, std::string port);
	~Server();
	std::string	&getPort(void);
	std::string	&getPassword(void);
    std::vector<struct pollfd>  &getFds(void);
    int                         getTotalClients(void);

    void    setSocket(void);
    int    setServ(void);
    int     waitClients(void);
    std::string     receiveMsgs(int sockfd);
    int     sendMsgs(void);
};

#endif
