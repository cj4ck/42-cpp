/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:16:05 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 14:08:15 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()  { std::cout << SYS_MSG_CON << "Def Constructor " << G << "called for class: " << BLUE << "WrongAnimal" << E; }
WrongAnimal::~WrongAnimal() { std::cout << SYS_MSG_DES << "Def Destructor " << G << "called for class: " << BLUE << "WrongAnimal" << E; }

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
	(void)src;
	//Don't forget to create a deep copy if there is something to copy
	std::cout << SYS_MSG_CON << "Copy Constructor " << G << "called for class: " << BLUE << "WrongAnimal" << E;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& src) {
	(void)src;
	//Don't forget to create a deep copy if there is something to copy
	std::cout << SYS_MSG_CON << "Copy Asigmnet operator overload" << G << "called for class: " << BLUE << "WrongAnimal" << E;
	return(*this);
}

std::string		WrongAnimal::getType() const {return(_type); }

void	WrongAnimal::makeSound() const { std::cout << "WrongAnimal sounds ..." << E; }
