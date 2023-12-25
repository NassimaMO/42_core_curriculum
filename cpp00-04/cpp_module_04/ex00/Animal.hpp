#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class       Animal
{
    public:

    Animal( void );
    Animal( const Animal& cp );
    Animal&   operator=( const Animal& cp );
    virtual ~Animal();

    std::string getType( void ) const;

    virtual void makeSound( void ) const;

    protected:

    std::string type;

};

#endif