#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    this->setName("default");
    this->setHit(100);
    this->setEnergy(50);
    this->setAttack(20);
}

DiamondTrap::DiamondTrap( std::string name )
{
    this->setName(name);
    this->setHit(100);
    this->setEnergy(50);
    this->setAttack(20);
    std::cout << "ScavTrap created." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "ScavTrap destroyed." << std::endl;
}

void    DiamondTrap::whoAmI( void )
{
    std::cout << _name << " or " << _name << std::endl;
}