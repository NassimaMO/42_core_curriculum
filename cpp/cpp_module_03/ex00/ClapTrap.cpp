#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hit(10), _energy(10), _attack(0)
{
    std::cout << "ClapTrap created." << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hit(10), _energy(10), _attack(0)
{
    std::cout << "ClapTrap " << _name << " created." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& cp )
{
    *this = cp;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& cp)
{
    this->setName(cp._name);
    this->setHit(cp._hit);
    this->setEnergy(cp._energy);
    this->setAttack(cp._attack);
    return ( *this );
}

void    ClapTrap::attack( const std::string& target )
{
    if (_energy && _hit)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl; //how can you know the damage
        _energy--;
    }
    else if (!_energy)
        std::cout << " ClapTrap " << _name << " has no energy points left." << std::endl;
}
void    ClapTrap::takeDamage( unsigned int amount )
{
    if (_hit)
    {
        std::cout << "ClapTrap " << _name << " received " << amount << " damage points." << std::endl;
        _hit -= amount;
    }
    else
        std::cout << "IT'S DEAD ALREADY !! STOP IT U PSYCHOPATH" << std::endl;
}

void    ClapTrap::beRepaired( unsigned int amount )
{
    if (_energy && _hit)
    {
        std::cout << "ClapTrap " << _name << " repaired itself. It recovered " << amount << " hit points." << std::endl;
        _hit += amount;
        _energy--;
    }
    else if (!_energy)
        std::cout << " ClapTrap " << _name << " has no energy points left." << std::endl;
}