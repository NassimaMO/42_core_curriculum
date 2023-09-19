#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed c(1);
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "1." << a << std::endl;
    std::cout << "2." << --a << std::endl;
    std::cout << "3." << a-- << std::endl;
    std::cout << "4." << a << std::endl;
    std::cout << "5." << ++a << std::endl;
    std::cout << "6." << a++ << std::endl;
    std::cout << "7." << a << std::endl;

    std::cout << "8." << (c > a) << std::endl;
    std::cout << "9." << (c < a) << std::endl;
    std::cout << "10." << (c >= a) << std::endl;
    std::cout << "11." << (c <= a) << std::endl;
    std::cout << "12." << (c == a) << std::endl;
    std::cout << "13." << (c != a) << std::endl;

    std::cout << "14." << b << std::endl;

    std::cout << "15." << Fixed::max( a, b ) << std::endl;

    return 0;
}