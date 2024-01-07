#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm( "Robotomy Request Form", 72, 45 ), m_target( target )
{
    std::cout << "RobotomyRequestForm created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& f ) : AForm( "Robotomy Request Form", 72, 45 )
{
    *this = f;
}

RobotomyRequestForm&  RobotomyRequestForm::operator=( const RobotomyRequestForm& f )
{
    if ( this != &f )
        m_target = f.m_target;
    return ( *this );
}

void    RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
    if ( getSignature() == false )
        throw AForm::NotSignedException();
    if ( executor.getGrade() > getGradeRequiredExec() )
        throw AForm::GradeTooLowException();
    std::srand(std::time(0));
    if ( std::rand() % 2 == 1 )
    {
        std::cout << "BRRRRRBRRRRRRRRRBRRR........" << std::endl;
        sleep(1);
        std::cout << "BRrrr......brrrr" << std::endl;
        sleep(2);
        std::cout << "brrrrrr...." << std::endl;
        sleep(3);
        std::cout << m_target << " has been robotomized successfuly." << std::endl;
    }
    else
        std::cout << "BRRRRBRRRRBR..BRR..brr....br...b-" << std::endl << m_target << " died. The robotomy failed." << std::endl;

}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destroyed." << std::endl;
}