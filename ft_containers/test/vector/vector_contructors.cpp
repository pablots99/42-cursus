/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_contructors.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:26:50 by pablo             #+#    #+#             */
/*   Updated: 2022/02/18 14:43:52 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.hpp"



TEST(vector,default_constructor)
{
	std::vector<std::string> v;
	ft::vector<std::string> fv;
	ASSERT_EQ(v.size(),fv.size()) << "Vectors ft and std are of unequal length";
	ASSERT_GE(fv.capacity(),v.capacity()) << "Vectors ft and std are of unequal capacity";
	ASSERT_EQ(v.max_size(),fv.max_size()) << "Vectors ft and std are of unequal length";

}

TEST(vector,fill_constructor)
{
	std::vector<std::string> v(12,"hola");
	ft::vector<std::string> fv(12,"hola");
	ASSERT_EQ(v.size(),fv.size()) << "Vectors x and y are of unequal length";
	ASSERT_GE(fv.capacity(),v.capacity()) << "Vectors incorrect capacity";
	ASSERT_EQ(v.max_size(),fv.max_size()) << "Vectors x and y are of unequal length";
	for (int i = 0; i < v.size(); ++i) {
  		EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;
	}
}

TEST(vector,range_constructor)
{
	std::vector<std::string> v(12,"hola");
	ft::vector<std::string> fv(12,"hola");
	ASSERT_EQ(v.size(),fv.size()) << "Vectors x and y are of unequal length";
	ASSERT_GE(fv.capacity(),v.capacity()) << "Vectors incorrect capacity";
	ASSERT_EQ(v.max_size(),fv.max_size()) << "Vectors x and y are of unequal length";
	for (int i = 0; i < v.size(); ++i) {
  		EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;
	}

}



