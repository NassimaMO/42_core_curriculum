#include "Serializer.hpp"
#include <cstdio>
int main( void )
{
    {
        uintptr_t   i = 545665;
        Data*        data;

        std::cout << "uintptr_t value: " << i << std::endl;
        data = Serializer::deserialize( i );
        std::cout << "Deserialized uintptr_t in data: " << Serializer::deserialize( i ) << std::endl;
        std::cout << "Serialized data (need to have the same value as the uintptr_t in the benninging): " << Serializer::serialize( data ) << std::endl;
    }

    {
        std::cout << std::endl;
        uintptr_t   i;
        Data*       data = new Data;

        data->num = 8;
        std::cout << "data int value: " << data <<std::endl;
        i = Serializer::serialize( data );
        std::cout << "Serialized data in i: " << i << std::endl;
        std::cout << "Deserialized i (need to have the same value as the data int in the benninging): " << Serializer::deserialize( i ) << std::endl;

        delete data;
    }
}