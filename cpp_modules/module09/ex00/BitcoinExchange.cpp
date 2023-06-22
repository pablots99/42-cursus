/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:51:50 by pablo             #+#    #+#             */
/*   Updated: 2023/06/22 15:54:24 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>

BitcoinExchange::BitcoinExchange(char* file): file(std::string(file))
{
  this->_initDB();
  std::cout << "Exange db initialized" << std::endl;
  this->_printResult();
}

void cleanLine(std::string &line) { 
  size_t pos;
  while((pos = line.find(' ')) != std::string::npos)
    line.erase(pos, 1);
}

void BitcoinExchange::_printResult() { 
  std::ifstream file(this->file);
  
  if(!file.is_open()) { 
    std::cout << "Error: could not open file." << std::endl;
    exit(1);
  }
  std::string line, date;
  double value;
  getline(file, line);
  while (getline(file, line)) {
    std::size_t del;
    cleanLine(line);
    del = line.find('|');
    if(del == std::string::npos) { 
      std::cout << "Error: bad input => " << line << std::endl;
      continue;
    }

    date = line.substr(0, del);
    try
    {
      _validateDate(date);
      value = _toDecimal(line.substr(del + 1, line.length()));
      std::cout << "value: " << line.substr(del + 1, line.length()) << std::endl;
    }
    catch(...)
    {
      continue;
    }
    std::cout << date << " => " << value << " = " << _conversion(date,value) << std::endl;
  }
  file.close();
}

double BitcoinExchange::_conversion(std::string date, double ammount) {
  std::map<std::string, double>::iterator lower;
  std::map<std::string, double>::iterator find;

  find = Db.find(date);
  if (find != Db.end())
    return find->second * ammount;

  lower = Db.lower_bound(date);
  if (lower != Db.begin())
    lower--;

  return lower->second * ammount;
}

void BitcoinExchange::_validateDate(std::string date) { 
  int year, month, day;
  bool err  = false;
  if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
    err = true;
  }
  try {
    year = std::stoi(date.substr(0, 4));
    month = std::stoi(date.substr(5, 2));
    day = std::stoi(date.substr(8, 2));
  }
  catch(...) {
    err = true;
  }
  if(day < 1 || day > 31 || month < 1 || month > 12 || year < 0 || year > 9999)
    err = true;
  if ((month == 2 && day > 28))
    err = true;
  if(((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
    err = true;
  if (month > 31)
    err = true;
  if (err) {
    std::exception e;
    std::cout << "Error: bad input => " << date << std::endl;
    throw 1;
  }

}

bool is_valid_number(std::string number) {
  return !number.empty() && number.find_first_not_of("-0123456789") == std::string::npos;
}

double BitcoinExchange::_toDecimal(std::string n) { 
    double result;
    if (!is_valid_number(n)) {
      std::cout << "Error: bad input => " << n << std::endl;
      throw 1;
    }
    try {
      result = std::stof(n);
    } catch (std::invalid_argument const &e) {
      std::cout << "Error: invalid number" << '\n';
      throw 1;
    } catch (std::out_of_range const &e) {
      std::cout << "Error: number is too long" << '\n';
      throw 1;
    }
    if (result < 0) { 
      std::cout << "Error: not a positive number." << '\n';
      throw 1;
    }
    if (result > 1000) {
      std::cout << "Error: too large a number." << std::endl;
      throw 1;
    }
    return result;
}

void BitcoinExchange::_initDB() { 
  std::ifstream file(DB_PATH);
  
  if(!file.is_open()) { 
    std::cout << "Error: db " << DB_PATH << " not found" << std::endl;
    exit(1);
  }

  std::string line, key;
  double value;

  getline(file, line);
  while (getline(file, line)) {
    std::size_t del;
    
    del = line.find(',');
    if(del == std::string::npos) { 
      std::cout << "Error: parsing db: invalid csv" << std::endl;
      exit(1);
    }
    key = line.substr(0, del);
    value = std::stof(line.substr(del + 1,line.length()));
    this->Db[key] = value;
  }
  file.close();
}

BitcoinExchange::BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj)
{
	*this = obj;
	return ;
}

BitcoinExchange &	BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	this->Db = obj.Db;
  this->file = obj.file;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

