/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:00:49 by pablo             #+#    #+#             */
/*   Updated: 2023/06/22 16:13:31 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#include <sstream>
#include <set>

class RPN
{
private:
  std::stack<std::string> expression;
  std::stack<double> numbers;
  std::string input;
  std::string op;
  bool initial_size;
  void _readExpression();
  void _calculate();
  void _operations();
  void _print();
  void _reverse();

public:
  RPN();
  RPN(char* input);
  RPN(RPN const &src);
  RPN &operator=(const RPN &obj);
  ~RPN();
};
#endif
