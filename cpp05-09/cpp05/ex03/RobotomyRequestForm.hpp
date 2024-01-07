#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include <ctime>
#include <unistd.h>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:

    std::string m_target;

    public:

    RobotomyRequestForm( std::string target );
    RobotomyRequestForm( const RobotomyRequestForm& f );
    RobotomyRequestForm&    operator=( const RobotomyRequestForm& f );
    void                    execute( Bureaucrat const & executor ) const;
    ~RobotomyRequestForm();
};

#endif