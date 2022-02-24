/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cast.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:48:01 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/24 18:35:33 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAST_HPP
#define  CAST_HPP
#define CHAR    1
#define INT     2
#define FLOAT   3
#define DOUBLE  4

#include <iostream>

class Cast { 

 class NonDisplayableException: public std::exception {
        const char * what () const throw()
	    {
		return "Non displayable";
	    }
    };
    class ImposibleCastException : public std::exception {
        const char * what () const throw()
	    {
	        return "Imposible cast";
	    }
    };
    private:
        std::string  _arg;
        int         _type;
        int         _int;
        double      _double;
        float       _float;
        char        _char;
        int        _detectType();
    public:
        Cast(std::string  str);
        Cast(Cast const &obj);
        Cast        &operator=(Cast const &obj);
        std::string getArg();
        ~Cast();
        int         to_int();
        float       to_float();
        double      to_double();
        char        to_char();
       
        void        printResult();
        int         getInt();
        float       getFloat();
        double      getDouble();
        char        getChar();
        void        cast();
};

#endif