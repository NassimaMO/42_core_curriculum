#include "Array.hpp"

int main( void )
{
    {
        Array< int > a;
        Array < int > arr(2);
        try
        {
            arr[0] = 1;
            arr[1] = 2;
            arr[2] = 3;
        }
        catch( std::exception &e )
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "arr: " << arr << std::endl; 
        a = arr;
        std::cout << "a: " << a << std::endl;
        a[0] = 5;
        std::cout << "a changed." << std::endl;
        std::cout << "a: " << a << std::endl;
        std::cout << "arr: " << arr << std::endl; 
        return (0);
    }
}