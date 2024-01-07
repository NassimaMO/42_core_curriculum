#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:

    const std::string   m_name;
    bool                m_signature;
    const int           m_gradeRequiredSign;
    const int           m_gradeRequiredExec;

    public:

    Form( std::string name, int gradeRequiredSign, int gradeRequiredExec );
    Form( const Form& f );
    Form&       operator=( const Form& f );
    std::string getName( void ) const ;
    bool        getSignature( void ) const ;
    int         getGradeRequiredSign( void ) const ;
    int         getGradeRequiredExec( void ) const ;
    void        beSigned( Bureaucrat& bc ); 
    void        beExecuted( Bureaucrat& bc );
    ~Form();
    
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

std::ostream&   operator<<( std::ostream& o, const Form& f );

#endif