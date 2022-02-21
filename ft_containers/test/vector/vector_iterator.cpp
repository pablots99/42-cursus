/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:57:20 by pablo             #+#    #+#             */
/*   Updated: 2022/02/21 15:16:44 by ptorres          ###   ########.fr       */
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


TEST(vector, iterator_operators) {

	std::list<std::string> list;
	for (size_t i = 0; i < 10; i++)
		list.push_back("number: " + std::to_string(i));
	std::vector<std::string> v(list.begin(),list.end());
	ft::vector<std::string> fv(list.begin(),list.end());
	ft::vector<std::string>::iterator fvit =  fv.begin();
	std::vector<std::string>::iterator vit = v.begin();
	while (vit != v.end()) {
		ASSERT_EQ(*vit,*fvit) << "vector ";
		ASSERT_EQ(*vit == *fvit, true);
		ASSERT_EQ(*vit != *fvit, false);
		vit++;
		fvit++;
	}
	vit--;
	fvit--;
	while (vit != v.begin()) {
		ASSERT_EQ(*vit,*fvit) << "vector ";
		ASSERT_EQ(*vit == *fvit, true);
		ASSERT_EQ(*vit != *fvit, false);
		vit--;
		fvit--;
	}
	while (vit != v.end()) {
		ASSERT_EQ(*vit,*fvit) << "vector ";
		ASSERT_EQ(*vit == *fvit, true);
		ASSERT_EQ(*vit != *fvit, false);
		vit+=1;
		fvit+=1;
	}
	vit--;
	fvit--;
	while (vit != v.begin()) {
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

