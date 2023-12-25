#include "Brain.hpp"
#include <iostream>

Brain::Brain( void )
{
    std::cout << "Brain created." << std::endl;
}
    
Brain::~Brain()
{
    std::cout << "Brain destroyed." << std::endl;
}
    
Brain::Brain( const Brain& cp )
{
    *this = cp;
}

Brain& Brain::operator=( const Brain& cp )
{
    if (this != &cp)
    {
        for (int i = 0; i < 100; i++ )
            _ideas[i] = cp._ideas[i];
    }
    return ( *this );
}

std::string Brain::getIdea( int index )
{
    return ( _ideas[index] );
}

void    Brain::setIdea( std::string idea, int index )
{
    if (index >= 0 && index < 100)
        _ideas[index] = idea;
}