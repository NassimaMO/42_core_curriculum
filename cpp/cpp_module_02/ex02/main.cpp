#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.357658f ) - Fixed( 5.25745f ) );
    Fixed c( Fixed( 5.35703f ) * Fixed( 5.2572f ) );
    Fixed const d( Fixed( 5.357342f ) / Fixed( 5.2574896f ) );

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
    std::cout << "16." << Fixed::min( b, d ) << std::endl << std::endl;

    std::cout << "a." << a << ", value: " << a.getRawBits() << std::endl;
    std::cout << "b." << b << ", value: " << b.getRawBits() << std::endl;
    std::cout << "c." << c << ", value: " << c.getRawBits() << std::endl;
    std::cout << "d." << d << ", value: " << d.getRawBits() << std::endl;


    return 0;
}