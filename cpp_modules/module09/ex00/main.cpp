/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:46:33 by pablo             #+#    #+#             */
/*   Updated: 2023/06/22 15:57:46 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
  if (argc != 2) { 
    std::cout << "Error: arguments are incorrect" << std::endl;
    return 1;
  }

  BitcoinExchange exange(argv[1]);
  
  return 0;
}
