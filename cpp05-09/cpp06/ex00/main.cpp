# include "ScalarConverter.hpp"

int main( int argc, char **argv )
{
    if ( argc != 2 )
        return ( std::cout << "Input error." << std::endl, -1 );
    ScalarConverter::convert( argv[1] );
    return ( 0 );
}