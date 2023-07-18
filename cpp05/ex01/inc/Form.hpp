/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:38:39 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/18 18:32:52 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Colors.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
  public:
	Form(std::string name, unsigned int gradeRequiedToSign, unsigned int gradeRequiedToExec);
	Form(const Form& src);
	Form& operator=(Form const &src);
	~Form();

	//* Nested Class
	class MyException {
		std::string msg;
		public:
		MyException(const std::string& arg, const char* file, int line) {
			std::ostringstream out;
			out << EX << G "(" << file << ":" << line << ")\n" << RED << "❯ "<< arg << E;
			msg = out.str();
			// throw std::runtime_error(msg.c_str());
		}
		~MyException() {}
		const char* what() const throw() { return msg.c_str(); }
	};

	class GradeTooHighException : public MyException {
		public:
		GradeTooHighException(const char* file, int line) : MyException("invalid grade: grade is too high", file, line) {}
	};

	class GradeTooLowException : public MyException {
		public:
		GradeTooLowException(const char* file, int line) : MyException("invalid grade: grade is too low", file, line) {}
	};

	void			beSigned(const Bureaucrat& bureaucrat);
	std::string		getName() const;
	bool			getSigned() const;
	unsigned int	getGradeRequiedToSign() const;
	unsigned int	getGradeRequiedToExec() const;

  private:
	Form();
	bool				_signed;
	const std::string	_name;
	const unsigned int	_gradeRequiedToSign;
	const unsigned int	_gradeRequiedToExec;

};

std::ostream& operator<<(std::ostream& out, const Form& rs);
