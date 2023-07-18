/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:17:06 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/17 12:03:30 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
//! SYSTEM TESTS
	try
	{
	// std::cout << SYS_MSG << "Constructors:" << E;
	// Bureaucrat a1;
	// Bureaucrat a2("Joe");
	// a2.setGrade(1);
	// std::cout << BLUE << "\ta2 grade: " << a2.getGrade() << E;

	// Bureaucrat a3("Alex", 10);
	// std::cout << BLUE << "\ta3 grade: " << a3.getGrade() << E;
	
	// a1 = a2;
	// std::cout << BLUE << "\ta2 grade: " << a2.getGrade() << E;
	// std::cout << BLUE << "\ta1 grade: " << a1.getGrade() << E;

	//! Exceptions
	Bureaucrat a5("Alex", 151);
	// Bureaucrat a4("Alex", 0);

	//! Incrementation/Decrementation	
	std::cout << SYS_MSG << "Incrementaiton/Decrementation:" << E;
	Bureaucrat b1("Joe", 43);
	std::cout << BLUE << "\tb1 grade before: " << b1.getGrade() << E;
	b1.incrementGrade();
	std::cout << BLUE << "\tb1 grade incremented: " << b1.getGrade() << E;
	Bureaucrat b2("Alex", 149);
	b1.decrementGrade();
	std::cout << BLUE << "\tb2 grade before: " << b2.getGrade() << E;
	std::cout << BLUE << "\tb2 grade decremented: " << b2.getGrade() << E;

	std::cout << SYS_MSG << "More Incrementaiton/Decrementation:" << E;
	Bureaucrat b3("Joe", 150);
	std::cout << BLUE << "\tb3 grade before: " << b3.getGrade() << E;
	for (unsigned int i = MAX_GRADE; i > MIN_GRADE; i--) {
		b3.incrementGrade();
		std::cout << BLUE << "\tb3 grade incremented: " << b3.getGrade() << E;
	}
	Bureaucrat b4("Alex", 1);
	std::cout << BLUE << "\tb4 grade before: " << b4.getGrade() << E;
	for (unsigned int i = MIN_GRADE; i > MAX_GRADE; i--) {
		b4.decrementGrade();
		std::cout << BLUE << "\tb4 grade decremented: " << b4.getGrade() << E;
	}
	
	//! Incrementation/Decrementation Exceptions
	// Bureaucrat b1("Joe", 1);
	// b1.incrementGrade();
	// Bureaucrat b1("Joe", 150);
	// b1.decrementGrade();

	// std::cout << SYS_MSG << "Destructors:" << E;
	}
	catch (std::exception& exception) {
		std::cerr << exception.what();
	}
	return 0;
}
