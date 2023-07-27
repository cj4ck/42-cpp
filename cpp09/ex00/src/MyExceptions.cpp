/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyExceptions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:58:56 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/22 18:38:19 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Colors.hpp"
#include "../inc/MyExceptions.hpp"

MyException::MyException(const std::string& arg, const char* func, const char* file, int line) {
	std::ostringstream out;
	out << EX << ITALIC << G "(In " << BASE_T << "202m" << func << "() " << G << UNDERLINE << file << ":" << line << ")\n" << R << RED << "❯ "<< arg << E;
	msg = out.str();
}

MyException::~MyException() {}

const char* MyException::what() const throw() { return msg.c_str(); }

MyException::MyException() {}
MyException::MyException(MyException const &) {}
MyException& MyException::operator=(MyException const &) { return *this; }
