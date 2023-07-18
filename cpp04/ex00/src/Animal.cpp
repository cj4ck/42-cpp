/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:16:05 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 14:50:32 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal()  { std::cout << SYS_MSG_CON << "Def Constructor " << G << "called for class: " << BLUE << "Animal" << E; }
Animal::~Animal() { std::cout << SYS_MSG_DES << "Def Destructor " << G << "called for class: " << BLUE << "Animal" << E; }

Animal::Animal(const Animal& src) {
	_type = src.getType();
	std::cout << SYS_MSG_CON << "Copy Constructor " << G << "called for class: " << BLUE << "Animal" << E;
}

Animal&	Animal::operator=(Animal const& src) {
	_type = src.getType();
	std::cout << SYS_MSG_CON << "Copy Asigmnet operator overload " << G << "called for class: " << BLUE << "Animal" << E;
	return(*this);
}

std::string		Animal::getType() const {return(_type); }

void	Animal::makeSound() const { std::cout << "Animal sounds ..." << E; }
