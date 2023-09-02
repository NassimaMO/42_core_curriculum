#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class   HumanA
{
    public:

    HumanA( std::string name, Weapon &m_weapon );
    ~HumanA( void );
    void    attack( void );

    private:

    Weapon      &m_weapon;
    std::string m_name;
};

#endif