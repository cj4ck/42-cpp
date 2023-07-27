/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:28:24 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/23 12:14:02 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>

#include "../inc/Colors.hpp"
#include "../inc/MyExceptions.hpp"

class BitcoinExchange : public MyException {
  public:
	BitcoinExchange(const std::string & file);
	~BitcoinExchange();

  private:
  	std::ifstream 	_file_input;
	std::ifstream 	_file_database;

	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &);
	BitcoinExchange & operator=(BitcoinExchange const &);

	std::map<std::string, double> _database;
	void parseDataBaseToMapObject();
	void displayDataBase();

	void processInput();
	bool isDateValid(std::string& date);
	bool isValueValid(double value, std::string& Ovalue, int line_nbr);
};


//! DATAE VALID
bool isDayValid(int year, int month, int day);
bool isMonthValid(int month);
bool isLeapYear(int year);

//! HELPERS
std::string ft_trim_white_space(std::string &str); //! I am interested if we are accually trimming them...
std::string intToString(int num);
double stringToDouble(const std::string& str);
bool checkNumberOfPoints(const std::string& str);
bool checkNumberOfMinus(const std::string& str);
bool errorCheckLine(const std::string& line);
bool isMultiChar(const std::string& line, char c);
