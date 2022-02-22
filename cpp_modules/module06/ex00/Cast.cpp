/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cast.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:50:43 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/18 17:31:11 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cast.hpp"
#include <iomanip>
#include <ctype.h>
#include <sstream>

Cast::Cast(std::string  str):
_arg(str),
_type(0),
_int(0),
_double(0.0f),
_float(0.0f),
_char(0)
{
    this->_type = _detectType();
}

Cast::Cast(Cast const &obj)
{
    *this = obj;

}

Cast & Cast::operator=(Cast const &obj)
{
    this->_arg = obj._arg;
    return *this;
}

std::string Cast::getArg(){
    return this->_arg;
}

int         Cast::getInt()
{
    return this->_int;
}

float       Cast::getFloat()
{
    return this->_float;
}

double     Cast::getDouble()
{
    return this->_double;
}

char        Cast::getChar()
{
    return this->_char;
}

void Cast::printResult()
{
    std::cout << _type << std::endl;
    std::cout << "char    :";
    try
    {
        char aux_char = this->to_char();
        std::cout << aux_char << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "int     :";
    try
    {

        int aux_int = this->to_int();
        std::cout << aux_int << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "float   :";
    try
    {

        float aux_float = this->to_float();
        std::cout << std::fixed << std::setprecision(1)  << aux_float << "f" << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "double  :";
    try
    {

        double aux_double = this->to_double();
        std::cout << std::fixed  << std::setprecision(1) << aux_double << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
 }

 char Cast::to_char()
 {
     if(!_type)
        throw ImposibleCastException();
    if (_type == INT && (_int < 0 || _int > 255))
        throw  ImposibleCastException();
    switch (_type)
    {
    case INT:
       _char =  static_cast<char>(_int);break;
    case FLOAT:
        _char =  static_cast<char>(_float);break;
    case DOUBLE:
         _char =  static_cast<char>(_double);break;
     }
    if(!isprint(_char))
        throw  NonDisplayableException();
    return _char;
}

int Cast::to_int()
{
    if(!_type)
        throw  ImposibleCastException();
    switch (_type)
    {
    case(CHAR):
        _int = static_cast<int >(_char);break;
    case(FLOAT):
        _int = static_cast<int >(_float);break;
    case(DOUBLE):
        _int = static_cast<int >(_double);break;
    }
    return _int;
}

float Cast::to_float()
{
    if(!_type)
        throw  ImposibleCastException();
    switch (_type)
    {
    case(CHAR):
        _float = static_cast<float >(_char);break;
    case(INT):
        _float = static_cast<float >(_int);break;
    case(DOUBLE):
        _float = static_cast<float >(_double);break;
    }
    return _float;
}

double Cast::to_double()
{
    if(!_type)
        throw  ImposibleCastException();
    switch (_type)
    {
    case(CHAR):
        _double = static_cast<double >(_char);break;
    case(FLOAT):
        _double = static_cast<double >(_float);break;
    case(INT):
        _double = static_cast<double >(_int);break;
    }
    return _double;
}


//parse max and min int
bool is_int(std::string str)
{
    int start = 0;
    if(str.length() == 0)
        return false;
    if(str[0] == '-')
        start++;
    std::string aux = &str[start];
    if(aux.find_first_not_of("01234567890") == aux.npos)
        return true;
    return false;
}

bool is_float(std::string str)
{
    int start = 0;
    int start2 = 0;
    if(str.length() == 0)
        return false;
    if(str[0] == '-')
        start++;
    std::string aux = &str[start];
    start = aux.find_first_not_of("0123456789");
    if(aux[start] == '.')
         aux = &str[start + 1];
    else 
        return false;
    start2 = aux.find_first_not_of("0123456789");
    if(start2 == -1 && str.length() - start > 7)
        return false;
    std::cout << "start" <<  start2 << std::endl;
    if(start2 == (int)str.npos ||
        ((start2 + start  + 1) == (int)(str.length() - 1) && str[str.length() - 1] == 'f'))
        return true;
    return false;
}

bool is_double(std::string str)
{
    int start = 0;
    int start2 = 0;
    if(str.length() == 0)
        return false;
    if(str[0] == '-')
        start++;
    std::string aux = &str[start];
    start = aux.find_first_not_of("01234567890");
    if(aux[start] == '.')
        aux = &str[start + 1];
    else 
        return false;
    start2 = aux.find_first_not_of("01234567890");
    if(start2 == (int)str.npos)
        return true;
    return false;
}

int Cast::_detectType()
{
    if(this->_arg.empty())
        return -1;
    if (this->_arg.length() == 1 && isprint(_arg[0]) && !isnumber(_arg[0])) { 
       _char =     static_cast<char >(_arg[0]);
        return CHAR;
    }
    if (is_int(_arg)) { 
        try
        {
            _int = stoi(_arg);
        }
        catch(const std::exception& e)
        {
            return 0;
        }
        return INT;
    }
    if (is_float(_arg)) {
         try
        {
            _float = stof(_arg);
            return FLOAT;
        }
        catch(const std::exception& e)
        {
        }
    }
    if (is_double(_arg)) { 
        try
        {
            _double = stod(_arg);
             return DOUBLE;
        }
        catch(const std::exception& e)
        {
        }
    }
    
    return 0;
}


Cast::~Cast(){
    
}