#include "Span.hpp"

Span::Span( int N ) : _N(N)
{
}

Span::Span( const Span &s ) : _N(s._N)
{
    *this = s;
}

Span&   Span::operator=( const Span &s )
{
    if ( this != &s )
    {
        this->_N = s._N;
        this->stock = s.stock;
    }
    return ( *this );
}

const std::list<int>* Span::getList( void ) const
{
    return ( &this->stock );
}

unsigned int    Span::getN( void ) const
{
    return ( _N );
}

void    Span::addNumber( int value )
{
    if ( stock.size() >= this->_N)
        throw Span::SpanFull();
    stock.insert(stock.end(), value);
}

void    Span::rangeIterator( const std::list<int> l )
{
    std::list<int>::const_iterator    start = l.begin();
    std::list<int>::const_iterator    end = l.end();
    if ( distance(start, end) + stock.size() >= _N )
    {
        std::list<int>::const_iterator    tmp = start;
        std::advance(tmp, _N - std::distance( stock.begin(), stock.end() ) );
        stock.insert(stock.end(), start, tmp);
        throw Span::SpanFull();
    }
    stock.insert(stock.end(), start, end);
}

int       Span::shortestSpan( void ) const
{
    std::list<int>::const_iterator   start = stock.begin();
    std::list<int>::const_iterator   next;
    int    tmp = this->longestSpan();

    if ( stock.size() <= 1 )
        throw Span::NotEnoughNumbers();
    if ( tmp == 0 )
        throw Span::NoIntervalFound();
    while ( start != stock.end() )
    {
        next = start;
        next++;
        while ( next != stock.end() )
        {
            if ( abs(*start - *next) && tmp > abs(*start - *next) )
                tmp = abs(*start - *next);
            if ( tmp == 1 )
                break;
            next++;
        }
        start++;
    }
    return ( tmp );
}

int       Span::longestSpan( void ) const
{
    int   tmp;

    if ( stock.size() <= 1 )
        throw Span::NotEnoughNumbers();
    tmp = *std::max_element(stock.begin(), stock.end()) - *std::min_element(stock.begin(), stock.end());
    if ( tmp == 0 )
        throw Span::NoIntervalFound();
    return ( tmp );
}

Span::~Span()
{
}

const char* Span::SpanFull::what() const throw()
{
    return ( "Span already full." );
}

const char* Span::NotEnoughNumbers::what() const throw()
{
    return ( "Not enough numbers." );
}

const char* Span::NoIntervalFound::what() const throw()
{
    return ( "No interval found." );
}

std::ostream& operator<<( std::ostream& o, const Span& s )
{
    std::list<int>::const_iterator tmp = s.getList()->begin();
    if ( s.getList()->size() )
    {
        while ( tmp != s.getList()->end() )
        {
            o << (*tmp) << ' ';
            tmp++;
        }
    }
    return ( o );
}