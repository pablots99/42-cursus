/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:45:21 by pablo             #+#    #+#             */
/*   Updated: 2021/12/28 18:17:32 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>



void get_initial_data(std::string *name,std::string *s1,std::string *s2) {
	std::cout << "input filename: ";
	std::getline(std::cin, *name);
	std::cout << "input s1: ";
	std::getline(std::cin, *s1);
	std::cout << "input s2: ";
	std::getline(std::cin, *s2);

}

void read_file(std::string name,std::string *buff){
	std::ifstream file_in(name);
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


int main() {
	std::string s1,s2,name,buff;
	get_initial_data(&name,&s1,&s2);
	read_file(name,&buff);
	buff = replace_str(buff,s1,s2);
	std::ofstream myfile(name.append(".replace"));
	myfile << buff;
	myfile.close();
}
