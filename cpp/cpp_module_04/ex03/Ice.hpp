#include "AMateria.hpp"

class Ice : public AMateria
{
    private:

    public:

    Ice( void );
    Ice( const Ice& cp );
    Ice&            operator=( const Ice& cp );
    Ice*            clone( void );
    void            use( ICharacter& target );
    ~Ice( void );

}