#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
    private:

    public:

    Cure( void );
    Cure( const Cure& cp );
    Cure&       operator=( const Cure& cp );
    AMateria*   clone( void ) const;
    void        use( ICharacter& target );
    ~Cure( void );

};

#endif