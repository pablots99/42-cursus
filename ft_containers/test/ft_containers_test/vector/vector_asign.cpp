/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_asign.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:30:45 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/21 17:27:04 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.hpp"

TEST(vector, vector_asign) { 
    std::list<std::string> list;
	for (size_t i = 0; i < 10; i++)
		list.push_back("number: " + std::to_string(i));
	std::vector<std::string> v(list.begin(),list.end());
	ft::vector<std::string> fv(list.begin(),list.end());
    ASSERT_EQ(v.size(),fv.size()) << "sizes are not equal";
    ASSERT_EQ(v.max_size(),fv.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv.capacity(),fv.size()) << "not enougth capacity";
    for (int i = 0; i < v.size(); ++i) {
  		EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;
	}
    v.assign(40,"hola");
    fv.assign(40,"hola");
    ASSERT_EQ(v.size(),fv.size()) << "sizes are not equal";
    ASSERT_EQ(v.max_size(),fv.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv.capacity(),fv.size()) << "not enougth capacity";
    for (int i = 0; i < v.size(); ++i) {
  		EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;
	}
    v.assign(list.begin(),list.end());
    fv.assign(list.begin(),list.end());
    ASSERT_EQ(v.size(),fv.size()) << "sizes are not equal";
    ASSERT_EQ(v.max_size(),fv.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv.capacity(),fv.size()) << "not enougth capacity";
    for (int i = 0; i < v.size(); ++i) {
  		EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;
	}

}
