#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class   FragTrap : public ClapTrap
{
    public:

    FragTrap( void );
    FragTrap( std::string name );
    FragTrap( const FragTrap& cp );
    FragTrap&   operator=( const FragTrap& clap );
    ~FragTrap();

    void    attack( const std::string& target );
    void    highFivesGuys( void );

    private:

    /**/
};

#endif