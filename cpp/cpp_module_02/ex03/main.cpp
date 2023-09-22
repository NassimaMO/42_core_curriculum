#include "Point.hpp"

int main( void )
{
    Point   ptOne( -2, 1 );
    Point   ptTwo( 1, 4 );
    Point   ptThree( 2, -2 );
    Point   point( -2, -2 );

    std::cout << bsp(ptOne, ptTwo, ptThree, point) << std::endl;

    return 0;
}