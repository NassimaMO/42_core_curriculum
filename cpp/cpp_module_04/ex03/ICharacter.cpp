#include "ICharacter.hpp"

ICharacter::ICharacter( void )
{
    m_num = 0;
}

ICharacter::ICharacter( std::string _name )
{
    m_num = 0;
    setName( _name );
}

ICharacter::ICharacter( const ICharacter& cp )
{
    *this = cp;
}

ICharacter& ICharacter::operator=( const ICharacter& cp )
{
    this->m_num = m_num;
    this->tab = tab_cp(tab);
    this->name = name;
    return ( *this );
}

ICharacter::~ICharacter( void )
{
    delete  m_unequiped;
}

void    ICharacter::setName( std::string _name )
{
    name = _name;
}

std::string ICharacter::getName( void ) const
{
    return ( name );
}

void    ICharacter::equip( AMateria* m )
{
    int i = 0;

    if (m_num == 4)
        return ();
    tab[m_num - 1] = m->clone();
    m_num++;
}

void    ICharacter::unequip( int idx )
{
    if ( i >= 0 && i < 4 )
    {
        m_unequiped = tab[idx];
        tab[idx] = 0;
    }
}

void    ICharacter::use( int idx, ICharacter& target )
{
    if ( i >= 0 && i < 4 )
    {
        tab[idx].use( target );
    }
}