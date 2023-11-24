#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
    private:

    public:

    Cure( void );
    Cure( const Cure& cp );
    Cure&            operator=( const Cure& cp );
    Cure*            clone( void );
    void             use( ICharacter& target );
    ~Cure( void );

}

#endif