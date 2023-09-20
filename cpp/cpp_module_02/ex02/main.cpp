#include "Point.hpp"

int main( void )
{
    Point   pt( 1.01f, 2.5f );
    Point   ptTwo( 3.05f, 6.8232f );
    Point   ptThree( 15.2f, 6 );
    Point   point( 1.5f, 5.4f );

    std::cout << bsp(pt, ptTwo, ptThree, point) << std::endl;
}