/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:47:25 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 14:49:57 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog()  { std::cout << SYS_MSG_CON << "Def Constructor " << G << "called for class: " << BLUE << "Dog" << E;
	this->_type = "Dog";
}

Dog::~Dog() { std::cout << SYS_MSG_DES << "Def Destructor " << G << "called for class: " << BLUE << "Dog" << E;
	this->_type = "Dog";
}

Dog::Dog(const Dog& src) {
	_type = src.getType();
	std::cout << SYS_MSG_CON << "Copy Constructor " << G << "called for class: " << BLUE << "Dog" << E;
}

Dog&	Dog::operator=(Dog const& src) {
	_type = src.getType();
	std::cout << SYS_MSG_CON << "Copy Asigmnet operator overload " << G << "called for class: " << BLUE << "Dog" << E;
	return(*this);
}

void Dog::makeSound() const { std::cout << "Bark! Bark! 🐕" << E; }
