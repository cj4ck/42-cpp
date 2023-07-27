/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:56:12 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/22 20:42:57 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Test cases
8 9 * 9 - 9 - 9 - 4 - 1 +
7 7 * 7 -
1 2 * 2 / 2 * 2 4 - +
(1 + 1)
*/

#include "../inc/RPN.hpp"

int main(int ac, char** av) {
	if (ac != 2) {
		std::cerr << ERROR << "Wrong arguments passed" << E;
		std::cout << SYS_MSG << RED << ITALIC << BOLD << "./RPL " << UNDERLINE << "<expression>" << E;
		return (1);
	}
	try {
		std::string input = av[1];
		RPN::calculateRPN(input);
	} catch (const MyException& e) { std::cerr << E << e.what(); }
	return (0);
}
