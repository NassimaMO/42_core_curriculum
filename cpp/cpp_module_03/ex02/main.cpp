#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
    ScavTrap    sT("Hello");
    FragTrap    fT("Shane");

    sT.attack("Jimmy");    
    fT.attack("Jimmy");
    fT.takeDamage(9);
    fT.beRepaired(5);
    sT.takeDamage(5);
    sT.beRepaired(5);
    sT.takeDamage(5);
    sT.beRepaired(5);
    fT.takeDamage(5);
    fT.beRepaired(5);
    fT.takeDamage(5);
    fT.beRepaired(5);
    fT.takeDamage(5);
    fT.beRepaired(5);
    fT.takeDamage(5);
    fT.beRepaired(5);

    sT.guardGate();
    fT.highFivesGuys();

}