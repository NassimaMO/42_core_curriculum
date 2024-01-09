#ifndef ITER_HPP
# define ITER_HPP

#include <string>
#include <cstring>
#include <iostream>

template <typename T>
void    iter(T *arr, int len, void (*func)(T) )
{
    for (int i = 0; i < len; i++)
        func(arr[i]);
}

template <typename T>
void    printT(T arr)
{
    std::cout << arr << std::endl;
}

#endif