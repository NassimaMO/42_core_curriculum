#include "iter.hpp"

int main( void )
{
    char arr[] = "Hello";
    int     tab[] = {1, 2, 3, 4};

    iter(arr, strlen(arr), printT);
    iter(tab, 4, printT);
    return ( 0 );
}