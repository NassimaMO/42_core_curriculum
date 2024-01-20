#ifndef SPAN_HPP
# define SPAN_HPP

template <typename T>
class   Span
{
    private:

    T           num[_N];
    const int   _N;

    public:

    Span( int N );
    Span( const Span &s );
    Span&   operator=( const Span &s );
    void    addNumber( long int value );
    void    rangeIterator( T start, T end, long int value );
    T       shortestSpan( void );
    T       longestSpan( void );
    ~Span();

    class   SpanFull : public std::exception
    {
        public:
        const char * what() const throw();
    }

    class   NotEnoughNumbers : public std::exception
    {
        public:
        const char * what() const throw();
    }

    class   NoIntervalFound : public std::exception
    {
        public:
        const char * what() const throw();
    }
}

#endif