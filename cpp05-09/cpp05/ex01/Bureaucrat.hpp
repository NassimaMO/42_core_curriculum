#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:

    const std::string   m_name;
    int                 m_grade;

    public:

    Bureaucrat( std::string name, int grade );
    Bureaucrat( const Bureaucrat& bc );
    Bureaucrat& operator=( const Bureaucrat& bc );
    void        gradeLevelUp( void );
    void        gradeLevelDown( void );
    std::string getName( void ) const;
    int         getGrade( void ) const;
    ~Bureaucrat();
    
    void        signForm( Form& f );

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
};

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& bc );

#endif