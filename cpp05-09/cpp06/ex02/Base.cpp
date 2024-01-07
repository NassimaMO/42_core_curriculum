#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

Base::~Base(){}

Base*   generate(void)
{
    std::srand( time( 0 ) );
    switch ( rand() % 3 )
    {
        case 0:
            std::cout << "A created" << std::endl;
            return ( new A );
        case 1:
            std::cout << "B created" << std::endl;
            return ( new B );
        default:
            std::cout << "C created" << std::endl;
            return ( new C );
    }
}

void    identify(Base* p)
{
    std::cout << "Pointer indentifier used" << std::endl;
    if ( dynamic_cast< A* >( p ) )
        std::cout << "A identified" << std::endl;
    if ( dynamic_cast< B* >( p ) )
        std::cout << "B identified" << std::endl;
    if ( dynamic_cast< C* >( p ) )
        std::cout << "C identified" << std::endl;
}

void    identify(Base& p)
{
    std::cout << "Reference indentifier used" << std::endl;
    try
    {
        A&  a = dynamic_cast< A& >( p );
        ( void ) a;
        std::cout << "A identified" << std::endl;
    }
    catch ( std::exception & e ) {}
    try
    {
        B&  b = dynamic_cast< B& >( p );
        ( void ) b;
        std::cout << "B identified" << std::endl;
    }
    catch ( std::exception & e ) {}
    try
    {
        C&  c = dynamic_cast< C& >( p );
        ( void ) c;
        std::cout << "C identified" << std::endl;
    }
    catch ( std::exception & e ) {}
}