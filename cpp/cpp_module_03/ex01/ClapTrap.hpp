#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class   ClapTrap
{
    public:

    ClapTrap( void );
    ClapTrap( std::string name );
    ClapTrap( const ClapTrap& cp );
    ClapTrap&   operator=(const ClapTrap& cp);
    ~ClapTrap();

    void    attack( const std::string& target );
    void    takeDamage( unsigned int amount );
    void    beRepaired( unsigned int amount );
    
    void    setName(std::string name);
    void    setHit(int hit);
    void    setEnergy(int energy);
    void    setAttack(int attack);

    protected:

    std::string _name;
    int         _hit;
    int         _energy;
    int         _attack;
};

#endif