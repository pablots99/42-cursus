/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:03:47 by pablo             #+#    #+#             */
/*   Updated: 2021/12/20 14:33:41 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


int main(int argc, char **argv )
{
	int i = 1;
	int j;

	while(argv[i] && argc)
	{
		j = 0;
		while(argv[i][j])
		{
			argv[i][j] = toupper(argv[i][j]);
			j++;
		}
		std::cout << argv[i];
		i++;
	}
	if(i == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
