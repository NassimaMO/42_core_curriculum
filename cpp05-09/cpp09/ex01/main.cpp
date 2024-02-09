#include "RPN.hpp"

int main( int argc, char **argv )
{
    if ( argc != 2 )
        return ( std::cout << "Argument error." << std::endl, 1 );
    RPN r;
    try
    {
        r.calculate( argv[1] );
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    } 
}