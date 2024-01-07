#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class   Intern
{
    private:

    public:

    Intern( void );
    Intern( const Intern& i );
    Intern&                 operator=( const Intern& i );
    AForm*  makeShrubberyCreationForm( std::string target );
    AForm*    makeRobotomyRequestForm( std::string target );
    AForm* makePresidentialPardonForm( std::string target );
    AForm*                   makeForm( std::string name, std::string target );
    ~Intern();
};

#endif