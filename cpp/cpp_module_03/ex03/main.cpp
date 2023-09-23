#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
    ScavTrap    sT("Hello");
    FragTrap    fT("Shane");
    DiamondTrap dT("Hilary");

    sT.attack("Jimmy");    
    fT.attack("Jimmy");
    dT.attack("Karl");
    fT.takeDamage(9);
    fT.beRepaired(5);
    dT.takeDamage(5);
    dT.beRepaired(5);
    fT.takeDamage(5);
    fT.beRepaired(5);
    fT.takeDamage(5);
    fT.beRepaired(5);
    fT.takeDamage(5);
    fT.beRepaired(5);
    fT.takeDamage(5);
    fT.beRepaired(5);
    fT.takeDamage(5);
    fT.beRepaired(5);

    dT.whoAmI();
}