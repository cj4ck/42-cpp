/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 21:21:19 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/23 12:11:30 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <string>
#include <algorithm>
#include "../inc/BitcoinExchange.hpp"

double stringToDouble(const std::string& str) {
    double x;
    std::istringstream ss(str);
    if (!(ss >> x)) { throw MyException("Invalid input: cannot convert string to double", __func__, __FILE__, __LINE__); }
    return x;
}

bool checkNumberOfPoints(const std::string& str) {
    return std::count(str.begin(), str.end(), '.') <= 1;
}

bool checkNumberOfMinus(const std::string& str) {
    if (str[0] == '-')
        return std::count(str.begin() + 1, str.end(), '-') == 0;
    else
        return std::count(str.begin(), str.end(), '-') == 0;
}

bool errorCheckLine(const std::string& line) {
	return isMultiChar(line, '|') && isMultiChar(line, ',') && 
			line.find_first_not_of("0123456789-,.| \n") == std::string::npos;
}

bool isMultiChar(const std::string& line, char c) {
	return std::count(line.begin(), line.end(), c) <= 1;
}

std::string ft_trim_white_space(std::string &str) {
	size_t first = str.find_first_not_of(" \t\n\v\f\r");
	if (std::string::npos == first)
		return str;
	size_t last = str.find_last_not_of(" \t\n\v\f\r");
	return str.substr(first, (last - first + 1));
}
