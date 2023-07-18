/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 04:07:40 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/06 21:02:04 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "colors.h"

int	main() {
	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << INFO << std::setw(43) << std::left
							   << "The memory address of the string variable: " << R << &str << std::endl;
	std::cout << INFO << std::setw(43) << "The memory address held by stringPTR: "      << R << &stringPTR << std::endl;
	std::cout << INFO << std::setw(43) << "The memory address held by stringPTR: "      << R << &stringREF << std::endl;
	std::cout << INFO << std::setw(43) << "The value of the string variable: "          << R << str << std::endl;
	std::cout << INFO << std::setw(43) << "The value pointed to by stringPTR: "         << R << *stringPTR << std::endl;
	std::cout << INFO << std::setw(43) << "The value pointed to by stringREF: "         << R << stringREF << std::endl;
	return(0);
}
