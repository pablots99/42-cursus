/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:27:36 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/21 18:25:13 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.hpp"

TEST(vector, vector_default_insert)
{
    std::list<std::string> list;
	for (size_t i = 0; i < 10; i++)
		list.push_back("number: " + std::to_string(i));
	std::vector<std::string> v(list.begin(),list.end());
	ft::vector<std::string> fv(list.begin(),list.end());
    ASSERT_EQ(v.size(), fv.size()) << "sizes are not equal";
    ASSERT_EQ(v.max_size(), fv.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv.capacity(), fv.size()) << "not enougth capacity";
    for (int i = 0; i < v.size(); ++i)
    {
        EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;
    }
    ASSERT_EQ(
        *v.insert(v.begin() + 5, "insert"),
        *fv.insert(fv.begin() + 5, "insert"))
        << "Return of insert function is wrong";
    ASSERT_EQ(v.size(), fv.size()) << "sizes are not equal";
    ASSERT_EQ(v.max_size(), fv.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv.capacity(), fv.size()) << "not enougth capacity";
    for (int i = 0; i < v.size(); ++i)
    {
        EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;
    }
}

TEST(vector, vector_fill_insert)
{
    std::list<std::string> list;
	for (size_t i = 0; i < 10; i++)
		list.push_back("number: " + std::to_string(i));
	std::vector<std::string> v(list.begin(),list.end());
	ft::vector<std::string> fv(list.begin(),list.end());
    
    
    v.insert(v.begin() + 5, 5, "insert");
    fv.insert(fv.begin() + 5, 5, "insert");
    ASSERT_EQ(v.size(), fv.size()) << "sizes are not equal";
    ASSERT_EQ(v.max_size(), fv.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv.capacity(), fv.size()) << "not enougth capacity";
    for (int i = 0; i < v.size(); ++i)
    {
        EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;
    }
    
    
    v.insert(v.begin(), 5, "insert2");
    fv.insert(fv.begin(), 5, "insert2");
    ASSERT_EQ(v.size(), fv.size()) << "sizes are not equal";
    ASSERT_EQ(v.max_size(), fv.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv.capacity(), fv.size()) << "not enougth capacity";
    for (int i = 0; i < v.size(); ++i){
        EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;
    }
    
    
    v.insert(v.end(), 5, "insert3");
    fv.insert(fv.end(), 5, "insert3");
    ASSERT_EQ(v.size(), fv.size()) << "sizes are not equal";
    ASSERT_EQ(v.max_size(), fv.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv.capacity(), fv.size()) << "not enougth capacity";
    for (int i = 0; i < v.size(); ++i)
    {
        EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;
    }
}

TEST(vector,vector_range_insert) { 
    std::list<std::string> list;
	for (size_t i = 0; i < 10; i++)
		list.push_back("number: " + std::to_string(i));
	std::vector<std::string> v(list.begin(),list.end());
	ft::vector<std::string> fv(list.begin(),list.end());
    
    
    v.insert(v.begin()+ 5, list.begin(), list.end());
    fv.insert(fv.begin() + 5,list.begin(), list.end());
    ASSERT_EQ(v.size(), fv.size()) << "sizes are not equal";
    ASSERT_EQ(v.max_size(), fv.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv.capacity(), fv.size()) << "not enougth capacity";
    for (int i = 0; i < v.size(); ++i)
        EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;
   
   
   
    v.insert(v.begin(), list.begin(), list.end());
    fv.insert(fv.begin(),list.begin(), list.end());
    ASSERT_EQ(v.size(), fv.size()) << "sizes are not equal";
    ASSERT_EQ(v.max_size(), fv.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv.capacity(), fv.size()) << "not enougth capacity";
    for (int i = 0; i < v.size(); ++i)
        EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;

    v.insert(v.end(), list.begin(), list.end());
    fv.insert(fv.end(),list.begin(), list.end());
    ASSERT_EQ(v.size(), fv.size()) << "sizes are not equal";
    ASSERT_EQ(v.max_size(), fv.max_size()) << "max_sizes are not equal";
    ASSERT_GE(fv.capacity(), fv.size()) << "not enougth capacity";
    for (int i = 0; i < v.size(); ++i)
        EXPECT_EQ(v[i], fv[i]) << "Vectors ft and std differ at index " << i;
}