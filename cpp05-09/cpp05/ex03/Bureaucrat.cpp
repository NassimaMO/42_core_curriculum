#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade ) : m_name( name ), m_grade( grade )
{
    std::cout << "Bureaucrat created." << std::endl;    
    if ( this->m_grade > 150 )
        throw Bureaucrat::GradeTooLowException();
    else if ( this->m_grade < 1 )
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat( const Bureaucrat& bc ) : m_name( bc.getName() )
{
    *this = bc;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& bc )
{
    if ( this != &bc )
    {
        this->m_grade = bc.m_grade;
    }
    return (*this);
}

void        Bureaucrat::gradeLevelUp( void )
{
    if ( this->m_grade == 1 )
        throw Bureaucrat::GradeTooHighException();
    this->m_grade--;
}

void        Bureaucrat::gradeLevelDown( void )
{
    if ( this->m_grade == 150 )
        throw Bureaucrat::GradeTooLowException();
    this->m_grade++;
}

std::string Bureaucrat::getName( void ) const
{
    return( this->m_name );
}

int         Bureaucrat::getGrade( void ) const
{
    return ( this->m_grade );
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destroyed" << std::endl;
}

void    Bureaucrat::signForm( AForm& f )
{
    try
    {
        if ( f.getSignature() == false )
            f.beSigned( *this );
    }
    catch ( std::exception & e )
    {
        std::cout << e.what() << std::endl;
    }
}

void        Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute( *this );
        std::cout << m_name << " executed " << form.getName() << "." << std::endl;
    }
    catch ( std::exception & e )
    {
        std::cout << e.what() << std::endl;
    }
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ( "Grade too high." );
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ( "Grade too low." );
}

std::ostream& operator<<( std::ostream& o, const Bureaucrat& bc )
{
    o << bc.getName() << ", bureaucrat grade " << bc.getGrade() << ".";
    return o;
}