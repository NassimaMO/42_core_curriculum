#include "Form.hpp"

Form::Form( std::string name, int gradeRequiredSign, int gradeRequiredExec ) : m_name( name ), m_signature( false ), m_gradeRequiredSign( gradeRequiredSign ), m_gradeRequiredExec( gradeRequiredExec )
{
    if ( gradeRequiredSign > 150 || gradeRequiredExec > 150 )
        throw Form::GradeTooLowException();
    if ( gradeRequiredSign < 1 || gradeRequiredExec < 1 )
        throw Form::GradeTooHighException();
    std::cout << "Form created" << std::endl;
}

Form::Form( const Form& f ) : m_name(f.getName()), m_gradeRequiredSign(f.getGradeRequiredSign()), m_gradeRequiredExec(f.getGradeRequiredExec())
{
    *this = f;
}

Form& Form::operator=( const Form& f )
{
    if ( this != &f )
        m_signature = f.getSignature();
    return ( *this );
}

std::string    Form::getName( void ) const
{
    return ( m_name );
}

bool    Form::getSignature( void ) const
{
    return ( m_signature );
}

int     Form::getGradeRequiredSign( void ) const
{
    return ( m_gradeRequiredSign );
}

int     Form::getGradeRequiredExec( void ) const
{
    return ( m_gradeRequiredExec );
}

void    Form::beSigned( Bureaucrat& bc )
{
    if ( bc.getGrade() > m_gradeRequiredSign )
    {
        std::cout << bc.getName() << " couldn’t sign " << m_name << " because ";
        throw Form::GradeTooLowException();
    }
    else if ( m_signature == true )
    {
        std::cout << "Form already signed." << std::endl;
        return ;
    }
    m_signature = true;
    std::cout << bc.getName() << " signed " << m_name << "." << std::endl;
}

/*void    Form::beExecuted( Bureaucrat& bc )
{
    if ( m_signature == false )
    {
        std::cout << bc.getName() << " couldn’t execute " << m_name << " because ";
        throw Form::NotSignedException();
    }
    if ( bc.getGrade() > m_gradeRequiredExec )
    {
        std::cout << bc.getName() << " couldn’t execute " << m_name << " because ";
        throw Form::GradeTooLowException();
    }
    std::cout << bc.getName() << " executed " << m_name << "." << std::endl;
}*/

Form::~Form()
{
    std::cout << "Form destoyed." << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ( "Grade too high." );
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ( "Grade too low." );
}

const char* Form::NotSignedException::what() const throw()
{
    return ( "Form not signed." );
}

std::ostream&   operator<<( std::ostream& o, const Form& f )
{
    o << f.getName();
    if ( f.getSignature() == 0 )
        o << " is not signed and requires a grade of " << f.getGradeRequiredSign() << " to be signed and " << f.getGradeRequiredExec() << " to be executed.";
    else if ( f.getSignature() == 1)
        o << " is signed and required a grade of " << f.getGradeRequiredSign() << " to be signed and " << f.getGradeRequiredExec() << " to be executed.";
    return ( o );
}