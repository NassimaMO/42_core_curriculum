#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:

    std::string type;

    public:

    AMateria( void );
    AMateria( std::string const & type );
    AMateria( const AMateria& cp );
    AMateria&           operator=( const AMateria& cp );
    std::string const & getType( void ) const;
    virtual AMateria*   clone( void ) const = 0;
    virtual void        use( ICharacter& target );
    virtual ~AMateria( void );
};

#endif