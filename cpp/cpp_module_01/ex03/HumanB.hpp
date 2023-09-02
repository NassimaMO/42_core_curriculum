#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class   HumanB
{
    public:

    HumanB( std::string name );
    ~HumanB( void );
    void    attack( void );
    void    setWeapon( Weapon  weapon );

    private:

    Weapon      &m_weapon;
    std::string m_name;
};

#endif