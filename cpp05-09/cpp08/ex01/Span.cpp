#include "Span.hpp"

Span::Span( int N ) : _N(N)
{
}

Span::Span( const Span &s )
{
    this = s;
}

Span&   Span::operator=( const Span &s )
{
    if ( this != &s )
    {
        this->num = s.num;
    }
    return ( *this );
}

void    Span::addNumber( long int value )
{
    if ( num.size() == num.max_size())
        throw Span::SpanFull();
    num.assign(1, value);
}

void    Span::rangeIterator( T start, T end, long int value )
{
    if ( start && end && end <= num.end())
    {
        while ( start != end )
        {
            insert(start, value);
            start++;
        }
    }
}

long int       Span::shortestSpan( void )
{
    T           start = num.begin();
    T           end = num.end();
    int         i_start, i_end = 0;
    long int    tmp = abs(start - end);

    while ( i_start < i_end )
    {
        if ( tmp > abs(start - end) )
            tmp = abs(start - end);
        i_start++;
        i_end--;
    }
}

long int       Span::longestSpan()
{
    long int   tmp;

    if ( num.size() <= 1 )
        throw Span::NotEnoughNumbers();
    tmp = std::max_element(num.begin(), num.end()) - std::min_element(num.begin(), num.end());
    if ( tmp == 0 )
        throw Span::NoIntervalFound();
    return ( tmp );
}

Span::~Span()
{
}