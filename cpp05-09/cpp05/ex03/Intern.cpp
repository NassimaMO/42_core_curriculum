#include "Intern.hpp"

Intern::Intern( void )
{
    std::cout << "Intern recruted." << std::endl;
}

Intern::Intern( const Intern& i )
{
    *this = i;
}

Intern& Intern::operator=( const Intern& i )
{
    ( void ) i;
    return ( *this );
}

AForm*  Intern::makeShrubberyCreationForm( std::string target )
{
    return ( new ShrubberyCreationForm( target ) );
}

AForm*    Intern::makeRobotomyRequestForm( std::string target )
{
    return ( new RobotomyRequestForm( target ) );
}

AForm* Intern::makePresidentialPardonForm( std::string target )
{
    return ( new PresidentialPardonForm( target ) );
}

AForm*   Intern::makeForm( std::string name, std::string target )
{
    std::string tab[] = { "shrubbery creation", "robotomy request", "presidential pardon" };
    AForm        *(Intern::*funcPtr[3])(std::string target) = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
    int         i = 0;
    while ( i < 3 )
    {
        if ( !name.compare( tab[i] ) )
        {
            std::cout << "Intern creates " << name << " form." << std::endl;
            return ( (this->*funcPtr[i])( target ) );
        }
        i++;
    }
    std::cout << name << ": No such form found. You're going to get me fired." << std::endl;
    return ( 0 );
}


Intern::~Intern()
{
    std::cout << "Intern fired." << std::endl;
}