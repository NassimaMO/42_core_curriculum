#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->setName("default");
    this->setHit(100);
    this->setEnergy(50);
    this->setAttack(20);
}

ScavTrap::ScavTrap( std::string name )
{
    this->setName(name);
    this->setHit(100);
    this->setEnergy(50);
    this->setAttack(20);
    std::cout << "ScavTrap created." << std::endl;
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