#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    _name = "default";
    this->ClapTrap::_name = _name + "_clap_name";
    this->FragTrap::_hit = 100;
    this->ScavTrap::_energy = 50;
    this->FragTrap::_attack = 30;
}

DiamondTrap::DiamondTrap( std::string name )
{
    _name = name;
    this->ClapTrap::_name = _name + "_clap_name";
    this->FragTrap::_hit = 100;
    this->ScavTrap::_energy = 50;
    this->FragTrap::_attack = 30;
    std::cout << "ScavTrap created." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "ScavTrap destroyed." << std::endl;
}

void    DiamondTrap::whoAmI( void )
{
    std::cout << _name << " or " << this->ClapTrap::_name << std::endl;
}