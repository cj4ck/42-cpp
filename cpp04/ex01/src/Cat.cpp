/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:47:04 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 16:27:02 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : _brain(new Brain()) { std::cout << SYS_MSG_CON << "Def Constructor " << G << "called for class: " << BLUE << "Cat" << E;
	this->_type = "Cat";
}

Cat::~Cat() { std::cout << SYS_MSG_DES << "Def Destructor " << G << "called for class: " << BLUE << "Cat" << E;
	delete _brain;
}

Cat::Cat(const Cat& src) : _brain(new Brain(*(src._brain))) { std::cout << SYS_MSG_CON << "Copy Constructor " << G << "called for class: " << BLUE << "Cat" << E;
	_type = src.getType();
}

Cat&	Cat::operator=(Cat const& src) {
	if (this != &src) { // Check for self-assignment
		delete _brain; // Delete the original Brain object
		_type = src.getType();
		_brain = new Brain(*(src._brain)); // Assign a new Brain object
	}
	std::cout << SYS_MSG_CON << "Copy Asigmnet operator overload " << G << "called for class: " << BLUE << "Cat" << E;
	return(*this);
}

void Cat::makeSound() const { std::cout << "Meow! Meow! 🐈" << E; }
