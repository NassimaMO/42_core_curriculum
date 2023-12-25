#include "Character.hpp"

Character::Character( void )
{
    m_num = 0;
    for(int i = 0; i < 4; i++ )
        tab[i] = 0;
    name = "unknown";
    std::cout << "Character created." << std::endl;
}

Character::Character( std::string _name )
{
    m_num = 0;
    for(int i = 0; i < 4; i++ )
        tab[i] = 0;
    name = _name;
    std::cout << "Character created." << std::endl;
}

Character::Character( const ICharacter& cp )
{
    *this = cp;
}

Character& Character::operator=( const Character& cp )
{
    this->m_num = m_num;
    for(int i = 0; i < 4; i++ )
        tab[i] = cp.tab[i]->clone();
    this->name = name;
    return ( *this );
}

Character::~Character( void )
{
    for ( int i = 0; i < 4; i++ )
    {
        if (tab[i])
            delete tab[i];
    }
    std::cout << "Character destroyed." << std::endl;
}

std::string const& Character::getName( void ) const
{
    return ( name );
}

void    Character::equip( AMateria* m )
{
    if (!m || m_num == 4)
        return;
    for ( int i = 0; i < 4; i++ )
    {
        if (tab[i] == 0)
        {
            tab[i] = m;
            return ;
        }
    }
    m_num++;
}

void    Character::unequip( int idx )
{
    if ( idx >= 0 && idx < 4 )
    {
        delete tab[idx];
        tab[idx] = 0;
    }
}

void    Character::use( int idx, ICharacter& target )
{
    if ( idx >= 0 && idx < 4 )
    {
        if (tab[idx])
            tab[idx]->use( target );
    }
}