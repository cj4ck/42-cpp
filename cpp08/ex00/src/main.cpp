/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:36:19 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/22 08:25:13 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "../inc/easyfind.hpp"

int main() {
	std::cout << E << INFO << "Creating a vector of 10 elements\n";
	std::vector<int> tab;
	std::cout << INFO << "Filling the vector with { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }" << E << E;
	for (int i = 0; i < 10; i++)
		tab.push_back(i);

	std::cout << INFO << "Trying to find 8 : " << E;
	try {
		easyfind(tab, 8);
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << E;
	}

	std::cout << INFO << "Trying to find 10 :" << E;
	try
	{ easyfind(tab, 10); }
		catch (std::exception &e) { std::cout << EX << e.what() << E; }
	return 0;
}
