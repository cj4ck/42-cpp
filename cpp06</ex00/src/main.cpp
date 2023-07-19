/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:51:42 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/19 21:08:16 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConversion.hpp"

int main(int ac, char **av) {
	if (ac == 2) {
		try {
			ScalarConversion::convert(av[1]);
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		return EXIT_SUCCESS;
	}
	std::cout << ERROR << "Wrong parameters" << E;
	std::cout << SYS_MSG << "Usage: ./convert <number>" << E;
	return EXIT_SUCCESS;
}

// std::string buffer(std::string str) {
// 	ScalarConversion::convert(str);
// 	return str;
// }

// int main() {
// 	std::cout << buffer("2147483648") << std::endl;
// 	std::cout << buffer("0") << std::endl;
// 	std::cout << buffer("-inf") << std::endl;
// 	std::cout << buffer("+inf") << std::endl;
// 	std::cout << buffer("-inff") << std::endl;
// 	std::cout << buffer("+inff") << std::endl;
// 	std::cout << buffer("nan") << std::endl;
// 	std::cout << buffer("nanf") << std::endl;
// 	std::cout << buffer("a") << std::endl;
// 	std::cout << buffer("97") << std::endl;
// 	std::cout << buffer("Hello World!") << std::endl;
// 	return EXIT_SUCCESS;
// }
