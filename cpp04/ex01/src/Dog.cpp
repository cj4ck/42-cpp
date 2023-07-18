/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:47:25 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 16:26:50 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog(): _brain(new Brain()) { std::cout << SYS_MSG_CON << "Def Constructor " << G << "called for class: " << BLUE << "Dog" << E;
	this->_type = "Dog";
}

Dog::~Dog() { std::cout << SYS_MSG_DES << "Def Destructor " << G << "called for class: " << BLUE << "Dog" << E;
	delete _brain;
}

Dog::Dog(const Dog& src) : _brain(new Brain(*(src._brain))) { std::cout << SYS_MSG_CON << "Copy Constructor " << G << "called for class: " << BLUE << "Dog" << E;
	_type = src.getType();
}

Dog&	Dog::operator=(Dog const& src) {
	if (this != &src) { // Check for self-assignment
		delete _brain; // Delete the original Brain object
		_type = src.getType();
		_brain = new Brain(*(src._brain)); // Assign a new Brain object
	}
	std::cout << SYS_MSG_CON << "Copy Asigmnet operator overload " << G << "called for class: " << BLUE << "Dog" << E;
	return(*this);
}

void Dog::makeSound() const { std::cout << "Bark! Bark! 🐕" << E; }
