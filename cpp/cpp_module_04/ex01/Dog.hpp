#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <string>

class       Dog : public Animal
{
    public:

    Dog( void );
    Dog( const Dog& cp );
    Dog&   operator=( const Dog& clap );
    ~Dog();

    std::string getType( void ) const;

    void makeSound( void ) const;

    private:

};

#endif