#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->setName("default");
    this->setHit(100);
    this->setEnergy(100);
    this->setAttack(30);
}

FragTrap::FragTrap( std::string name )
{
    this->setName(name);
    this->setHit(100);
    this->setEnergy(100);
    this->setAttack(30);
    std::cout << "FragTrap created." << std::endl;
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
    std::cout << "A positive high fives request." << std::endl;
}
