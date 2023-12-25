#ifndef WRONGWrongANIMAL_HPP
# define WRONGWrongANIMAL_HPP

#include <string>

class       WrongAnimal
{
    public:

    WrongAnimal( void );
    WrongAnimal( const WrongAnimal& cp );
    WrongAnimal&   operator=( const WrongAnimal& cp );
    ~WrongAnimal();

    std::string getType( void ) const;

    void makeSound( void ) const;

    private:

    protected:

    std::string type;

};

#endif