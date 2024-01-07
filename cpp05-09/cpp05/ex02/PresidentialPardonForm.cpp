#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm( "Presidential Pardon Form", 25, 5 ), m_target( target )
{
    std::cout << "PresidentialPardonForm created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& f ) : AForm( "Presidential Pardon Form", 25, 5 )
{
    *this = f;
}

PresidentialPardonForm&  PresidentialPardonForm::operator=( const PresidentialPardonForm& f )
{
    if ( this != &f )
        m_target = f.m_target;
    return ( *this );
}

void PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
    if ( getSignature() == false )
        throw AForm::NotSignedException();
    if ( executor.getGrade() > getGradeRequiredExec() )
        throw AForm::GradeTooLowException();
    std::cout << m_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destroyed." << std::endl;
}