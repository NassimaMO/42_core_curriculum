#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"

class AMateria;

class ICharacter
{
    private:

    std::string  name;
    AMateria    *tab[4];
    AMateria    *m_unequiped;
    int         m_num;

    public:

    ICharacter( void );
    ICharacter( std::string _name);
    ICharacter( const ICharacter& cp );
    virtual     ~ICharacter() {}
    virtual     ICharacter& operator=( const ICharacter& cp ) = 0;
    virtual     void    setName( std::string _name ) = 0;
    virtual     std::string const & getName() const = 0;
    virtual     void equip( AMateria* m ) = 0;
    virtual     void unequip( int idx ) = 0;
    virtual     void use( int idx, ICharacter& target ) = 0;
};

#endif