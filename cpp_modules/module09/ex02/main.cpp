/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:45:02 by pablo             #+#    #+#             */
/*   Updated: 2023/06/20 19:50:36 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) { 
  if (argc < 1 )
  {
    std::cout << "Error: not enough arguments" << std::endl;
    return 1;
  }
  PmergeMe merge(argv);
  return 0;
}