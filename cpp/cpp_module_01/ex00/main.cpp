#include "Zombie.hpp"

int main( void )
{
    Zombie zombieOne( "Bryan" );
    Zombie *zombieTwo;

    zombieOne.announce();
    zombieTwo = newZombie( "Jeff" );
    zombieTwo->announce();
    randomChump( "Alejandro" );
    zombieTwo->~Zombie();
}