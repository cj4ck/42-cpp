/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:36:19 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/22 13:11:43 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "../inc/Span.hpp"

int main() {
	std::cout << BLUE << "\n-=[ simple test ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << E;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << SYS_MSG << BLUE << "shortest span: " << sp.shortestSpan() << E;
		std::cout << SYS_MSG << BLUE << "longest span : " << sp.longestSpan() << E;
	} catch(const MyException& e) { std::cerr << E << e.what(); }

	std::cout << BLUE << "\n━━━=[ 10000 elements test ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << E;
	try {
		std::vector<int>vec(10000);
		std::srand(time(NULL));
		std::generate(vec.begin(), vec.end(), std::rand);

		Span span(vec.size());

		span.addNumber(vec.begin(), vec.end());

		std::cout << SYS_MSG << BLUE << "shortest span: " << span.shortestSpan() << E;
		std::cout << SYS_MSG << BLUE << "longest span : " << span.longestSpan() << E;
	} catch(const MyException& e) { std::cerr  << E << e.what(); }

	std::cout << BLUE << "\n━━━=[ 10000 elements test ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << E;
	try {
		unsigned int size = 0;
		std::cout << BLUE << "Enter vector size: ", std::cin >> size;
		std::vector<int>vec(10000);
		std::srand(time(NULL));
		std::generate(vec.begin(), vec.end(), std::rand);

		Span span(vec.size());

		span.addNumber(vec.begin(), vec.end());

		std::cout << SYS_MSG << BLUE << "shortest span: " << span.shortestSpan() << E;
		std::cout << SYS_MSG << BLUE << "longest span : " << span.longestSpan() << E;
	} catch(const MyException& e) { std::cerr  << E << e.what(); }

	std::cout << BLUE << "\n━━━=[ custom elements test ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << E;
	try {
		unsigned int size = 3, val1 = 0, val2 = 0, val3 = 0;
		std::cout << BLUE << "Enter val1: ",  std::cin >> val1;
		std::cout << BLUE << "Enter val2: ",  std::cin >> val2;
		std::cout << BLUE << "Enter val3: ",  std::cin >> val3;
		Span span(size);
		span.addNumber(val1), span.addNumber(val2), span.addNumber(val3);

		std::cout << SYS_MSG << BLUE << "shortest span: " << span.shortestSpan() << E;
		std::cout << SYS_MSG << BLUE << "longest span : " << span.longestSpan() << E;
	} catch(const MyException& e) { std::cerr << e.what(); }

	std::cout << BLUE << "\n━━━=[ exceptions test ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << E;
	try {
		Span sp = Span(-10);
	} catch(const MyException& e) { std::cerr << E << e.what(); }
	try {
		Span sp = Span(1);
		std::cout << SYS_MSG << BLUE << "shortest span: " << sp.shortestSpan() << E;
	} catch(const MyException& e) { std::cerr << E << E << e.what(); }
	try {
		Span sp = Span(1);
		std::cout << SYS_MSG << BLUE << "longest span : " << sp.longestSpan() << E;
	} catch(const MyException& e) { std::cerr << E << E << e.what(); }
	try {
		Span sp = Span(2);
		sp.addNumber(6);
		sp.addNumber(6);
		sp.addNumber(6);
	} catch(const MyException& e) { std::cerr << E << e.what(); }

	return 0;
}
