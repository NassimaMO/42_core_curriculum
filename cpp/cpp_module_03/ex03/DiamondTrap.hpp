#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class   DiamondTrap : public ClapTrap
{
    public:

    DiamondTrap( void );
    DiamondTrap( std::string name );
    ~DiamondTrap();

    void whoAmI();

    private:

    std::string _name;

};

#endif