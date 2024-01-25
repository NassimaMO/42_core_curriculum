#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <list>

class   Span
{
    private:

    unsigned int           _N;
    std::list<int> stock;

    public:

    Span( int N );
    Span( const Span &s );
    Span&   operator=( const Span &s );
    const std::list<int>*   getList( void ) const;
    unsigned int            getN( void ) const ;
    void                    addNumber( int value );
    void                    rangeIterator( const std::list<int>::iterator start, const std::list<int>::iterator end );
    int                     shortestSpan( void ) const;
    int                     longestSpan( void ) const;
    ~Span();

    class   SpanFull : public std::exception
    {
        public:

        const char*         what() const throw();
    };

    class   NotEnoughNumbers : public std::exception
    {
        public:

        const char*         what() const throw();
    };

    class   NoIntervalFound : public std::exception
    {
        public:

        const char*         what() const throw();
    };
};

std::ostream&               operator<<( std::ostream& o, const Span& s );


#endif