/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:14:03 by pablo             #+#    #+#             */
/*   Updated: 2021/11/09 21:19:57 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc,char **argv) {
	if (argc < 2 || argc > 2)
	{
		std::cout << "expected 1 arg";
		return (1);
	}
	std::string str = argv[1];
	Karen karen;
	karen.filter(str);

}
