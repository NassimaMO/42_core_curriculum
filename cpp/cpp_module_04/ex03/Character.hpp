#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
    private:

    std::string name;
    AMateria    *tab[4];
    int         m_num;

    public:

    Character( void );
    Character( std::string _name );
    Character( const ICharacter& cp );
    Character& operator=( const Character& cp );
    std::string const & getName() const;
    void        equip( AMateria* m );
    void        unequip( int idx );
    void        use( int idx, ICharacter& target );
    ~Character();
};

#endif