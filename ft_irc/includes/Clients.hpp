#ifndef CLIENT_HPP
# define CLIENT_HPP
# include "ft_irc.hpp"
# include <netinet/in.h>

class Clients
{
	private:

	std::string				_nick;
	std::string				_name;
	std::string				_password;
	std::string				_buffer;
	int						_answerMsgs;
	int						_sockfd;
	bool					_ping;
	bool					_update;
	//std::string				*_invite;

	//struct  sockaddr_in	serv_addr;

	public:

		Clients(int socket_client);
		~Clients();
		void		setBuffer(std::string	buf);
		int			getSock(void);
		std::string	getPassword(void);
		std::string	getNick(void);
		int			getAnswerMsgs(void);
		void		setAnswerMsgs(int answerMsgs);
		void		setUpdate(bool bin);	
		bool		getUpdate(void);
		bool		getPing(void);
		void		setPing(bool i);
		void		sendMsgs(void);
		void		parseMsgs(void);
		void		parse(std::string command, std::string &src);

		////////////////////Sent RPL////////////////////
		void		sendRPL001(void);
		void		sendRPL002(void);
		void		sendRPL003(void);
		void		sendRPL004(void);
		void		sendPong(void);

		////////////////////Sent Err////////////////////
		void		sendErrPass(void);
		void		sendErrNickCollision(void);


};

#endif
