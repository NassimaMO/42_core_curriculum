#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : IMateriaSource()
{
    m_num = 0;
    for(int i = 0; i < 4; i++ )
        tab[i] = 0;
    std::cout << "MateriaSource found." << std::endl;
}

MateriaSource::MateriaSource( const IMateriaSource& cp ) : IMateriaSource()
{
    *this = cp;
}

MateriaSource& MateriaSource::operator=( const MateriaSource& cp )
{
    if (this != &cp)
    {
        for(int i = 0; i < 4; i++ )
            tab[i] = cp.tab[i];
    }
    return ( *this );
}

MateriaSource::~MateriaSource( void )
{
    for ( int i = 0; i < 4; i++ )
    {
        if (tab[i])
            delete tab[i];
    }
    std::cout << "MateriaSource disappeared." << std::endl;
}

void    MateriaSource::learnMateria( AMateria* cp )
{
    if (m_num == 4)
        return;
    for ( int i = 0; i < 4; i++ )
    {
        if (tab[i] == 0)
        {
            tab[i] = cp;
            return ;
        }
    }
    m_num++;
}

AMateria*    MateriaSource::createMateria( std::string const & type )
{
    for ( int i = 0; i < 4; i++)
    {
        if (tab[i] && tab[i]->getType() == type)
            return ( tab[i]->clone() );
    }
    return ( NULL );
}