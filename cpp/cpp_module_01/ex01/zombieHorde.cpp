#include "Zombie.hpp"

Zombie  *zombieHorde( int N, std::string name )
{
    Zombie *zoom;
    zoom = new Zombie[N];
    for ( int i = 0; i < N; i++ )
    {
        std::cout << i << " created." << std::endl;
        zoom[i].giveName( name );
    }
    std::cout << std::endl;
    return ( zoom );
}