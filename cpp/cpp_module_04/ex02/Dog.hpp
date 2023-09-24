#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

class       Dog : public Animal
{
    public:

    Dog( void );
    Dog( const Dog& cp );
    Dog&   operator=( const Dog& cp );
    virtual ~Dog();

    std::string getType( void ) const;

    void makeSound( void ) const;
    std::string getBrainIdea( int index );
    void        setBrainIdea( std::string idea, int index );

    private:

    Brain *brain;
};

#endif