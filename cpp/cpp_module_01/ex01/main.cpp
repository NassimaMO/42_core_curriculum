#include "Zombie.hpp"

int main( void )
{
    Zombie  *zoom;
    int N = 5;

    zoom = zombieHorde( N, "Christian " );
    for ( int i = 0; i < N; i++ )
    {
        std::cout << i << "  " << std::flush;
        zoom[i].announce();
    }
    std::cout << std::endl;
    for ( int i = 0; i < N; i++ )
    {
        std::cout << i << "  " <<  std::flush;
        delete (zoom + i);
    }
}