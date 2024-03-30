#ifndef SERVER_HPP
# define SERVER_HPP

# include "ft_irc.hpp"
# include "Clients.hpp"

class Clients;

class Server
{
    private:

		std::vector<Clients>		_client;
	    std::vector<struct pollfd>  _fds;
	    std::string                 _password;
	    std::string                 _port;
	    int                         _sockfd;
		int                         _totalClients;
		int							_ext;
	    struct  sockaddr_in         serv_addr;

		/////////////////////Init Serv/////////////////////
	    int							initSocket(void);
	    int							initServ(void);

    public:

		Server(std::string password, std::string port);
		~Server();

		////////////////////GET AND SET////////////////////
	    std::vector<struct pollfd>	&getFds(void);
		std::string					&getPort(void);
		std::string					&getPassword(void);
		int							getTotalClients(void);
		int							getExt(void);

		////////////////////// Reply //////////////////////
		int							RPLSwitch( ssize_t it);
		int							replyVoid(ssize_t it);
		int							replyWelcome( ssize_t it);
		int							replyJoin(ssize_t it);

		void						replyPong(ssize_t it);

	    void						waitClients(void);
	    void						receiveMsgs(void);
	    int							sendMsgs(void);
		void						parseMsgs(void);

		////////////////////// Verif //////////////////////
		int							verif(ssize_t it);
		void						deleteClient(ssize_t it);
};

#endif
