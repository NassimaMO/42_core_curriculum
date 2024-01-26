#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <limits.h>
# include <limits>
# include <cstring>
# include <string>
# include <fstream>
# include <sstream>
# include <cmath>
# include <cstdlib>
class BitcoinExchange
{
    private:

    const std::map<std::string, float>  stock_data( std::ifstream& data );
    float                         getValue( float value, float valueData );
    float                         searchValue( const std::string& date, const std::map<std::string, float> myMap );

    public:

    BitcoinExchange( void );
    BitcoinExchange( const BitcoinExchange& b );
    BitcoinExchange&    operator=( const BitcoinExchange& b );
    virtual             ~BitcoinExchange();

    static int          BitcoinValueTab( std::ifstream& file, std::ifstream& data );
    virtual void        wtv() = 0;
};

#endif