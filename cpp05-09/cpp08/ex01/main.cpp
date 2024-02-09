#include "Span.hpp"

int main( void )
{
    unsigned int    size = 5;
    {
        //size = 10000
        Span            sp = Span( size );
        std::srand( time ( NULL ) );
        for ( unsigned int i = 0; i < size; i++ )
            sp.addNumber( std::rand() % size );
        std::cout << sp << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        //size = 5
        Span            sp = Span( size );
        std::list<int>  l( 10000 );
        std::srand( time ( NULL ) );
        std::generate( l.begin(), l.end(), std::rand );
        try
        {
            sp.rangeIterator( l.begin(), l.end() );
        }
        catch ( std::exception &e )
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << sp << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    return 0;
}
