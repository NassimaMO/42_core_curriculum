#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
    private:

    public:

    Ice( void );
    Ice( const Ice& cp );
    Ice&        operator=( const Ice& cp );
    Ice*   clone( void ) const;
    void        use( ICharacter& target );
    ~Ice( void );

};

#endif