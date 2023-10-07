#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class   DiamondTrap : public ScavTrap, public FragTrap
{
    public:

    DiamondTrap( void );
    DiamondTrap( std::string name );
    ~DiamondTrap();

    using ScavTrap::attack;
    void whoAmI();

    private:

    std::string _name;

};

#endif