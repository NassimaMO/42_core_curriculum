#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _name("default"), _hit(100), _energy(50), _attack(20)
{
    /**/
}

ScavTrap::ScavTrap( std::string name ) : _name(name), _hit(100), _energy(50), _attack(20)
{
    std::cout << "ScavTrap " << _name << " created." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destroyed." << std::endl;
}
