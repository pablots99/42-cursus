#include <stdlib.h>
#include <vector>
#include <map>
#include <iostream>
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include <stack>
#include "../utils.hpp"

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

template <typename T1, typename T2>
void print_map(LIBRARY::map<T1, T2> &m)
{
    typename LIBRARY::map<T1,T2>::iterator it;

    std::cout << "\nVector content: " << std::endl;
    for (it = m.begin(); it != m.end(); ++it)
    {
        std::cout << it->first << ":" << it->second << std::endl;
    }
    std::cout << "---------------" << std::endl;
    std::cout << "size: " << m.size() << std::endl;
    // std::cout << "capaticy " << m.capacity() << std::endl;
    std::cout << "max_size " << m.max_size() << std::endl;
}
