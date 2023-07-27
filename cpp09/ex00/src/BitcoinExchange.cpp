/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:28:18 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/23 12:14:24 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& file) {
	_file_input.open(file.c_str());
	if (!_file_input.is_open()) { throw MyException("Invalid file: " + file, __func__, __FILE__, __LINE__); }
	parseDataBaseToMapObject();
	processInput();
}

void BitcoinExchange::parseDataBaseToMapObject() {
	std::string 	line, date, price;

	_file_database.open("data.csv");
	if (!_file_database.is_open()) { throw MyException("Missing database file", __func__, __FILE__, __LINE__); }

	getline(_file_database, line);
	while(getline(_file_database, line)) {
		std::istringstream tmp(line);

		getline(tmp, date, ','); getline(tmp, price);
	
		_database.insert(std::pair<std::string, double> (date, stringToDouble(price)));
	}
	// displayDataBase();
}

void BitcoinExchange::processInput() {
	std::string line, date, value;
	int	line_nbr = 1;

	getline(_file_input, line);
	if(_file_input.eof()) { throw MyException("Invalid input file, empty file", __func__, __FILE__, __LINE__); }
	if (line != "date | value") { throw MyException("Invalid header", __func__, __FILE__, __LINE__); }

	while(getline(_file_input, line)) {
		line_nbr++;
		std::istringstream tmp(line);
		
		if (!errorCheckLine(line)) {
			std::cerr << ERROR << R << line << RED << "\t<== Invalid characters found, line: " << line_nbr << E;
			line = "";
			continue;
		}

		getline(tmp, date, '|');
		if (!isDateValid(date)) {
			std::cerr << ERROR << R << date << RED << "\t<== Invalid date, line: " << line_nbr << E;
			date = "";
			continue;
		}
	
		getline(tmp, value, '|');
		value = ft_trim_white_space(value);
		size_t isDigitNumber = value.find_first_not_of("0123456789.-\n");
		if (std::string::npos != isDigitNumber || !checkNumberOfPoints(value)) {
			std::cerr << ERROR << R << value << RED << "\t<== Invalid value, line: " << line_nbr << E;
			value = "";
			continue;
		}

		double bitcoin_value = stringToDouble(value);
		if (!isValueValid(bitcoin_value, value, line_nbr))
			continue;

		std::map<std::string, double>::iterator it = _database.begin(); it++;
		if (date < it->first) {
			std::cerr << ERROR << R << RED << "\t<== Not enough data to calculate, line: " << line_nbr << E;
			continue;
		}

		it = _database.find(date);
		if (it == _database.end()) {
			it = _database.lower_bound(date);
			if (it == _database.begin())
				std::cerr << ERROR << R << RED << "\t<== Not enough data to calculate, line: " << line_nbr << E;
			it--;
		}
		std::cout << "\t  " << date << " => " << value << " = " << std::setprecision(10) << (bitcoin_value * it->second) << E;
	}
}


bool BitcoinExchange::isDateValid(std::string& date) {
	date = ft_trim_white_space(date);
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    std::stringstream tmp(date);
    int year, month, day;
    char dash;
    tmp >> year >> dash >> month >> dash >> day;
    if(!tmp.eof() || tmp.fail())
        return false;
    return isMonthValid(month) && isDayValid(year, month, day);
}

bool BitcoinExchange::isValueValid(double value, std::string& Ovalue, int line_nbr) {
	if (Ovalue.find_first_not_of("0123456789.-") != std::string::npos || !checkNumberOfMinus(Ovalue)) {
		std::cerr << ERROR << R << value << RED << "\t<== Invalid characters found, line: " << line_nbr << E;
		return (false);
	} else if (value < 0) {
		std::cerr << ERROR << R << value << RED << "\t<== Value can't be negative, line: " << line_nbr << E;
		return (false);
	} else if (value > 1000) {
		std::cerr << ERROR << R << value << RED << "\t<== Value is over 1000, line: " << line_nbr << E;
		return (false);
	} return (true);
}

void BitcoinExchange::displayDataBase() {
	std::map<std::string, double>::iterator it = _database.begin();
	
	for (int i = 0; i < _database.size(); i++) {
		if (it == _database.end())
			break;
		double tmp = it->second + it->second;
		std::cout << it->first << " | " << std::fixed  << tmp << E;
		it++;
	}
}

BitcoinExchange::BitcoinExchange() : MyException() {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &) : MyException() { }
BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const &) { return *this; }
BitcoinExchange::~BitcoinExchange() {
	_file_input.close();
	_file_database.close();
}
