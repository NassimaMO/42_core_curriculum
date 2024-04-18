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
<<<<<<< HEAD
	std::string				_channel;
	std::string				_ping;
	std::string				_mode;
	std::string				_msg;
	std::string				_kick;
	std::string				_topic;
	int						_answerMsgs;
	int						_sockfd;
	bool					_update;
	std::string				_invite;
=======
	int						_answerMsgs;
	int						_sockfd;
	bool					_ping;
	bool					_update;
	//std::string				*_invite;
>>>>>>> d716035d2eb73105aa66ebd283be720780c86a21

	//struct  sockaddr_in	serv_addr;

	public:

		Clients(int socket_client);
		~Clients();
<<<<<<< HEAD

		void		sendMsgs(void);
		void		parseMsgs(void);
		void		parseError(void);
		void		parse(std::string command, int i, std::string &src);

		///////////////////Get and Set///////////////////
		std::string	getNick(void);
		std::string	getPassword(void);
		void		setPassword(std::string str);
		std::string	getBuffer(void);
		void		setBuffer(std::string buf);
		std::string	getChannel();
		void		setChannel(std::string	src);
		std::string	getMode();
		int			getAnswerMsgs(void);
		void		setAnswerMsgs(int answerMsgs);
		int			getSock(void);
		bool		getUpdate(void);
		void		setUpdate(bool bin);
		std::string	getPing(void);
		void		setPing(std::string string);
		std::string	getMsg();
		void		setMsg(std::string msg);
		std::string	getInvite(void);
		std::string	getKick(void);
		std::string	getTopic();
		void		setTopic(std::string topic);

		////////////////////Sent RPL////////////////////
		void		sendPong(void);
=======
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
>>>>>>> d716035d2eb73105aa66ebd283be720780c86a21
		void		sendRPL001(void);
		void		sendRPL002(void);
		void		sendRPL003(void);
		void		sendRPL004(void);
<<<<<<< HEAD
		void 		sendRPL331(std::string name);
		void 		sendRPL341(std::string channel, std::string invited);
		void 		sendRPL332(std::string channel, std::string topic);
		void 		sendRPL353(std::string channel, std::string listName);
		void 		sendRPL366(std::string channel);
		void		sendPrivMsg(std::string channel, std::string msg, std::string name);
		void 		sendKickMsg(std::string channel, std::string client, std::string name, std::string reason);
=======
		void		sendPong(void);
>>>>>>> d716035d2eb73105aa66ebd283be720780c86a21

		////////////////////Sent Err////////////////////
		void		sendErrPass(void);
		void		sendErrNickCollision(void);
<<<<<<< HEAD
		void		sendErrBadKey(std::string channel);
		void		sendErrInviteOnlyChan(std::string channel);
		void		sendErrChannelIsFull(std::string channel);
		void		sendErrNoSuchNick(std::string nick);
		void		sendErrNoSuchChannel(std::string channel);
		void		sendErrNotOnChannel(std::string channel);
		void		sendErrNeedMoreParams(std::string command);
		void		sendErrNoPrivileges();
=======


>>>>>>> d716035d2eb73105aa66ebd283be720780c86a21
};

#endif
