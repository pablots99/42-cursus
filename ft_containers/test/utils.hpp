#include <stdlib.h>
#include <vector>
#include <iostream>
#include "vector.hpp"

#ifndef LIBRARY
    #define LIBRARY std
#endif
#define TYPE std::string

template <typename T>
void print_vec(LIBRARY::vector<T> &v)
{
    typename LIBRARY::vector<T>::iterator it;

    std::cout << "\nVector content: " << std::endl;
    for (it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "---------------" << std::endl;
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capaticy " << v.capacity() << std::endl;
    std::cout << "max_size " << v.max_size() << std::endl;
}
