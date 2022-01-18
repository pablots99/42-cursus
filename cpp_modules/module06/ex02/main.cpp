/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:18:22 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/18 18:29:36 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def/A.hpp"
#include "def/B.hpp"
#include "def/C.hpp"

int main() { 

    Base *gen = generate();
    identify(gen);
    identify(gen);
}