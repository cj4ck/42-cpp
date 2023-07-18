/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:17:06 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/18 18:40:12 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main()
{
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat senior("Senior", 10);
		Bureaucrat junior("Junior", 143);
		Intern intern;

		AForm *form1 = intern.makeForm("ShrubberyCreationForm", "home");
		AForm *form2 = intern.makeForm("RobotomyRequestForm", "Cat");
		AForm *form3 = intern.makeForm("PresidentialPardonForm", "Joe");
		AForm *form4 = intern.makeForm("NaN", "Joeee");
		
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
		
		if(form1)
			delete form1;
		if(form2)
			delete form2;
		if(form3)
			delete form3;
		if(form4)
			delete form4;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return EXIT_SUCCESS;
}
