#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class   Zombie
{
    public:

    Zombie( std::string name );
    Zombie ( void );
    ~Zombie ( void );
    void announce ( void );

    private:

    std::string m_name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif