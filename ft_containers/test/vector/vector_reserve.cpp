/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reserve.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:32:19 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/21 16:36:59 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.hpp"


TEST(vector, vector_reserve) 
{
    std::list<std::string> list;
	for (size_t i = 0; i < 10; i++)
		list.push_back("number: " + std::to_string(i));
	std::vector<std::string> v(list.begin(),list.end());
	ft::vector<std::string> fv(list.begin(),list.end());
    ASSERT_EQ(v.size(),fv.size()) << "sizes are not equal";
    ASSERT_EQ(v.max_size(),fv.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv.capacity(),fv.size()) << "not enougth capacity";
    fv.reserve(8);
    for (int i = 0; i < v.size(); ++i) {
  		EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;
	}
    fv.reserve(15);
    ASSERT_GE(fv.capacity(),15) << "not enougth capacity";
    fv.reserve(20);
    ASSERT_GE(fv.capacity(),20) << "not enougth capacity";
    fv.reserve(3);
    v.reserve(3);
    for (int i = 0; i < v.size(); ++i) {
  		EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;
	}
    ASSERT_EQ(v.size(),fv.size()) << "sizes are not equal";
    ASSERT_EQ(v.max_size(),fv.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv.capacity(),fv.size()) << "not enougth capacity";
}