#include "Harl.hpp"

Harl::Harl( void )
{
    std::cout << "Harl created." << std::endl;
}
Harl::~Harl( void )
{
    std::cout << "Harl destroyed." << std::endl;
}

void    Harl::complain( std::string level )
{
    switch( level )
    {
        case DEBUG:
            debug();
            break;
        case INFO:
            info();
            break;
        case WARNING:
            warning();
            break;
        case ERROR:
            error();
            break;
        default:
            std::cout << "nothing." << std::endl;
            break;
    }
}

void    Harl::debug( void )
{
    std::cout << "DEBUG: contextual information to establish a diagnostic." << std::endl;
}

void    Harl::info( void )
{
    std::cout << "INFO: detailed information to trace the execution of a program in production." << std::endl;
}

void    Harl::warning( void )
{
    std::cout << "WARNING: potential problem in the system that can be resolved or ignored." << std::endl;
}

void    Harl::error( void )
{
    std::cout << "ERROR: critical error. Manual intervention needed." << std::endl;
}