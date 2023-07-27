/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:36:36 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/23 08:17:15 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main(int ac, char** av) {
	if (ac != 2) {
		std::cerr << ERROR << "Wrong arguments passed" << E;
		std::cout << SYS_MSG << RED << ITALIC << BOLD << "./btc " << UNDERLINE << "<input.txt>" << E;
		return (1);
	}
	try { BitcoinExchange obj(av[1]); } catch (const MyException& e) { std::cerr << e.what(); }
	return (0);
}
