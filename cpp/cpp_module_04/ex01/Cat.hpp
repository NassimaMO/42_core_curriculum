#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

class       Cat : public Animal
{
    public:

    Cat( void );
    Cat( const Cat& cp );
    Cat&   operator=( const Cat& cp );
    virtual ~Cat();

    std::string getType( void ) const;

    void makeSound( void ) const;
    std::string getBrainIdea( int index );
    void        setBrainIdea( std::string idea, int index );

    private:

    Brain *brain;

};

#endif