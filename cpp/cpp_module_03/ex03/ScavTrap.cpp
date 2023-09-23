#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    _name = "default";
    _hit = 100;
    _energy = 50;
    _attack = 20;
}

ScavTrap::ScavTrap( std::string name )
{
    _name = name;
    _hit = 100;
    _energy = 50;
    _attack = 20;
    std::cout << "ScavTrap created." << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& cp )
{
    *this = cp;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& cp)
{
    _name = cp._name;
    _hit = cp._hit;
    _energy = cp._energy;
    _attack = cp._attack;
    return ( *this );
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destroyed." << std::endl;
}

void    ScavTrap::attack( const std::string& target )
{
    if (_energy && _hit)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
        _energy--;
    }
    else if (!_energy)
        std::cout << "ScavTrap " << _name << " has no energy points left." << std::endl;
}

void    ScavTrap::guardGate( void )
{
    std::cout << "ScavTrap " << _name << " is now in gatekeeper mode." << std::endl;
}