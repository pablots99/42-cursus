/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:45:21 by pablo             #+#    #+#             */
/*   Updated: 2022/01/09 22:04:29 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <stdio.h>

void read_file(std::string name,std::string *buff){
	std::ifstream file_in(name);
	if(!file_in)
	{
		std::cout << "no file wit name: " << name << std::endl;
		return ;
	}
	std::string aux;
	while(getline(file_in,aux))
		buff->append(aux + "\n");
	file_in.close();
}

std::string replace_str(std::string str, std::string s1, std::string s2)
{
	std::string res;

	for (size_t i = 0; i < str.length(); i++)
	{
		int j = 0;
		while(str[i + j] == s1[j] && j < (int)s1.length()) {
			j++;
		}
		if(j == (int)s1.length())
		{
			std::string aux;
			aux.append(str.substr(0,i));
			aux.append(s2);
			aux.append(str.substr(i + j,str.length()));
			str.clear();
			str.append(aux);
		}
		i += j;
	}
	return str;
}


int main(int argc, char **argv) {
	if (argc != 4)
	{
		std::cout << "Arguments error" << std::endl;
		return (1);
	}
	std::string buff;
	std::string name(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	read_file(name,&buff);
	buff = replace_str(buff,s1,s2);
	std::ofstream myfile(name.append(".replace"));
	myfile << buff;
	myfile.close();
	return (0);
}
