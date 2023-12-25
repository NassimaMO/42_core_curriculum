#include "AMateria.hpp"

AMateria::AMateria( void )
{
    std::cout << "AMateria created." << std::endl;
    type = "unknown";
}

AMateria::AMateria( std::string const & type )
{
    std::cout << "AMateria created." << std::endl;
    this->type = type;
}

AMateria::AMateria( const AMateria& cp )
{
    *this = cp;
}

AMateria& AMateria::operator=( const AMateria& cp )
{
    if (this != &cp)
        this->type = cp.type;
    return ( *this );
}

AMateria::~AMateria( void )
{
    std::cout << "AMateria destroyed." << std::endl;
}

std::string const & AMateria::getType( void ) const
{
    return (type);
}

AMateria* AMateria::clone( void ) const
{
    std::cout << "Cloning AMateria." << std::endl;
    return ( (AMateria *) this );
}

void AMateria::use( ICharacter& target )
{
    std::cout << "* Using AMateria on " << target.getName() << " *" << std::endl;
}