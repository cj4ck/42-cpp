/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:21:12 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/22 20:43:03 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& src) : MyException() { (void)src; }
RPN&	RPN::operator=(RPN const &src) { (void)src; return *this; }

RPN::RPN(std::string input) { calculateRPN(input); }

int RPN::calculateRPN(const std::string& input) {
	std::stack<int>	_numbers;
	size_t i = 0;
	while (i < input.length()) {
		char c = input[i];
		if (c == ' ')
			i++;
		else if (isdigit(c)) {
			int num = 0;
			while (i < input.length() && isdigit(input[i])) {
				num = num * 10 + (input[i] - '0');
				i++;
			}
			_numbers.push(num);
		}
		else {
			std::string op(1, c);
			if (!isOperation(op)) { throw MyException("Invalid operator: " + op, __func__, __FILE__, __LINE__); }
			if (_numbers.size() < 2) { throw MyException("Not enough numbers for operation: " + op, __func__, __FILE__, __LINE__); }

			int n2 = _numbers.top(); _numbers.pop();
			int n1 = _numbers.top(); _numbers.pop();

			_numbers.push(calculate(n1, n2, op));
			i++;
		}
	}

	if (_numbers.size() != 1)
		throw MyException("Invalid RPN expression", __func__, __FILE__, __LINE__);
	std::cout << SYS_MSG << GREEN << "Result is: " << _numbers.top() << E;
	return _numbers.top();
}

int RPN::calculate(int a, int b, const std::string& operation) {
    if (operation == "+")
        return a + b;
    if (operation == "-")
        return a - b;
    if (operation == "*")
        return a * b;
    if (operation == "/")
        return a / b;
    throw MyException("Something went wrong during calculations", __func__, __FILE__, __LINE__);
}

bool RPN::isOperation(const std::string& op) {
    return op == "+" || op == "-" || op == "*" || op == "/";
}
