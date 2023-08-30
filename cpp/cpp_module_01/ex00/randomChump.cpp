/* Crée un zombie, lui donne un nom et le fait se présenter. */

#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie  zoom( name );
    zoom.announce();
}