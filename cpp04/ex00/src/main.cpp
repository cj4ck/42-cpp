/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:34:13 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 14:54:35 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongCat.hpp"

int	main() {
	{
	std::cout << BASE_B << "160m SYS TESTS ANIMAL" << E;
	std::cout << SYS_MSG << "obj: a1  " << E;
	Animal a1;
	std::cout << E << SYS_MSG << "obj: b2  " << E;
	Animal b2(a1);
	std::cout << E << SYS_MSG << "obj: c3  " << E;
	Animal c3;
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
	std::cout << BASE_B << "160m SUBJECT TESTS1" << E;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	}
	{
	std::cout << BASE_B << "160m SUBJECT TESTS2" << E;
	const WrongAnimal* meta = new WrongAnimal();
	const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	}
	return 0;
}
