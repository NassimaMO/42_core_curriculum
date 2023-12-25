#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : brain(NULL)
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog created." << std::endl;
}

Dog::Dog( const Dog& cp ) : brain(NULL)
{
    *this = cp;
}

Dog& Dog::operator=( const Dog& cp)
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

Dog::~Dog( void )
{
    if (brain)
        delete brain;
    std::cout << "Dog destroyed." << std::endl;
}

void    Dog::makeSound( void ) const
{
    std::cout << "*Dog noise*" << std::endl;
}

std::string Dog::getType( void ) const
{
    return ( type );
}

std::string Dog::getBrainIdea(int index)
{
    return ( brain->getIdea( index ) );
}

void        Dog::setBrainIdea( std::string idea, int index )
{
    brain->setIdea(idea, index);
}