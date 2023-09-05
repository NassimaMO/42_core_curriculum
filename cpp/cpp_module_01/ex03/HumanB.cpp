// do not necessarily have a weapon
#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
    this->m_name = name;
}

HumanB::~HumanB( void )
{
    /**/
}

void    HumanB::attack( void )
{
    if (this->m_weapon->getType().empty())
        return (std::cout << this->m_name << " don't have any weapon therefore" << this->m_name << " may not attack." << std::endl, void());
    std::cout << this->m_name << " attacks with their " << this->m_weapon->getType() << std::endl;
}

void    HumanB::setWeapon( Weapon  &weapon )
{
    this->m_weapon = &weapon;
}