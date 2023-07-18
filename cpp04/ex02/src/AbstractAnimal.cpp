/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:16:05 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 16:44:44 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal()  { std::cout << SYS_MSG_CON << "Def Constructor " << G << "called for class: " << BLUE << "AbstractAnimal" << E; }
AbstractAnimal::~AbstractAnimal() { std::cout << SYS_MSG_DES << "Def Destructor " << G << "called for class: " << BLUE << "AbstractAnimal" << E; }

AbstractAnimal::AbstractAnimal(const AbstractAnimal& src) {
	_type = src.getType();
	std::cout << SYS_MSG_CON << "Copy Constructor " << G << "called for class: " << BLUE << "AbstractAnimal" << E;
}

AbstractAnimal&	AbstractAnimal::operator=(AbstractAnimal const& src) {
	_type = src.getType();
	std::cout << SYS_MSG_CON << "Copy Asigmnet operator overload " << G << "called for class: " << BLUE << "AbstractAnimal" << E;
	return(*this);
}

std::string		AbstractAnimal::getType() const {return(_type); }

// void	AbstractAnimal::makeSound() const { std::cout << "AbstractAnimal sounds ..." << E; }
