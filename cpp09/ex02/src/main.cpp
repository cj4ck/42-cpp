/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:56:12 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/27 17:10:55 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include "../inc/MyException.hpp"
#include <unistd.h>

int main(int ac, char **av)
{
	std::vector<int>myVector;
	std::deque<int>myDeque;

	if (ac <= 2) {
		std::cout << ERROR << "Wrong arguments passed to the program" << E;
		std::cout << SYS_MSG << RED << "./PmergeMe < numeric sequence > < ... >" << E;
		return (1);
	}

	try {
		for (int i = 1; i < ac; i++) {
			populateContainer(myVector, av[i]);
			populateContainer(myDeque, av[i]);
		}
	} catch (...) { std::cout << "Wrong input" << E; exit(1); }
	std::cout << INFO << "Before: " << G;
	printContainer(myVector);
	std::cout << E;

	clock_t start = clock();
	PmergeMe::fordJohnson(myVector, 0, myVector.size() -  1);
	clock_t end = clock();
    double vecTime = double(end - start) / CLOCKS_PER_SEC * 1000000.0;

	start = clock();
	PmergeMe::fordJohnson(myDeque, 0, myDeque.size() -  1);
	end = clock();
    double dequeTime = double(end - start) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << INFO << "After: " << G;
	printContainer(myVector);

	std::cout << E << SYS_MSG << BLUE << "Time to process a range of " << RED << BOLD << myVector.size() << BLUE << " elements with vector: "  << GREEN << vecTime << " us" << E;
	std::cout << SYS_MSG << BLUE << "Time to process a range of " << RED << BOLD << myDeque.size() << BLUE << " elements with deque: " << GREEN << dequeTime << " us" << E;
	return (0);
}
