#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap clap("Carol");
    ClapTrap target("Jimmy");

    std::cout << "Jimmy ! You stole my lunch money, fight me !" << std::endl;
    while (target.getEnergy() && target.getEnergy())
    {
        clap.attack("Jimmy");
        target.takeDamage(clap.getAttack());
        target.beRepaired(5);
    }
    clap.attack("Jimmy");
    target.takeDamage(clap.getAttack());
    target.beRepaired(5);
    return 0;
}