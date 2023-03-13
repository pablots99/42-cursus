/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:06:53 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/23 13:53:53 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.hpp"

std::vector<std::string> v;
ft::vector<std::string> fv;

TEST(vector, vector_empty_true)
{
    ASSERT_EQ(v.empty(),fv.empty());

}

TEST(vector,vector_push_back)
{
    for (size_t i = 0; i < 10; i++){
		v.push_back("number: " + std::to_string(i));
        fv.push_back("number: " + std::to_string(i));
    }
    ASSERT_EQ(v.size(),fv.size()) << "sizes are not equal";
    ASSERT_EQ(v.max_size(),fv.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv.capacity(),fv.size()) << "not enougth capacity";
    for (int i = 0; i < v.size(); ++i) {
  		EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;
	}
}

TEST(vector, vector_empty_false )
{
    ASSERT_EQ(v.empty(),fv.empty());
}


TEST(vector,vector_pop_back)
{
    v.pop_back();
    fv.pop_back();
    ASSERT_EQ(v.size(),fv.size()) << "sizes are not equal";
    ASSERT_EQ(v.max_size(),fv.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv.capacity(),fv.size()) << "not enougth capacity";
    for (int i = 0; i < v.size(); ++i) {
  		EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;
	}
}

TEST(vector,vector_back)
{
      ASSERT_EQ(v.back(),fv.back());
}

TEST(vector,vector_front)
{
    ASSERT_EQ(v.front(),fv.front());
}

TEST(vector,vector_at)
{
    ASSERT_EQ(v.at(0),fv.at(0));
    std::exception e1;
    std::exception e2;
    try
    {
       v.at(100);
    }
    catch(const std::exception& e)
    {
        e1 = e;
    }
    try
    {
       fv.at(100);
    }
    catch(const std::exception& e)
    {
        e2 = e;
    }
    ASSERT_EQ(e1.what(),e2.what());
}

TEST(vector,vector_clear) {
    v.clear();
    fv.clear();
    ASSERT_EQ(v.size(),fv.size()) << "sizes are not equal";
    ASSERT_EQ(v.max_size(),fv.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv.capacity(),fv.size()) << "not enougth capacity";
    for (int i = 0; i < v.size(); ++i) {
  		EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;
	}
}

TEST(vector,vector_erase)
{

    std::list<std::string> list;
	for (size_t i = 0; i < 10; i++)
		list.push_back("number: " + std::to_string(i));
	std::vector<std::string> v1(list.begin(),list.end());
	ft::vector<std::string> fv1(list.begin(),list.end());

    ASSERT_EQ(
         *v1.erase(v1.begin() + 3),
         *fv1.erase(fv1.begin() + 3)
    ) << "erase return value not ok";
    ASSERT_EQ(v1.size(),fv1.size()) << "sizes are not equal";
    ASSERT_EQ(v1.max_size(),fv1.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv1.capacity(),fv1.size()) << "not enougth capacity";
    for (int i = 0; i < v1.size(); ++i) {
  		EXPECT_EQ(v1[i], fv1[i]) << "Vectors ft and std differ at index " << i;
	}
    v1.erase(v1.begin() + 3,v1.end());
    fv1.erase(fv1.begin() + 3,fv1.end());
    ASSERT_EQ(v1.size(),fv1.size()) << "sizes are not equal";
    ASSERT_EQ(v1.max_size(),fv1.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv1.capacity(),fv1.size()) << "not enougth capacity";
    for (int i = 0; i < v1.size(); ++i) {
  		EXPECT_EQ(v1[i], fv1[i]) << "Vectors ft and std differ at index " << i;
	}
    ASSERT_EQ(
         *v1.erase(v1.begin()),
         *fv1.erase(fv1.begin())
    ) << "erase return value not ok";
    ASSERT_EQ(v1.size(),fv1.size()) << "sizes are not equal";
    ASSERT_EQ(v1.max_size(),fv1.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv1.capacity(),fv1.size()) << "not enougth capacity";
    for (int i = 0; i < v1.size(); ++i) {
  		EXPECT_EQ(v1[i], fv1[i]) << "Vectors ft and std differ at index " << i;
	}


}

