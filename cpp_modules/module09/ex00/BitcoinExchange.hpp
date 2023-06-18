/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:51:53 by pablo             #+#    #+#             */
/*   Updated: 2023/06/18 17:30:13 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXANGE_HPP
#define BITCOINEXANGE_HPP
#define DB_PATH "./data.csv"

#include <iostream>
#include <map>
#include <fstream>

class BitcoinExchange
{
private:
  std::string file;
  std::map<std::string,double> Db;
  void _initDB();
  void _printResult();
  void  _validateDate(std::string date);
  double _conversion(std::string date, double ammount);
  double _toDecimal(std::string n);
public:
  BitcoinExchange(char *file);
  ~BitcoinExchange();
};

#endif
