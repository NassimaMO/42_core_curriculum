#include "AForm.hpp"

AForm::AForm( std::string name, int gradeRequiredSign, int gradeRequiredExec ) : m_name( name ), m_signature( false ), m_gradeRequiredSign( gradeRequiredSign ), m_gradeRequiredExec( gradeRequiredExec )
{
    std::cout << "AForm created" << std::endl;
    if ( gradeRequiredSign > 150 || gradeRequiredExec > 150 )
        throw AForm::GradeTooLowException();
    if ( gradeRequiredSign < 1 || gradeRequiredExec < 1 )
        throw AForm::GradeTooHighException();
}

AForm::AForm( const AForm& f ) : m_name(f.getName()), m_gradeRequiredSign(f.getGradeRequiredSign()), m_gradeRequiredExec(f.getGradeRequiredExec())
{
    *this = f;
}

AForm& AForm::operator=( const AForm& f )
{
    if ( this != &f )
        m_signature = f.getSignature();
    return ( *this );
}

std::string    AForm::getName( void ) const
{
    return ( m_name );
}

bool    AForm::getSignature( void ) const
{
    return ( m_signature );
}

int     AForm::getGradeRequiredSign( void ) const
{
    return ( m_gradeRequiredSign );
}

int     AForm::getGradeRequiredExec( void ) const
{
    return ( m_gradeRequiredExec );
}

void    AForm::beSigned( Bureaucrat& bc )
{
    if ( bc.getGrade() > m_gradeRequiredSign )
    {
        std::cout << bc.getName() << " couldn’t sign " << m_name << " because ";
        throw AForm::GradeTooLowException();
    }
    m_signature = true;
    std::cout << bc.getName() << " signed " << m_name << "." << std::endl;
}

void AForm::execute( Bureaucrat const & executor ) const
{
    if ( m_signature == false )
    {
        std::cout << executor.getName() << " couldn’t execute " << m_name << " because ";
        throw AForm::NotSignedException();
    }
    if ( executor.getGrade() > m_gradeRequiredExec )
    {
        std::cout << executor.getName() << " couldn’t execute " << m_name << " because ";
        throw AForm::GradeTooLowException();
    }
    std::cout << executor.getName() << " executed " << m_name << "." << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm destoyed." << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ( "Grade too high." );
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ( "Grade too low." );
}

const char* AForm::NotSignedException::what() const throw()
{
    return ( "AForm not signed." );
}

std::ostream&   operator<<( std::ostream& o, const AForm& f )
{
    o << f.getName();
    if ( f.getSignature() == 0 )
        o << " is not signed and requires a grade of " << f.getGradeRequiredSign() << " to be signed and " << f.getGradeRequiredExec() << " to be executed.";
    else if ( f.getSignature() == 1)
        o << " is signed and required a grade of " << f.getGradeRequiredSign() << " to be signed and " << f.getGradeRequiredExec() << " to be executed.";
    return ( o );
}