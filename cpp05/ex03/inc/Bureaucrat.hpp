/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:29:43 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/18 18:39:38 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

#include "Colors.hpp"
#include "AForm.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class AForm;

class Bureaucrat {
  public:
	Bureaucrat(const std::string& name, unsigned int grade);
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat();
	Bureaucrat&	operator=(Bureaucrat const &src);

	void			signForm(AForm* form);
	void			executeForm(AForm const & form) const;

	void			incrementGrade();
	void			decrementGrade();

	void			setGrade(unsigned int grade);
	std::string		getName() const;
	unsigned int	getGrade() const;

	class MyException {
		std::string msg;
	  public:
		MyException(const std::string& arg, const char* file, int line) {
			std::ostringstream out;
			out << EX << G "(" << file << ":" << line << ")\n" << RED << "❯ "<< arg << E;
			msg = out.str();
		}
		~MyException() _NOEXCEPT {}
		const char* what() const _NOEXCEPT { return msg.c_str(); }
	};

	class GradeTooHighException : public MyException, public std::exception {
	  public:
		GradeTooHighException(const char* file, int line) : MyException("invalid grade: grade is too high", file, line) {}
	};

	class GradeTooLowException : public MyException, public std::exception {
	  public:
		GradeTooLowException(const char* file, int line) : MyException("invalid grade: grade is too low", file, line) {}
	};

  private:
	Bureaucrat();
	unsigned int		_grade;
	const std::string	_name;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rs);
