#include "Bureaucrat.hpp"

int main( void )
{
    {
        Bureaucrat bc("James", 150);
        std::cout << bc << std::endl;
        try
        {
            bc.gradeLevelDown();
        }
        catch ( std::exception & e )
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << bc << std::endl;
    }
    {
        std::cout << std::endl;
        Bureaucrat bc("Léa", 1);
        std::cout << bc << std::endl;
        try
        {
            bc.gradeLevelUp();
        }
        catch ( std::exception & e )
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << bc << std::endl;
    }
    {
        std::cout << std::endl;
        try
        {
            Bureaucrat bc("lalala", 152);
            std::cout << bc << std::endl;
        }
        catch ( std::exception & e )
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        try
        {
            Bureaucrat bc("lilili", 0);
            std::cout << bc << std::endl;
        }
        catch ( std::exception & e )
        {
            std::cout << e.what() << std::endl;
        }
    }
}