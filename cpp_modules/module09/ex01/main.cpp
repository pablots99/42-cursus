/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 23:58:34 by pablo             #+#    #+#             */
/*   Updated: 2023/06/19 21:38:17 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char**argv) {
  if (argc != 2) { 
    std::cout << "Error: wrong number of arguments" << std::endl;
    return 1;
  }
  RPN polish(argv[1]);
  return 0;
}
