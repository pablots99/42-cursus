/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_vector_iterator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:57:20 by pablo             #+#    #+#             */
/*   Updated: 2022/02/21 15:15:56 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../test.hpp"


TEST(vector, reverse_empty_iterator) {
	std::vector<std::string> v;
	ft::vector<std::string> fv;
	ft::vector<std::string>::reverse_iterator fvit = fv.rbegin();
	std::vector<std::string>::reverse_iterator fit = v.rbegin();
	ASSERT_EQ(std::distance(fit,v.rend()),std::distance(fvit,fv.rend())) << "vector reverse_iterator ft not equal to std reverse_iterator";
}


TEST(vector, reverse_iterator_operators) {

	std::list<std::string> list;
	for (size_t i = 0; i < 10; i++)
		list.push_back("number: " + std::to_string(i));
	std::vector<std::string> v(list.rbegin(),list.rend());
	ft::vector<std::string> fv(list.rbegin(),list.rend());
	ft::vector<std::string>::reverse_iterator fvit =  fv.rbegin();
	std::vector<std::string>::reverse_iterator vit = v.rbegin();
	while (vit != v.rend()) {
		ASSERT_EQ(*vit,*fvit) << "vector ";
		ASSERT_EQ(*vit == *fvit, true);
		ASSERT_EQ(*vit != *fvit, false);
		vit++;
		fvit++;
	}
	vit--;
	fvit--;
	while (vit != v.rbegin()) {
		ASSERT_EQ(*vit,*fvit) << "vector ";
		ASSERT_EQ(*vit == *fvit, true);
		ASSERT_EQ(*vit != *fvit, false);
		vit--;
		fvit--;
	}
	while (vit != v.rend()) {
		ASSERT_EQ(*vit,*fvit) << "vector ";
		ASSERT_EQ(*vit == *fvit, true);
		ASSERT_EQ(*vit != *fvit, false);
		vit+=1;
		fvit+=1;
	}
	vit--;
	fvit--;
	while (vit != v.rbegin()) {
		ASSERT_EQ(*vit,*fvit) << "vector ";
		ASSERT_EQ(*vit == *fvit, true);
		ASSERT_EQ(*vit != *fvit, false);
		vit-=1;
		fvit-=1;
	}
	ASSERT_EQ(*(vit + 2) == *(fvit + 2), true) << "== ft interator operator not working as std interator operator ";
	ASSERT_EQ(*(vit) != *(fvit + 2), true) << "!= ft interator operator not working as std interator operator ";
	ASSERT_EQ(*(vit) == *(fvit + 2), false)<< "== ft interator operator not working as std interator operator ";
	ASSERT_EQ((vit) < (vit + 2), (fvit) < (fvit + 2))<< "< ft interator operator not working as std interator operator ";
	ASSERT_EQ((vit) > (vit + 2), (fvit) > (fvit + 2))<< "> ft interator operator not working as std interator operator ";
	ASSERT_EQ((vit) <= (vit + 2), (fvit) <= (fvit + 2))<< "<= ft interator operator not working as std interator operator ";
	ASSERT_EQ((vit) >= (vit + 2), (fvit) >= (fvit + 2))<< ">= ft interator operator not working as std interator operator ";
}

