/* Crée un zombie, lui donne un nom et le retourne afin qu’il puisse être utilisé en
dehors de la portée de la fonction. */

#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie  zoom;
    return (&zoom);
}
