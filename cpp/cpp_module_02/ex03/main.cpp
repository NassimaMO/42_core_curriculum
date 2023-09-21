#include "Point.hpp"

int main( void )
{
    Point   ptOne( 10, 10 );
    Point   ptTwo( 10, 10 );
    Point   ptThree( 10, 10 );
    Point   point( 1, 2 );

    std::cout << bsp(ptOne, ptTwo, ptThree, point) << std::endl;

    return 0;
}