#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:

    std::string m_target;

    public:

    ShrubberyCreationForm( std::string target );
    ShrubberyCreationForm( const ShrubberyCreationForm& f );
    ShrubberyCreationForm&  operator=( const ShrubberyCreationForm& f );
    void                    execute( Bureaucrat const & executor ) const;
    ~ShrubberyCreationForm();
};

#endif