#include "BitcoinExchange.hpp"


int main( int argc, char **argv )
{
    if (argc != 2)
        return (std::cout << "Error: could not open file." << std::endl, 1);
    if (argv[1] && strcmp(argv[1] + (strlen(argv[1]) - 4), ".txt"))
        return (std::cout << "Error: file with wrong extension." << std::endl, 1);

    /*
    Value multiplied by the exchange rate according to the date indicated in your database
    Use the lower date if the input does not exist in your DB
    */
    std::ifstream   data( "data.csv" );

    if ( data.is_open() )
    {
        std::ifstream input( argv[1] );
        if ( input.is_open() )
        {
            if ( BitcoinExchange::BitcoinValueTab( input, data ) )
                std::cout << "Error: Invalid format." << std::endl;
            input.close();
        }
        else
            std::cout << "Error: " << argv[1] << ": file does not exist." << std::endl;
        data.close();
    }
    else
        std::cout << "Error: data.csv: could not open file." << std::endl;
    return (0);
}