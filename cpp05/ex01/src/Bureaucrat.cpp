/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:34:33 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/19 15:21:27 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(MIN_GRADE) {
	// std::cout << SYS_MSG_CON << "Def Constructor " << G << "called for class: " << BLUE << "Bureaucrat" << E; 
}
Bureaucrat::~Bureaucrat() {
	// std::cout << SYS_MSG_DES << "Def Destructor " << G << "called for class: " << BLUE << "Bureaucrat" << E; 
}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name) {
	// std::cout << SYS_MSG_CON << "Def Constructor " << G << "called for class: " << BLUE << "Bureaucrat" << E;
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name) {
	// std::cout << SYS_MSG_CON << "Constructor " << G << "called for class: " << BLUE << "Bureaucrat" << E;
	this->_grade = src._grade;
}

Bureaucrat&		Bureaucrat::operator=(Bureaucrat const& src) {
	// std::cout << SYS_MSG_CON << "Copy Asigmnet operator overload " << G << "called for class: " << BLUE << "Bureaucrat" << E;
	if (this != &src)
		this->_grade = src._grade;
	return(*this);
}

void			Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << GREEN << _name << " signed " << form.getName() << "\n";
	}
	catch (Form::GradeTooLowException& e) {
		std::cerr << RED << _name << " couldn't sign " << form.getName() << " because \n" << e.what() << E;
	}
}

void			Bureaucrat::setGrade(unsigned int grade) { 
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException(__FILE__, __LINE__);
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException(__FILE__, __LINE__);
	else
		this->_grade = grade;
}

std::string		Bureaucrat::getName() const { return _name; }
unsigned int	Bureaucrat::getGrade() const { return _grade; }

void			Bureaucrat::incrementGrade() {
	if (_grade <= MAX_GRADE)
		throw Bureaucrat::GradeTooHighException(__FILE__, __LINE__);
	_grade--;
}

void			Bureaucrat::decrementGrade() {
	if (_grade >= MIN_GRADE)
		throw Bureaucrat::GradeTooLowException(__FILE__, __LINE__);
	_grade++;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rs) {
	o << BLUE << rs.getName() << R <<  ", bureaucrat grade " << BLUE << rs.getGrade() << R;
	return o;
}

Bureaucrat::MyException(const std::string& arg, const char* file, int line) {
	std::ostringstream out;
	out << EX << G "(" << file << ":" << line << ")\n" << RED << "❯ "<< arg << E;
	msg = out.str();
}

//! FIX