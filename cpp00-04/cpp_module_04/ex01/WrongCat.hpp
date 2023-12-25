#ifndef WRONGWrongCAT_HPP
# define WRONGWrongCAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class       WrongCat : public WrongAnimal
{
    public:

    WrongCat( void );
    WrongCat( const WrongCat& cp );
    WrongCat&   operator=( const WrongCat& clap );
    ~WrongCat();

    std::string getType( void ) const;

    void makeSound( void ) const;

    private:

};

#endif