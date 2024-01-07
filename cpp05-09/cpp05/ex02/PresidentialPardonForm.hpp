#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:

    std::string m_target;

    public:

    PresidentialPardonForm( std::string target );
    PresidentialPardonForm( const PresidentialPardonForm& f );
    PresidentialPardonForm& operator=( const PresidentialPardonForm& f );
    void                    execute( Bureaucrat const & executor ) const;
    ~PresidentialPardonForm();
};

#endif