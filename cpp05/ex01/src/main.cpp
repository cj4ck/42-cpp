/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:17:06 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/17 12:22:41 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{
	try
	{
		Bureaucrat    a1("Joe", 42);
		// Bureaucrat    a2("Alex", 43);
		Form          f1("Test", 42, 42);
		Form          f2("Test1", 42, 42);

		a1.signForm(f1);
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
		//! Exceptions
		// a2.signForm(f1);
	}
	catch (std::exception& exception) {
		std::cerr << exception.what();
	}
	return EXIT_SUCCESS;
}
