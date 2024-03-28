#ifndef CHANNEL_HPP
# define CHANNEL_HPP
# include "ft_irc.hpp"

# define CH_INVITE 2
# define CH_PASSWORD 1
# define CH_OPEN 0

class	Channel
{
	private :
		std::string	_name;
		std::string	_topic;
		std::string	_password;
		std::string _member[];
		std::string	_operator[];
		int			access;
		int			maxMembers;

	public :
		
};

#endif
