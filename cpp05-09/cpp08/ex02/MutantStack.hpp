#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template< typename T >
class MutantStack : public std::stack< T >
{
    public:

    MutantStack( void ){}
    MutantStack( const MutantStack &m ){ *this = m; }
    MutantStack&    operator=( const MutantStack &m )
    {
        if ( this != *m )
        {
            *this = m;
        }
        return ( &this );
    }
    ~MutantStack(){}
 // Container_Type: This parameter is the type of container for which the iterator is declared.
    typedef typename std::stack< T >::container_type::iterator    iterator;

    iterator begin( void )
    {
        return this->c.begin();
    }

    iterator end( void )
    {
        return this->c.end();
    }
};

#endif