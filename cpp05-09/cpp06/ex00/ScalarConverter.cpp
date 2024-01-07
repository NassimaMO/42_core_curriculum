#include "ScalarConverter.hpp"
#include <math.h>
#include <climits>

ScalarConverter::ScalarConverter( void )
{
}

ScalarConverter::ScalarConverter( const ScalarConverter& sc )
{
    ( void ) sc;
}

ScalarConverter&    ScalarConverter::operator=( const ScalarConverter& sc )
{
    ( void ) sc;
    return ( *this );
}

ScalarConverter::~ScalarConverter(){}

static bool    isChar( std::string str )
{
    if ( ( str[0] >= '0' && str[0] <= '9' ) || !str.compare( "-inff" ) || !str.compare( "+inff" ) || !str.compare( "nanf" ) || !str.compare( "-inf" ) || !str.compare( "+inf" ) || !str.compare( "nan" ) || ( ( str[0] == '-' || str[0] == '+' ) && str[1] && str[1] >= '0' && str[1] <= '9' )/*|| ( ( str[0] < 'a' || str[0] > 'z' ) && ( str[0] < 'A' || str[0] > 'Z' ) ) */)
        return ( 0 );
    return ( 1 );    
}

static bool    isInt( const char * str )
{
    int i = 0;

    if ( str[i] == '-' || str[i] == '+' )
        i++;
    if ( !str[i] )
        return ( 0 );
    while( str[i] )
    {
        if ( str[i] < '0' || str[i] > '9' )
            return ( 0 );
        i++;
    }
    if ( atol( str ) < INT_MIN || atol( str ) > INT_MAX )
        return ( 0 );
    return ( 1 );
}

static bool    isFloat( std::string str )
{
    int i = 0;
    int p = 0;

    if ( !str.compare( "-inff" ) || !str.compare( "+inff" ) || !str.compare( "nanf" ) )
        return ( 1 );
    if ( str[i] == '-' || str[i] == '+' )
        i++;
    while( str[i] )
    {
        if ( str[i] == '.' )
            p++, i++;
        if ( p == 1 && str[i] && str[i] == 'f' && !str[i + 1] )
            return ( 1 );
        if ( p > 1 || ( str[i] && ( str[i] < '0' || str[i] > '9' ) ) )
            return ( 0 );
        i++;
    }
    return ( 0 );
}
static bool    isDouble( std::string str )
{
    int i = 0;
    int p = 0;

    if ( !str.compare( "-inf" ) || !str.compare( "+inf" ) || !str.compare( "nan" ) )
        return ( 1 );
    if ( str[i] == '-' || str[i] == '+' )
        i++;
    while( str[i] )
    {
        if ( str[i] == '.' )
            p++, i++;
        if ( p == 1 && str[i - 1] && str[i - 1] == '.' && !str[i] )
            return ( 1 );
        if ( p > 1 || ( str[i] && ( str[i] < '0' || str[i] > '9' ) ) )
            return ( 0 );
        i++;
    }
    if ( p )
        return ( 1 );
    return ( 0 );
}

static void    convertChar( char c )
{
    std::cout << "char: " << c << std::endl;
    std::cout << "int: "  << static_cast<int>( c ) << std::endl;
    std::cout << "float: " << static_cast<float>( c ) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>( c ) << ".0" << std::endl;
}

static void    convertInt( int n )
{
    if ( isprint( static_cast<char>( n ) ) )
        std::cout << "char: " << static_cast<char>( n ) << std::endl;
    else if ( n < 0 || n > 255 )
        std::cout << "char: Impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: "  << n << std::endl;
    std::cout << "float: " << static_cast<float>( n ) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>( n ) << ".0" << std::endl;
}

static void    convertFloat( float f )
{
    if ( isprint( static_cast<char>( f ) ) )
        std::cout << "char: " << static_cast<char>( f ) << std::endl;
    else if ( f < 0 || f > 255 || isnan( f ) )
        std::cout << "char: Impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if ( f >= INT_MIN && f <= INT_MAX )
        std::cout << "int: "  << static_cast<int>( f ) << std::endl;
    else
        std::cout << "int: Impossible" << std::endl;
    if ( f - static_cast<int>( f ) == 0 )
    {
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>( f ) << ".0" << std::endl;
    }
    else
    {
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>( f ) << std::endl;
    }
}

static void    convertDouble( double d )
{
    if ( isprint( static_cast<char>( d ) ) )
        std::cout << "char: " << static_cast<char>( d ) << std::endl;
    else if ( d < 0 || d > 255 || isnan( d ) )
        std::cout << "char: Impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if  ( d >= INT_MIN && d <= INT_MAX )
        std::cout << "int: "  << static_cast<int>( d ) << std::endl;
    else
        std::cout << "int: Impossible" << std::endl;
    if ( d - static_cast<int>( d ) == 0 )
    {
        std::cout << "float: " << static_cast<float>( d ) << ".0f" << std::endl;
        std::cout << "double: " << d << ".0" << std::endl;
    }
    else
    {
        std::cout << "float: " << static_cast<float>( d ) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
}

void ScalarConverter::convert( const char * str )
{
    if ( isChar( str ) )
        convertChar( str[0] );
    else if ( isInt( str ) )
        convertInt( atoi( str ) );
    else if ( isFloat( str ) )
        convertFloat( atof( str ) );
    else if ( isDouble( str ) )
        convertDouble( strtod( str, NULL ) );
    else
        std::cout << "The argument passed do not correspond to any type." << std::endl;
}
