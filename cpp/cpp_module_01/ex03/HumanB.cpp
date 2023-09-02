// do not necessarily have a weapon
#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
    this->m_name = name;
    this->m_weapon = nullptr;
}

HumanB::~HumanA( void )
{
    /**/
}

void    HumanB::attack( void )
{
    if (this->m_weapon == nullptr)
        return (std::cout << this->m_name << " don't have any weapon therefore" << this->m_name << " may not attack." << std::endl);
    std::cout << this->m_name << " attacks with their " << this->m_weapon.getType() << std::endl;
}

void    HumanB::setWeapon( Weapon  weapon )
{
    this->m_weapon = weapon;
}