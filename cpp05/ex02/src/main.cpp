/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:17:06 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/17 14:09:17 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat senior("Senior", 10);
		Bureaucrat junior("Junior", 143);
		
		AForm *form1 = new ShrubberyCreationForm("home");
		AForm *form2 = new RobotomyRequestForm("Cat");
		AForm *form3 = new PresidentialPardonForm("Joe");

		std::cout << *form1;
		std::cout << junior;
		junior.signForm(form1);
		std::cout << *form1;
		junior.executeForm(*form1);
		
		std::cout << *form1;
		senior.signForm(form1);
		std::cout << senior;
		std::cout << *form1;
		senior.executeForm(*form1);
		std::cout << *form1;
		
		senior.signForm(form2);
		senior.executeForm(*form2);
		
		std::cout << *form3;
		senior.signForm(form3);
		senior.executeForm(*form3);
		
		std::cout << *form3;
		boss.executeForm(*form3);
		
		delete form1;
		delete form2;
		delete form3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return EXIT_SUCCESS;
}
