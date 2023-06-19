/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:02:40 by pablo             #+#    #+#             */
/*   Updated: 2023/06/19 21:45:01 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void error() {
  std::cout << "Error" << std::endl;
  exit(1);
}

RPN::RPN(char* input):input(std::string(input)),op("") { 
  _readExpression();
  _reverse();
  std::stack<std::string> copy = expression;
  _calculate();
  if (numbers.size() > 1)
    error();
  std::cout << numbers.top() << std::endl;
}

void RPN::_reverse() {
  std::stack<std::string> temp;
  while (!expression.empty()) {
      temp.push(expression.top());
      expression.pop();
  }
  expression = temp;
}

void RPN::_calculate()
{
  while(!expression.empty()) {
    if (!(expression.top() == "+" || expression.top() == "-" || expression.top() == "*" || expression.top() == "/"))
    {
      try
      {
        numbers.push(std::stof(expression.top()));
        expression.pop();
      }
      catch(...) { 
          error();
      }
    }
    else {
      op = expression.top();
      expression.pop();
      if (numbers.size() < 2)
        error();
      _operations();
    }
  }
}

void RPN::_operations() {
  double res = 0;
  double num1, num2;
  num2 = numbers.top();
  numbers.pop();
  num1 = numbers.top();
  numbers.pop();
  if (op == "+") 
    res = num1 + num2;
  else if (op == "-") 
    res = num1 - num2;
  else if (op == "*")
    res = num1 * num2;
  else if (op == "/") 
    res = num1 / num2;
  expression.push(std::to_string(res));
  while (!numbers.empty())
  {
    expression.push(std::to_string(numbers.top()));
    numbers.pop();
  }
}

void RPN::_readExpression() {
  std::stringstream stream(input);
  std::string word;
   while (stream >> word) {
      expression.push(word);
   }
}

RPN::RPN() { 
  return ;
}

RPN::RPN(RPN const &obj)
{
	*this = obj;
	return ;
}

RPN &RPN::operator=(const RPN &obj)
{
	this->numbers = obj.numbers;
  this->input = obj.input;
  this->expression = obj.expression;
  this->op = obj.op;
	return (*this);
}

RPN::~RPN() { 
  while(!numbers.empty())
    numbers.pop();
  while (!expression.empty())
    numbers.pop();
  return ;
}
