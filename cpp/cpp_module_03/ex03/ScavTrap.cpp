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

void    ScavTrap::guardGate( void )
{
    std::cout << "ScavTrap is now in gatekeeper mode." << std::endl;
}