/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:11:02 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/17 13:58:02 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45),  _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src.getName(), src.getGradeRequiedToSign(), src.getGradeRequiedToExec()), _target(src._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
	_target = src._target;
	return *this;
}

void RobotomyRequestForm::action() const {
	std::cout << SYS_MSG << "some drilling noises" << E;
	srand (time(NULL));
	if (rand() % 2 == 0)
		std::cout << SYS_MSG << R << GREEN << _target << " has been robotomized successfully" << E;
	else
		std::cout << SYS_MSG << R << RED << _target << " robotomized failed" << E;
}

std::string RobotomyRequestForm::getTarget() const { return _target; }

RobotomyRequestForm::~RobotomyRequestForm() {}
