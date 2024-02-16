#include "PmergeMe.hpp"

int main( int argc, char** argv ) {

    if (argc == 1)
        return (std::cout << "Positive integer sequence needed. " << std::endl, 1);
    try
    {
        PmergeMe<std::list<int> > v( argv + 1 );

        std::cout << "Before: ";
        v.printContainer();
        v.sort();

        PmergeMe<std::deque<int> > dq( argv + 1 );
        std::cout << "After: ";
        dq.sort();
        dq.printContainer();

        v.benchmark();
        dq.benchmark();

    }
    catch ( std::exception &e )
    {
        std::cout << e.what() << std::endl;
    }
    return ( 0 );
}