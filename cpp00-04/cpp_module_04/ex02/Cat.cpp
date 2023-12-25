#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : brain(NULL)
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat created." << std::endl;
}

Cat::Cat( const Cat& cp ) : brain(NULL)
{
    *this = cp;
}

Cat& Cat::operator=( const Cat& cp)
{
    if (this != &cp)
    {
        type = cp.getType();
        if (!brain)
            brain = new Brain;
        *brain = *cp.brain;
    }
    return ( *this );
}

Cat::~Cat( void )
{
    if (brain)
        delete brain;
    std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound( void ) const
{
    std::cout << "*Cat noise*" << std::endl;
}

std::string Cat::getType( void ) const
{
    return ( type );
}

std::string Cat::getBrainIdea(int index)
{
    return ( brain->getIdea( index ) );
}

void        Cat::setBrainIdea( std::string idea, int index )
{
    brain->setIdea(idea, index);
}