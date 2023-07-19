/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:00:24 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/19 19:19:47 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConversion.hpp"


bool ScalarConversion::checkOverflow(const std::string & literal) {
	std::istringstream iss(literal);
	char overflowCharacter = 0;
	int overflowInt = 0;
	// float overflowFloat = 0;
	// double overflowDouble = 0;
	if (!(iss >> overflowInt)) {
		std::cout << "1fail\n";
		if (!(iss >> overflowCharacter)) {
			std::cout << "1fail\n";
			return 1;}
	}
	if (!(iss >> overflowCharacter)) {
		std::cout << "2fail\n";
		if (!(iss >> overflowInt)) {
			std::cout << "2fail\n";
			return 1;}
	}
	return 0;
}

void ScalarConversion::convert(const std::string & literal) {
	std::string pseudoLiterals[6] = { "-inff", "+inff", "-inf", "+inff", "nan", "nanf"};
	std::string	toCharacter = "";
	
	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		toCharacter = literal[0];
		std::cout << std::setw(11) << "character: " << GREEN <<  toCharacter << E;
		std::cout << std::setw(11) << "int: " << GREEN <<  static_cast<int>(toCharacter[0]) << E;
		std::cout << std::setw(11) << "float: " << GREEN <<  static_cast<float>(toCharacter[0]) << ".0f" << E;
		std::cout << std::setw(11) << "double: " << GREEN <<  static_cast<double>(toCharacter[0]) << ".0" << E;
		return;
	}
	
	int 		toInt = std::atoi(literal.c_str());
	long 		ov = std::atol(literal.c_str());
	bool		over_flow = ((ov > INT_MAX || ov < INT_MIN) ? 1 : 0);
	float		toFloat = std::atof(literal.c_str());
	double		toDouble = std::atof(literal.c_str());

	if(literal[literal.length() - 1] == 'f')
		toDouble = static_cast<double>(toFloat);
	else
		toFloat = static_cast<float>(toDouble);

	for (int i = 0; i < 6; i++) {
		if (literal == pseudoLiterals[i]) {
			toCharacter = "imposibble";
			break;
		}
	}
	
	if (toCharacter == "" && toInt >= 32 && toInt <= 126) {
		toCharacter = "'";
		toCharacter += static_cast<char>(toInt);
		toCharacter += "'";
	}
	else if (toCharacter == "")
		toCharacter = "Non displayable";

	if (toCharacter == "imposibble") {
		std::cout << "character: " << RED << toCharacter << E;
		std::cout << std::setw(11) << "int: " << RED << "impossible" << E;
	}
	else {
		std::cout << "character: " << GREEN << toCharacter << E;
		if (!over_flow)
			std::cout << std::setw(11) << "int: " << GREEN << toInt << E;
		else
			std::cout << std::setw(11) << "int: " << RED << "overflow" << E;
	}

	if (toCharacter == "imposibble" && toFloat == 0) {
		std::cout << ERROR << std::setw(11) << "float: " << RED << "impossible" << E;
		std::cout << ERROR << std::setw(11) << "double: " << RED << "impossible" << E;
	} else {
		if (toCharacter != "impossible" && toFloat - static_cast<int>(toFloat) == 0) {
			std::cout << std::setw(11) << "float: " << GREEN << toFloat << ".0f" << E;
			std::cout << std::setw(11) << "double: " << GREEN << toDouble << ".0" << E;
		}
		else {
		std::cout << std::setw(11) << "float: " << GREEN << toFloat << "f" << E;
		std::cout << std::setw(11) << "double: " << GREEN << toDouble << E;
		}
	}
}
