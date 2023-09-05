#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : m_weapon(weapon), m_name(name)
{
    /**/
}

HumanA::~HumanA( void )
{
    /**/
}

void    HumanA::attack( void )
{
    std::cout << this->m_name << " attacks with their " << this->m_weapon.getType() << std::endl;
}