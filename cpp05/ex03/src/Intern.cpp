/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:04:23 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/18 18:36:27 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& src) { (void)src; }
Intern::~Intern() {}
Intern& Intern::operator=(const Intern& src) { (void)src; return *this; }

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm* forms[] = {
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target),
		new ShrubberyCreationForm(target)
	};
	
	std::string form_names[3] = {"RobotomyRequestForm", "PresidentialPardonForm", "ShrubberyCreationForm"};
	
	for (int i = 0; i < 3; i++) {
		if (name == form_names[i]) {
			for (int j = 0; j < 3; j++)
				if (j != i)
					delete forms[j];
			std::cout << INFO << GREEN << "Intern creates " << name << E;
			return forms[i];
		}
	}
	for (int j = 0; j < 3; j++)
		delete forms[j];
	std::cout << ERROR << "Intern cannot find form " << name << E;
	return nullptr;
}
