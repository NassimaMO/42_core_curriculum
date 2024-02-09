#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

    /*
    Except for char parameters, only the decimal notation will be used
    To make things simple, please note that non displayable characters shouldn’t be used as inputs.
    If a conversion to char is not displayable, prints an informative message.
    You have to handle these pseudo literals as well (you know, for science and fun): -inff, +inff, nanf, -inf, +inf and nan.
    You have to first detect the type of the literal passed as parameter, convert it from string to its actual type, then convert it explicitly to the three other data types.
    If a conversion does not make any sense or overflows, display a message to inform the user that the type conversion is impossible.
    */
    
class ScalarConverter
{
    public:

    ScalarConverter( void );
    ScalarConverter( const ScalarConverter& sc );
    ScalarConverter&    operator=( const ScalarConverter& sc );
    virtual             ~ScalarConverter();

    /* outputs str to char, int, float or double */ 
    static void         convert( const char * str );
    virtual void        wtv( void ) = 0;
};

#endif