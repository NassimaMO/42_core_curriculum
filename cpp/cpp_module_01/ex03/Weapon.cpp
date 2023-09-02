#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
    this->m_type = type;
}

Weapon::~Weapon( void )
{
    /**/
}

const std::string&  Weapon::getType( void )
{
    return ( this->m_type );
}

void    Weapon::setType( std::string type )
{
    this->m_type = type;
}