#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
    {
        Bureaucrat  bc( "James", 50 );
        Form        f( "Important Form", 123, 56 );

        bc.signForm( f );
        std::cout << f << std::endl;
        bc.signForm( f );
    }
    {
        std::cout << std::endl;
        Bureaucrat  bc( "Nily", 80);
        Form        f;

        std::cout << f << std::endl;
        bc.signForm( f );
    }
    {
        std::cout << std::endl;
        try
        {
            Form        f( "Cléo", 0, 15 );
        }
        catch ( std:: exception & e )
        {
            std::cout << e.what() << std::endl;
        }
    }
    return ( 0 );
}