#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <string>

class       Cat : public Animal
{
    public:

    Cat( void );
    Cat( const Cat& cp );
    Cat&   operator=( const Cat& clap );
    virtual ~Cat();

    std::string getType( void ) const;

    void makeSound( void ) const;

    private:

};

#endif