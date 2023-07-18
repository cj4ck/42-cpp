/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:34:13 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 16:46:07 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"
#define N 2
#include <unistd.h>

int	main() {
	{
	std::cout << BASE_B << "160m SYS TESTS BRAIN" << E;
	std::cout << SYS_MSG << "obj: a1  " << E;
	Brain a1;
	std::cout << E << SYS_MSG << "obj: b2  " << E;
	Brain b2(a1);
	std::cout << E << SYS_MSG << "obj: c3  " << E;
	Brain c3;
	c3 = a1;
	std::cout << E << SYS_MSG << "system tests: DESTRUCTORS" << E;
	}
	{
	std::cout << BASE_B << "160m SYS TESTS DOG" << E;
	std::cout << SYS_MSG << "obj: a1  " << E;
	Dog a1;
	std::cout << E << SYS_MSG << "obj: b2  " << E;
	Dog b2(a1);
	std::cout << E << SYS_MSG << "obj: c3  " << E;
	Dog c3;
	c3 = a1;
	std::cout << E << SYS_MSG << "system tests: DESTRUCTORS" << E;
	}
	{
	std::cout << BASE_B << "160m SYS TESTS CAT" << E;
	std::cout << SYS_MSG << "obj: a1  " << E;
	Cat a1;
	std::cout << E << SYS_MSG << "obj: b2  " << E;
	Cat b2(a1);
	std::cout << E << SYS_MSG << "obj: c3  " << E;
	Cat c3;
	c3 = a1;
	std::cout << E << SYS_MSG << "system tests: DESTRUCTORS" << E;
	}
	{
	std::cout << BASE_B << "160m SUBJECT TESTS" << E;
	AbstractAnimal *animals[N];
	
	for(int i = 0; i < N; i++) {
		if (i % 2 == 0)
			animals[i] =  new Cat();
		else
			animals[i] =  new Dog();
	}
	for(int i = 0; i < N; i++) { delete animals[i]; }
	}
	// {
	// std::cout << BASE_B << "160m DEEP COPY TESTS" << E;
	// Cat a;
	// Cat b;
	// a._brain->setIdeas("DEEP COPY", 0);
	
	// b = a;
	// Cat c(a);
	// std::cout << b._brain->getIdeas()[0] << E;
	// std::cout << c._brain->getIdeas()[0] << E;
	// }
	return 0;
}
