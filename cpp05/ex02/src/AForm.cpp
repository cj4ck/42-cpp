/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:52:21 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/17 13:56:22 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm() : _name("Def"), _gradeRequiedToSign(MAX_GRADE), _gradeRequiedToExec(MAX_GRADE) {
	// std::cout << SYS_MSG_CON << "Def Constructor " << G << "called for class: " << BLUE << "AForm" << E;
}

AForm::AForm(std::string name, unsigned int gradeRequiedToSign, unsigned int gradeRequiedToExec) :\
_signed(false), _name(name), _gradeRequiedToSign(gradeRequiedToSign), _gradeRequiedToExec(gradeRequiedToExec) {
	// std::cout << SYS_MSG_CON << "Constructor " << G << "called for class: " << BLUE << "AForm" << E;
	if (gradeRequiedToSign < MAX_GRADE || gradeRequiedToExec < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException(__FILE__, __LINE__);
	else if (gradeRequiedToSign > MIN_GRADE || gradeRequiedToExec > MIN_GRADE )
		throw Bureaucrat::GradeTooLowException(__FILE__, __LINE__);
}

AForm::AForm(const AForm& src) : _name(src._name), _gradeRequiedToSign(src._gradeRequiedToSign), _gradeRequiedToExec(src._gradeRequiedToExec) {
	// std::cout << SYS_MSG_CON << "Constructor " << G << "called for class: " << BLUE << "AForm" << E;
	this->_signed = src._signed;
}

AForm&		AForm::operator=(AForm const& src) {
	// std::cout << SYS_MSG_CON << "Copy Asigmnet operator overload " << G << "called for class: " << BLUE << "AForm" << E;
	if (this != &src)
		this->_signed = src._signed;
	return(*this);
}

AForm::~AForm() {
	// std::cout << SYS_MSG_DES << "Def Destructor " << G << "called for class: " << BLUE << "AForm" << E;
}

void			AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeRequiedToSign)
		throw AForm::GradeTooLowException(__FILE__, __LINE__);
	else
		this->_signed = true;
}

void			AForm::execute(Bureaucrat const & executor) const	{
	if (!getSigned())
		throw AForm::FormNotSignedException(__FILE__, __LINE__);
	else {
		if (getGradeRequiedToExec() < executor.getGrade())
			throw AForm::GradeTooLowException(__FILE__, __LINE__);
		else
			action();
	}
}

bool			AForm::getSigned() const { return _signed; }
std::string		AForm::getName() const { return _name; }
unsigned int	AForm::getGradeRequiedToSign() const { return _gradeRequiedToSign; }
unsigned int	AForm::getGradeRequiedToExec() const { return _gradeRequiedToExec; }

std::ostream& operator<<(std::ostream& out, const AForm& rs) {
	out << INFO << rs.getName() << G << " form has grade requied to sign: "
	<< BLUE << rs.getGradeRequiedToSign() << G << " and grade requied to execute: "
	<< BLUE << rs.getGradeRequiedToExec() << G << " Status: " << (rs.getSigned() ? GREEN : RED)
	<< "is " << (rs.getSigned() ? "" : "not ") << "signed" << E;
	return out;
}
