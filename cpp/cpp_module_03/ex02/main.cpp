#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
    ClapTrap    clap("Carol");
    ClapTrap    target("Jimmy");
    ScavTrap    another("Karl");
    FragTrap    bystander("Bob");

    std::cout << std:: endl << "Carol: Jimmy ! You stole my lunch money, fight me !" << std::endl << std:: endl;
    while (target.getEnergy() && target.getEnergy() && target.getHit() && target.getHit())
    {
        clap.attack("Jimmy");
        target.takeDamage(clap.getAttack());
        target.beRepaired(5);
    }
    target.takeDamage(clap.getAttack());
    target.beRepaired(5);
    std::cout << std:: endl << "Karl: What is happening here ??" << std:: endl << std:: endl;

    while (another.getEnergy() && clap.getHit())
    {
        another.attack("Carol");
        clap.takeDamage(another.getAttack());
    }

    another.guardGate();

    std::cout << std::endl << "Bob: Be cool maannn... Don't fight guyyyys...another" << std:: endl << std:: endl;

    bystander.highFivesGuys();

    return 0;
}