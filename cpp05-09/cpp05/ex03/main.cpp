#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
    {
        Bureaucrat  bc("Jim", 50);
        Intern      eight;
        AForm*       l = eight.makeForm( "robotomy request", "Georges" );
        if ( l )
        {
            bc.signForm( *l );
            bc.executeForm( *l );
            delete l;
        }
    }
    return ( 0 );
}