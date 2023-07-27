/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:56:55 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/22 20:43:02 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stack>
#include "Colors.hpp"
#include "MyException.hpp"

class RPN : public MyException {
  public:
	static int calculateRPN(const std::string& input);
  private:
	RPN();
	~RPN();
	RPN(std::string input);
	RPN(const RPN& src);
	RPN&	operator=(RPN const &src);

	static bool isOperation(const std::string& op);
	static int calculate(int a, int b, const std::string& operation);
};
