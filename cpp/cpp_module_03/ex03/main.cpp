#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
    ClapTrap    clap( "Carol" );
    ClapTrap    target( "Jimmy" );
    ScavTrap    another( "Karl" );
    FragTrap    bystander( "Bob" );
    DiamondTrap finalBoss( "TheBoss" );

    std::cout << std:: endl << "Carol: Jimmy ! You stole my lunch money, fight me !" << std::endl << std:: endl;
    while ( target.getEnergy() && target.getEnergy() && target.getHit() && target.getHit() )
    {
        clap.attack( "Jimmy" );
        target.takeDamage( clap.getAttack() );
        target.beRepaired( 5 );
    }
    target.takeDamage( clap.getAttack() );
    target.beRepaired( 5 );
    std::cout << std::endl << "Karl: What is happening here ??" << std::endl << std::endl;

    while ( another.getEnergy() && clap.getHit() )
    {
        another.attack( "Carol" );
        clap.takeDamage( another.getAttack() );
    }

    another.guardGate();

    std::cout << std::endl << "Bob: Be cool maannn... Don't fight guyyyys..." << std::endl << std::endl;

    bystander.highFivesGuys();

    std::cout << std::endl << "TheBoss: NO." << std::endl << std::endl;

    while ( another.getHit() && bystander.getHit() && finalBoss.getEnergy() )
    {
        finalBoss.attack( "Karl" );
        another.takeDamage( finalBoss.getAttack() );
        finalBoss.attack( "Bob" );
        bystander.takeDamage( finalBoss.getAttack() );
    }

    return 0;
}