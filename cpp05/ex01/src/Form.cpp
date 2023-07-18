/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:52:21 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/17 12:22:10 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form() : _name("Def"), _gradeRequiedToSign(MAX_GRADE), _gradeRequiedToExec(MAX_GRADE) {
	// std::cout << SYS_MSG_CON << "Def Constructor " << G << "called for class: " << BLUE << "Form" << E;
}

Form::Form(std::string name, unsigned int gradeRequiedToSign, unsigned int gradeRequiedToExec) :\
_signed(false), _name(name), _gradeRequiedToSign(gradeRequiedToSign), _gradeRequiedToExec(gradeRequiedToExec) {
	// std::cout << SYS_MSG_CON << "Constructor " << G << "called for class: " << BLUE << "Form" << E;
	if (gradeRequiedToSign < MAX_GRADE || gradeRequiedToExec < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException(__FILE__, __LINE__);
	else if (gradeRequiedToSign > MIN_GRADE || gradeRequiedToExec > MIN_GRADE )
		throw Bureaucrat::GradeTooLowException(__FILE__, __LINE__);
}

Form::Form(const Form& src) : _name(src._name), _gradeRequiedToSign(src._gradeRequiedToSign), _gradeRequiedToExec(src._gradeRequiedToExec) {
	// std::cout << SYS_MSG_CON << "Constructor " << G << "called for class: " << BLUE << "Form" << E;
	this->_signed = src._signed;
}

Form&		Form::operator=(Form const& src) {
	// std::cout << SYS_MSG_CON << "Copy Asigmnet operator overload " << G << "called for class: " << BLUE << "Form" << E;
	if (this != &src)
		this->_signed = src._signed;
	return(*this);
}

Form::~Form() {
	// std::cout << SYS_MSG_DES << "Def Destructor " << G << "called for class: " << BLUE << "Form" << E;
}

void			Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeRequiedToSign)
		throw Form::GradeTooLowException(__FILE__, __LINE__);
	else
		this->_signed = true;
}

bool			Form::getSigned() const { return _signed; }
std::string		Form::getName() const { return _name; }
unsigned int	Form::getGradeRequiedToSign() const { return _gradeRequiedToSign; }
unsigned int	Form::getGradeRequiedToExec() const { return _gradeRequiedToExec; }

std::ostream& operator<<(std::ostream& out, const Form& rs) {
	out << DARKBLUE << rs.getName() << G << " form has grade requied to sign: "
	<< BLUE << rs.getGradeRequiedToSign() << G << " and grade requied to execute: "
	<< BLUE << rs.getGradeRequiedToExec() << G << " Status: " << (rs.getSigned() ? GREEN : RED)
	<< "is " << (rs.getSigned() ? "" : "not ") << "signed";
	return out;
}
