#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
    {
        Bureaucrat              bc( "Jim", 50);
        ShrubberyCreationForm   l("home");

        bc.signForm( l );
        bc.executeForm( l );
    }
    {
        std::cout << std::endl;
        Bureaucrat              bc( "Erica", 20);
        RobotomyRequestForm     l("Timmy");

        bc.signForm( l );
        bc.executeForm( l );
    }
    {
        std::cout << std::endl;
        Bureaucrat              bc( "Nan", 2);
        PresidentialPardonForm  l("no");

        bc.signForm( l );
        bc.executeForm( l );
    }
    return ( 0 );
}