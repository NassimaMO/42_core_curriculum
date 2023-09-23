#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    _name = "default";
    _hit = 100;
    _energy = 100;
    _attack = 30;
}

FragTrap::FragTrap( std::string name )
{
    _name = name;
    _hit = 100;
    _energy = 100;
    _attack = 30;
    std::cout << "FragTrap created." << std::endl;
}

FragTrap::FragTrap( const FragTrap& cp )
{
    *this = cp;
}

FragTrap&   FragTrap::operator=(const FragTrap& cp)
{
    _name = cp._name;
    _hit = cp._hit;
    _energy = cp._energy;
    _attack = cp._attack;
    return ( *this );
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destroyed." << std::endl;
}

void    FragTrap::attack( const std::string& target )
{
    if (_energy && _hit)
    {
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
        _energy--;
    }
    else if (!_energy)
        std::cout << "FragTrap " << _name << " has no energy points left." << std::endl;
}

void    FragTrap::highFivesGuys( void )
{
    std::cout << "Give me a high five !!" << std::endl;
}
