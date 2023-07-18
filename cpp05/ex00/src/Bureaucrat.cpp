/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:34:33 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/18 18:38:21 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(MIN_GRADE) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name) {
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name) {
	this->_grade = src._grade;
}

Bureaucrat&		Bureaucrat::operator=(Bureaucrat const& src) {
	if (this != &src)
		this->_grade = src._grade;
	return(*this);
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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rs) {
	out << BLUE << rs.getName() << R <<  ", bureaucrat grade " << BLUE << rs.getGrade() << R;
	return out;
}
