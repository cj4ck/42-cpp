/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyExceptions.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:45:36 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/22 21:59:46 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <sstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Colors.hpp"

class MyException {
  public :
	MyException();
	MyException(const std::string& arg, const char* func, const char* file, int line);
	MyException(MyException const &);
	~MyException();
	MyException& operator=(MyException const &);
	const char* what() const throw();
  protected :
	std::string msg;
};

//! Use cases
// throw MyException("invalid grade: grade is too high",__FILE__, __LINE__)
// catch(const std::exception& e) { std::cerr << e.what(); }

// try {
// 	form.execute(*this);
// 	std::cout << INFO << GREEN << _name << " executed " << form.getName() << E;
// } catch (AForm::GradeTooLowException e) {
	
// 	std::cerr << ERROR << _name << " couldn't execute " << form.getName() << " because: \n" << e.what() << E; }
