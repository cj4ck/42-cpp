/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:17:51 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/17 13:40:59 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5),  _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src.getName(), src.getGradeRequiedToSign(), src.getGradeRequiedToExec()), _target(src._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	this->_target = src._target;
	return *this;
}

void		PresidentialPardonForm::action() const {
	std::cout << SYS_MSG << _target << " has been pardoned by Zaphod Beeblebrox." << E;
}

std::string	PresidentialPardonForm::getTarget() const { return _target; }

PresidentialPardonForm::~PresidentialPardonForm() {}
