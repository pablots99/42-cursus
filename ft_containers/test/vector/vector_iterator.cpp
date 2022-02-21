/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:57:20 by pablo             #+#    #+#             */
/*   Updated: 2022/02/18 15:10:22 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../test.hpp"



TEST(vector, empty_iterator) {
	std::vector<std::string> v;
	ft::vector<std::string> fv;
	ft::vector<std::string>::iterator fvit = fv.begin();
	std::vector<std::string>::iterator fit = v.begin();
	ASSERT_EQ(std::distance(fit,v.end()),std::distance(fvit,fv.end())) << "vector iterator ft not equal to std iterator";

}

