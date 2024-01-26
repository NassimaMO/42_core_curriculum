/*• Each line in this file must use the following format: "date | value".
• A valid date will always be in the following format: Year-Month-Day.
• A valid value must be either a float or a positive integer, between 0 and 1000*/
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ){}
BitcoinExchange::BitcoinExchange( const BitcoinExchange& b ){ *this = b; }
BitcoinExchange&    BitcoinExchange::operator=( const BitcoinExchange& b ){ (void)b; return( *this ); }
BitcoinExchange::~BitcoinExchange(){}

float   strtoi( std::string line )
{
    float             num;
    std::stringstream ss(line);
    if (!(ss >> num))
        return (std::numeric_limits<float>::quiet_NaN());
    return (num);
}

const std::map<std::string, float> BitcoinExchange::stock_data( std::ifstream& data )
{
    std::string line;
    std::string date;
    std::map<std::string, float> myMap;

    getline(data, line);
    while ( getline( data, line ) )
        myMap[line.substr( 0, line.find( ',' ) )] = strtoi( line.substr( line.find( ',' ) + 1 ) );
    return ( myMap );

    /*std::string line;
    std::string date;


    
    std::cout << line << std::endl;
    getline(data, line);
    std::cout << line << std::endl;
    while ( getline( data, line ) )
    {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos)
        {
            std::string date = line.substr(0, commaPos);
            try {
                float value = strtoi(line.substr(commaPos + 1));
                // Assuming you want to store the value as a float in the map
                myMap[date] = value;
            } catch (const std::invalid_argument& e) {
                // Handle the exception or log the error
                std::cerr << "Error processing line: " << e.what() << std::endl;
            }
        }
    }*/
}


float BitcoinExchange::getValue( float value, float valueData )
{
    return (value * valueData);
}

float BitcoinExchange::searchValue( const std::string& targetDate, const std::map<std::string, float> myMap )
{
    std::map<std::string, float>::const_iterator it = myMap.lower_bound( targetDate );

    if ( it != myMap.end() && it->first == targetDate )
        return it->second;

    // If the targetDate is not found, find the closest lower date
    if ( it != myMap.begin() )
    {
        --it;
        return it->second;
    }
    else
        return (0.0);
}

std::string    trim( std::string str )
{
    size_t start = 0;
    size_t end = str.length();

    while (start < end && isspace(str[start]))
        start++;
    while (end > start && isspace(str[end - 1]))
        end--;
    return str.substr(start, end - start);
}

int validLine( std::string line )
{
    float   num;
    std::string str;

    str = trim(line.substr(0, line.find('|')));
    if (str.empty())
        return ( 1 );
    size_t i = 0;
    while ( str[i] )
    {
        if (std::isdigit(str[i]))
            break;
        i++;
    }
    if (i == str.length())
        return (1);
    num = strtoi(line.substr(0, line.find('-')));
    if ( num < 0 || static_cast<long int>(num) > INT_MAX)
        return (1);
    line = line.substr(line.find('-') + 1);
    num = strtoi(line.substr(0, line.find('-')));
    if ( line.find('-') >= line.length() || num > 31 || num < 1 )
        return (1);
    line = line.substr(line.find('-') + 1);
    num = strtoi(line.substr(0, line.find('-')));
    if ( num > 31 || num < 1 )
        return (1);
    if ( line.find('|') >= line.length() || strtoi(line.substr(line.find('|') + 1)) != strtoi(line.substr(line.find('|') + 1)))
        return (1);
    i = 0;
    while ( line[i] )
    {
        if (std::isalpha(line[i]))
            return (1);
        i++;
    }
    return (0);
}

int BitcoinExchange::BitcoinValueTab( std::ifstream& file, std::ifstream& data )
{
    std::string line;
    std::string date;
    float         value;
    BitcoinExchange *f = NULL;
    std::map<std::string, float> myMap;

    getline(file, line);
    if ( strcmp( line.c_str(), "date | value" ) )
        return (1);
    myMap = f->stock_data( data );
    while (getline(file, line))
    {
        if (validLine( line )) // need to take care of spaces in case there is no value after the |
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        date = trim(line.substr(0, line.find('|')));
        value = strtoi(line.substr(line.find('|') + 1));
        if (value < 0)
            std::cout << "Error: not a positive number." << std::endl;
        else if (static_cast<long int>(value) > INT_MAX)
            std::cout << "Error: too large a number." << std::endl;
        else
            std::cout << date << " => " << value << " = " << f->getValue(value, f->searchValue(date, myMap)) << std::endl;
    }
    (void)value;
    (void)data;
    return (0);
}
