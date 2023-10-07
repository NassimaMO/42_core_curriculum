#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hit(10), _energy(10), _attack(0)
{
    std::cout << "Default ClapTrap created." << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hit(10), _energy(10), _attack(0)
{
    std::cout << "ClapTrap created." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& cp )
{
    *this = cp;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destroyed." << std::endl;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& cp)
{
    _name = cp._name;
    _hit = cp._hit;
    _energy = cp._energy;
    _attack = cp._attack;
    return ( *this );
}

void    ClapTrap::attack( const std::string& target )
{
    if (_energy && _hit)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
        _energy--;
    }
    else if (!_energy)
        std::cout << "ClapTrap " << _name << " has no energy points left." << std::endl;
}
void    ClapTrap::takeDamage( unsigned int amount )
{
    if (_hit)
    {
        std::cout << "ClapTrap " << _name << " received " << amount << " damage points." << std::endl;
        if ((unsigned int)_hit > amount)
            _hit -= amount;
        else
            _hit = 0;
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
        std::cout << "ClapTrap " << _name << " has no energy points left." << std::endl;
}

int    ClapTrap::getHit( void )
{
    return ( _hit );
}

int    ClapTrap::getEnergy( void )
{
    return ( _energy );
}

int    ClapTrap::getAttack( void )
{
    return ( _attack );
}