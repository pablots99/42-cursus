/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:49:42 by pablo             #+#    #+#             */
/*   Updated: 2022/01/18 18:18:13 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef	A_HPP
#define A_HPP

#include <iostream>
#include "Base.hpp"

class A: public Base
{
private:
	/* data */
public:
	A(void);
	A(A &obj);
	A &operator=(A &obj);
	~A();
};
#endif

