#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>

template <typename T>
class   Array
{
    private:

    T               *elem;
    unsigned int    len;

    public:

    Array( void )
    {
        std::cout << "Array created." << std::endl;
        this->elem = new T[0];
        this->len = 0;
    }
    
    Array( unsigned int n ) //Creates an array of n elements initialized by default.
    {
        std::cout << "Array created." << std::endl;
        this->elem = new T[n];
        this->len = n;
    }
    //Tip: Try to compile int * a = new int(); then display *a.?????
    
    Array( const Array& a )
    {
        std::cout << "Construction by copy." << std::endl;
        &this = a;
    }

    Array&          operator=( const Array& a )
    {
        if ( this != &a )
        {
            if ( this->elem )
                delete[] this->elem;
            this->elem = new T[a.len];
            for( unsigned int i = 0; i < a.len; i++ )
                this->elem[i] = a.elem[i];
            this->len = a.len;
            std::cout << "Assignment operator called." << std::endl;
        }
        return (*this);
    }

    ~Array()
    {
        if (elem)
            delete[] elem;
    }

    class IndexOutOfBounds : public std::exception
    {
        public:

            const char* what() const throw(){ return ( "Index is out of bounds." ); }

    };

    T&              operator[]( unsigned int n ) const
    {
        if ( n >= len )
            throw Array::IndexOutOfBounds();
        return ( elem[n] );
    }

    unsigned int    size( void ) const
    {
        return ( len );
    }

};

template <typename T>
std::ostream& operator<<( std::ostream& o, const Array<T>& a )
{
    for( unsigned int i = 0; i < a.size(); i++ )
        o << a[i] << " ";
    return o;
}

#endif