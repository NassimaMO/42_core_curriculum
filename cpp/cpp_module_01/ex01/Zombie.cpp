# include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
    this->m_name = name;
    std::cout << "Zombie " << this->m_name << " created." << std::endl;
}

Zombie::Zombie( void )
{
    /**/
}

Zombie::~Zombie( void )
{
    std::cout << "Zombie " << this->m_name << " destroyed." << std::endl;
}

void    Zombie::announce( void )
{
    std::cout << this->m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::giveName( std::string name )
{
    this->m_name = name;
}