/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:45:04 by pablo             #+#    #+#             */
/*   Updated: 2021/11/09 21:20:04 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(KAREN_HPP)
#define KAREN_HPP
#include <iostream>
class Karen
{
private:
	void debug();
	void info();
	void warning();
	void error();
public:
	void filter( std::string level );
	Karen();
	~Karen();
};


#endif // KAREN_HPP
