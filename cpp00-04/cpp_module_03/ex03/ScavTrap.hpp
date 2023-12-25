#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class   ScavTrap : virtual public ClapTrap
{
    public:

    ScavTrap( void );
    ScavTrap( std::string name );
    ScavTrap( const ScavTrap& cp );
    ScavTrap&   operator=( const ScavTrap& clap );
    ~ScavTrap();

    void    attack( const std::string& target );
    void    guardGate( void );

    private:

    /**/
};

#endif