#include "Point.hpp"

int main( void )
{
    Point   ptOne( 8.12739f, 5.604521f );
    Point   ptTwo( 7.1391f,5.2624f );
    Point   ptThree( 7.899343610f, 4.3882662f );
    Point   point( 8.01f, 5 );

    std::cout << bsp(ptOne, ptTwo, ptThree, point) << std::endl;
    return 0;
}