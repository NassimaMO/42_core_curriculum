#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:

    const std::string   m_name;
    bool                m_signature;
    const int           m_gradeRequiredSign;
    const int           m_gradeRequiredExec;

    public:

    AForm( std::string name, int gradeRequiredSign, int gradeRequiredExec );
    AForm( const AForm& f );
    AForm&          operator=( const AForm& f );
    std::string     getName( void ) const ;
    bool            getSignature( void ) const ;
    int             getGradeRequiredSign( void ) const ;
    int             getGradeRequiredExec( void ) const ;
    void            beSigned( Bureaucrat& bc ); 
    virtual void    execute( Bureaucrat const & executor ) const = 0;
    virtual         ~AForm();
    
    class GradeTooHighException : public std::exception
    {
        public:

            const char* what() const throw();

    };

    class GradeTooLowException : public std::exception
    {
        public:

            const char* what() const throw();

    };

    class NotSignedException : public std::exception
    {
        public:

            const char* what() const throw();
    };
};

std::ostream&   operator<<( std::ostream& o, const AForm& f );

#endif